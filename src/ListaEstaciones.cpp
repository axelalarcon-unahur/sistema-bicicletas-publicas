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

int ListaEstaciones::getLargo() {
    return largo;
}