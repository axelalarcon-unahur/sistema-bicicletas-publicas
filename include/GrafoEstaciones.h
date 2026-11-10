#ifndef GRAFO_ESTACIONES_H
#define GRAFO_ESTACIONES_H
#include "ListaEstaciones.h"
#include "Estacion.h"

using namespace std;

class GrafoEstaciones {
private:
    ListaEstaciones* caminoEncontrado(Estacion* destino, int cantidadEstaciones);
    void limpiarEstaciones(Estacion** estaciones, int cantidadEstaciones);

public:
    ListaEstaciones* caminoMasCorto(Estacion* origen, Estacion* destino, Estacion** estaciones, int cantidadEstaciones);
};
#endif