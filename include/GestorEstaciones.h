#ifndef GESTOR_ESTACIONES_H
#define GESTOR_ESTACIONES_H
#include <string>
#include "ListaEstaciones.h"
#include "Estacion.h"

using namespace std;

class GestorEstaciones {
private:
    Estacion** estaciones; // array de punteros a estaciones
    int cantidadEstaciones; // estaciones almacenadas
    int capacidad; // tamaño de hash table
    Estacion* tombstone; // marca

    int funcionHash(string codigo);
    bool hayEstacion(int posicion);
    
public:
    GestorEstaciones(int cantidadInicial);
    ~GestorEstaciones();
    void agregarEstacion(Estacion* estacion);
    Estacion* buscarEstacion(string codigo);
    void eliminarEstacion(string codigo);
};
#endif