#include "ListaEstaciones.h"

ListaEstaciones::ListaEstaciones() {
    primero = nullptr;
    largo = 0;
}

ListaEstaciones::~ListaEstaciones() {
    NodoEstacion* actual = primero;

    while (actual != nullptr) {
        NodoEstacion* aux = actual;
        actual = actual->siguiente;
        delete aux; //nota: no elimina la estación
    }
}

void ListaEstaciones::agregarEstacion(Estacion* estacion) {
    NodoEstacion* nuevo = new NodoEstacion(estacion);

    if (primero == nullptr) {
        primero = nuevo;
    }
    else {
        NodoEstacion* actual = primero;

        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }

        actual->siguiente = nuevo;
    }
    largo++;
}

void ListaEstaciones::eliminarEstacion(Estacion* estacion) {
    if (primero == nullptr) {
        return;
    }

    NodoEstacion* actual = primero;
    NodoEstacion* previo = nullptr;
    
    while (actual != nullptr && actual->dato != estacion) {
        previo = actual;
        actual = actual->siguiente;
    }
    
    if (actual != nullptr) {
        if (actual == primero) {
            primero = actual->siguiente;
        }
        else {
            previo->siguiente = actual->siguiente;
        }
        delete actual;
        largo--;
    }
}

Estacion* ListaEstaciones::getEstacion(int pos) {
    NodoEstacion* actual = primero;
    int i = 0;

    while (actual != nullptr && i < pos) {
        actual = actual->siguiente;
        i++;
    }

    return actual->dato;
}

int ListaEstaciones::getLargo() {
    return largo;
}