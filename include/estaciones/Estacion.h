#ifndef ESTACION_H
#define ESTACION_H
#include <string>
#include "colas/ColaEspera.h"

using namespace std;

class ListaEstaciones;

class Estacion {
private:
    string codigo;
    string nombre;
    string barrio;
    int capacidadAnclajes;
    int bicisDisponibles;
    ListaEstaciones* adyacentes;
    ColaEspera* cola;
    bool visitada;
    Estacion* padre;

public:
    Estacion(string codigo, string nombre, string barrio, int capacidadAnclajes, int bicisDisponibles);
    Estacion();
    ~Estacion();
    string getCodigo();
    string getNombre();
    string getBarrio();
    int getCapacidadAnclajes();
    int getBicisDisponibles();
    int getFaltantes();
    Estacion* getPadre();
    bool isVisitada();
    ListaEstaciones* getAdyacentes();
    double getPorcentajeOcupacion();
    void agregarAdyacente(Estacion* estacion);
    int devolverBicicleta();
    bool retirarBicicleta(int dni);
    void visitar();
    void setPadre(Estacion* padre);
    void resetearAtributosBusqueda();
};
#endif