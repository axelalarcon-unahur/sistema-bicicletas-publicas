#ifndef LISTA_ESTACIONES_H
#define LISTA_ESTACIONES_H
#include "Estacion.h"

struct NodoEstacion{
    Estacion* dato;
    NodoEstacion* siguiente;

    NodoEstacion(Estacion* dato) {
        this->dato = dato;
        this->siguiente = nullptr;
    }
};

class ListaEstaciones {
private:
    NodoEstacion* primero;
    int largo;

public:
    ListaEstaciones();
    ~ListaEstaciones();
    void agregarEstacion(Estacion* estacion);
    int getLargo();
};

#endif
