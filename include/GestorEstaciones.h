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

    Estacion** codigosAEstaciones(string* codigos, int n);
    
public:
    GestorEstaciones(int cantidadInicial);
    ~GestorEstaciones();
    void mostrarInformacion(string codigo);
    void agregarEstacion(Estacion* estacion);
    void eliminarEstacion(string codigo);
    void estacionesOrdenadasPorCapacidad();
    void estacionesOrdenadasPorDisponibilidad();
    void estacionesConOcupacionBaja();
    void caminoMasCorto(string origen, string destino);
    void agregarCiclovia(string a, string b);
    void mostrarRestribucionBicicletas(string* codigos, int cantidadEstaciones, int capacidadCamion);
    void totalColisiones();
    void factorDeCarga();
};
#endif