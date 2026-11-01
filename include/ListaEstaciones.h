#ifndef LISTA_ESTACIONES_H
#define LISTA_ESTACIONES_H
#include "NodoEstacion.h"

class ListaEstaciones {
private:
    NodoEstacion* primero;
    int largo;

public:
    ListaEstaciones();
    ~ListaEstaciones();
    void agregarEstacion(Estacion* estacion);
    void eliminarEstacion(Estacion* estacion);
    Estacion* getEstacion(int pos);
    int getLargo();
};

#endif
