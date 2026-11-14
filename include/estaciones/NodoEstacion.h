#ifndef NODO_ESTACION_H
#define NODO_ESTACION_H
#include "estaciones/Estacion.h"

struct NodoEstacion{
    Estacion* dato;
    NodoEstacion* siguiente;

    NodoEstacion(Estacion* dato) {
        this->dato = dato;
        this->siguiente = nullptr;
    }
};

#endif