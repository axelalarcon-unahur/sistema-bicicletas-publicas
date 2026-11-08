#include "ListaViajes.h"
#include <iostream>
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
int ListaViajes::minutosPedaleadosPorUsuarioSegunViajes(int dniUsuario){
    int cantMinutos = 0;
    NodoViaje* nodoActual = primero;
    while(nodoActual!= nullptr){
        if(nodoActual->dato.getDniUsuario() == dniUsuario){
            cantMinutos = cantMinutos + nodoActual->dato.getDuracionMin();
        }
        nodoActual = nodoActual->siguiente;
    }
    return cantMinutos;
}