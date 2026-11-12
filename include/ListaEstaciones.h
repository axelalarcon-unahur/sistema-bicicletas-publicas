#ifndef LISTA_ESTACIONES_H
#define LISTA_ESTACIONES_H
#include "NodoEstacion.h"

class ListaEstaciones {
private:
    NodoEstacion* primero;
    int largo;

public:
    ListaEstaciones();
    ListaEstaciones(ListaEstaciones& lista);
    ~ListaEstaciones();
    void agregarEstacion(Estacion* estacion);
    void quitarEstacion(Estacion* estacion);
    Estacion* getEstacion(int pos);
    int getLargo();
    void mostrar();
    void mostrarCamino();
};

#endif
