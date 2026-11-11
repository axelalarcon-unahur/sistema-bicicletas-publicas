#ifndef TABLA_HASH_H
#define TABLA_HASH_H
#include "ListaEstaciones.h"
#include "Estacion.h"

using namespace std;

class TablaHash {
private:
    const double MAX_FACTOR_CARGA = 0.9;
    Estacion** estaciones; // array de punteros a estaciones
    int cantidadEstaciones; // estaciones almacenadas
    int capacidad; // tamaño de hash table
    Estacion* tombstone; // marca para el borrado
    int totalColisiones;

    int funcionHash(string codigo);
    bool hayEstacion(int posicion);
    void cambiarCapacidad(int nuevaCapacidad);
    void verificarCambioCapacidad();
    
public:
    TablaHash(int cantidadInicial);
    ~TablaHash();
    Estacion* buscarEstacion(string codigo);
    void agregarEstacion(Estacion* estacion);
    void eliminarEstacion(string codigo);
    Estacion** listarEstaciones();
    Estacion** estacionesOrdenadasPorCapacidad();
    Estacion** estacionesOrdenadasPorDisponibilidad();
    ListaEstaciones* estacionesConOcupacionBaja();
    int getCantidadEstaciones();
    double getFactorCarga();
    int getTotalColisiones();
};
#endif