#ifndef ESTACION_H
#define ESTACION_H
#include <string>

using namespace std;

class Estacion {
private:
    string codigo;
    string nombre;
    string barrio;
    int capacidadAnclajes;
    int bicisDisponibles;

public:
    Estacion(string codigo, string nombre, string barrio, int capacidadAnclajes, int bicisDisponibles);
    string getCodigo();
    string getNombre();
    string getBarrio();
    int getCapacidadAnclajes();
    int getBicisDisponibles();
};
#endif