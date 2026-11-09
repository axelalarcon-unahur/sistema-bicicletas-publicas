#ifndef GESTOR_ESTACIONES_H
#define GESTOR_ESTACIONES_H
#include "Estacion.h"
#include "TablaHash.h"
#include "GrafoEstaciones.h"

using namespace std;

class GestorEstaciones {
private:
    TablaHash* tablaHash;
    GrafoEstaciones* grafo;
    
public:
    GestorEstaciones(int cantidadInicial);
    ~GestorEstaciones();
    void mostrarInformacion(string codigo);
    int getCantidadEstaciones();
    void agregarEstacion(Estacion* estacion);
    void eliminarEstacion(string codigo);
    void estacionesOrdenadasPorCapacidad();
    void estacionesOrdenadasPorDisponibilidad();
    void estacionesConOcupacionBaja();
    void caminoMasCorto(string origen, string destino);
};
#endif