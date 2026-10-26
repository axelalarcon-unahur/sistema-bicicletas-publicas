// implemento la operaciones sobre la lista de viajes
/*
------ NECESITAMOS LO SIGUIENTE ----------
    1. Contar los viajes que salieron de una estación dentro de un rango de fechas.
    2. Buscar los viajes de un usuario por DNI y calcular el total de minutos pedaleados.
    3. Listar las bicicletas que superen una cantidad de kilómetros indicada por el usuario.
*/
#include "ListaViajes.h"

/*
    como inicialiamos el contructor osea pide que el viaje
    tenga todos los atributos, lo que tenemos que hacer 
    es inicializar dato directamente en el contructor del nodo
*/
NodoViaje::NodoViaje(Viaje viaje) : dato(viaje) {
    siguiente = nullptr;
}
/*
    ¿Como funciona :dato(viaje)?
        - Inicializa el atributo dato utilizando el objeto
        que recibimos por parametro, asi no se contruye un viaje vacio.
*/
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
        actual->dato.getFecha() == fechaInicio 
        && actual->dato.getFecha() == fechaFin){
            cantViajes++;
        }
        actual = actual->siguiente; 
    }
    return cantViajes;
}
// 2) Buscar todos los viajes de un usuario dado su DNI y mostrar el total de minutos pedaleados
int ListaViajes::calcularMinutosPorUsuario(string dniUser){
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
