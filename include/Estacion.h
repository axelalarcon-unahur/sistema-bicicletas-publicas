#ifndef ESTACION_H
#define ESTACION_H
#include <string>

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

public:
    Estacion(string codigo, string nombre, string barrio, int capacidadAnclajes, int bicisDisponibles);
    ~Estacion();
    string getCodigo();
    string getNombre();
    string getBarrio();
    int getCapacidadAnclajes();
    int getBicisDisponibles();
    int getFaltantes();
    ListaEstaciones* getAdyacentes();
    double getOcupacion();
    void agregarAdyacente(Estacion* estacion);
};
#endif