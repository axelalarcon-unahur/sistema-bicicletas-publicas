#include <iostream>
#include "ListaEstaciones.h"

ListaEstaciones::ListaEstaciones() {
    primero = nullptr;
    largo = 0;
}

// usado para la creación de soluciones en backtracking
ListaEstaciones::ListaEstaciones(ListaEstaciones& lista) {
    NodoEstacion* aux = lista.primero;
    NodoEstacion* actual = nullptr;
    
    primero = nullptr;
    largo = lista.largo;

    while (aux != nullptr) {
        NodoEstacion* temp = new NodoEstacion(aux->dato);

        if (primero == nullptr) {
            primero = temp;
            actual = temp;
        }
        else {
            actual->siguiente = temp;
            actual = temp;
        }

        aux = aux->siguiente;
    }
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

void ListaEstaciones::quitarEstacion(Estacion* estacion) {
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

void ListaEstaciones::mostrar() {
    cout << "[";
    if (primero != nullptr) {
        NodoEstacion* actual = primero;
        cout << primero->dato->getCodigo();

        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
            cout << ", " << actual->dato->getCodigo();
        }
    }
    cout << "]" << endl;
}

void ListaEstaciones::mostrarCamino() {
    if (primero == nullptr) {
        cout << endl;
        return;
    }

    NodoEstacion* actual = primero;
    cout << primero->dato->getCodigo();

    while (actual->siguiente != nullptr) {
        actual = actual->siguiente;
        cout << "-> " << actual->dato->getCodigo();
    }

    cout << endl;
}