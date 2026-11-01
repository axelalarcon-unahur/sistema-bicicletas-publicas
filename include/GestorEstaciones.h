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
    Estacion** listarEstaciones();
    void agregarPrevio(Estacion* estacion, Estacion* previo, Estacion** previos);
    Estacion* buscarPrevio(Estacion* estacion, Estacion** previos);
    ListaEstaciones* caminoEncontrado(Estacion* origen, Estacion* destino, Estacion** previos);

public:
    GestorEstaciones(int cantidadInicial);
    ~GestorEstaciones();
    Estacion* buscarEstacion(string codigo);
    int getCantidadEstaciones();
    void agregarEstacion(Estacion* estacion);
    void eliminarEstacion(string codigo);
    Estacion** estacionesOrdenadasPorCapacidad();
    Estacion** estacionesOrdenadasPorDisponibilidad();
    ListaEstaciones* estacionesConOcupacionBaja();
    ListaEstaciones* caminoMasCorto(string origen, string destino);
};
#endif