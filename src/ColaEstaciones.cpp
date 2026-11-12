#include <iostream>
#include "ColaEstaciones.h"
using namespace std;

ColaEstaciones::ColaEstaciones() {
    primero = nullptr;
    ultimo = nullptr;
}

ColaEstaciones::~ColaEstaciones() {
    while (primero != nullptr) {
        NodoEstacion* aux = primero;
        primero = primero->siguiente;
        delete aux;
    }

    ultimo = nullptr;
}

void ColaEstaciones::encolar(Estacion* estacion) {
    NodoEstacion* nuevo = new NodoEstacion(estacion);

    if (primero == nullptr) {
        primero = nuevo;
        ultimo = nuevo;
    }
    else {
        ultimo->siguiente = nuevo;
        ultimo = nuevo;
    }
}

Estacion* ColaEstaciones::desencolar(){
    if(estaVacia()) {
       return nullptr;
    }

    NodoEstacion* aux = primero;
    Estacion* estacion = aux->dato;
    primero = primero->siguiente;

    if (primero == nullptr) {
        ultimo = nullptr;
    }

    delete aux;
    return estacion;
}

bool ColaEstaciones::estaVacia(){
    return primero == nullptr;
}
