#include "ListaViajes.h"

NodoViaje::NodoViaje(Viaje viaje) : dato(viaje) {
    siguiente = nullptr;
}
ListaViajes::ListaViajes() {
    primero = nullptr;
}
ListaViajes::~ListaViajes() {
    NodoViaje* actual = primero;
    while (actual != nullptr) {
        NodoViaje* aux = actual;
        actual = actual->siguiente;
        delete aux;
    }
}
void ListaViajes::agregarViaje(Viaje viaje) {
    NodoViaje* nuevo = new NodoViaje(viaje); 
    if (primero == nullptr) {
        primero = nuevo;
    } else {
        NodoViaje* actual = primero; 
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
}
// 1) Calcular la cantidad de viajes que salieron de una estación dentro de un rango de fechas.
int ListaViajes::cantViajesPorEstacion(string codigoEstacion,int fechaInicio, int fechaFin){
    int cantViajes = 0; 
    NodoViaje* actual = primero; 
    while(actual != nullptr){
        if(actual->dato.getEstacionDeOrigen() == codigoEstacion && 
        actual->dato.getFecha() >= fechaInicio  && actual->dato.getFecha() <= fechaFin){
            cantViajes++;
        }
        actual = actual->siguiente; 
    }
    return cantViajes;
}
// 2) Buscar todos los viajes de un usuario dado su DNI y mostrar el total de minutos pedaleados
int ListaViajes::calcularMinutosPorUsuario(int dniUser){
    int totalDeMinutos = 0;
    NodoViaje* actual = primero;
    while(actual!=nullptr){
        if(actual->dato.getDniUsuario()==dniUser){
            totalDeMinutos = totalDeMinutos + actual->dato.getDuracionMin();
        }
        actual = actual->siguiente;
    }
    return totalDeMinutos;
}
// buscar todos los viajes de un usuario a partir de su DNI
ListaViajes ListaViajes::viajesHechosPorUnUserConDni(int dni){
    NodoViaje* actual = primero;
    ListaViajes nuevaLista;
    while(actual!= nullptr){
        if(actual->dato.getDniUsuario()== dni){
            nuevaLista.agregarViaje(actual->dato);
    }
    actual = actual->siguiente;
 }
    return nuevaLista;
}