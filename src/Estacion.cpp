#include "Estacion.h"
#include "ListaEstaciones.h"

Estacion::Estacion(string codigo, string nombre, string barrio, int capacidadAnclajes, int bicisDisponibles) {
    this->codigo = codigo;
    this->nombre = nombre;
    this->barrio = barrio;
    this->capacidadAnclajes = capacidadAnclajes;
    this->bicisDisponibles = bicisDisponibles;
    this->adyacentes = new ListaEstaciones();
}

Estacion::~Estacion() {
    delete adyacentes;
}

string Estacion::getCodigo() {
    return codigo;
}

string Estacion::getNombre() {
    return nombre;
}

string Estacion::getBarrio() {
    return barrio;
}

int Estacion::getCapacidadAnclajes() {
    return capacidadAnclajes;
}

int Estacion::getBicisDisponibles() {
    return bicisDisponibles;
}

ListaEstaciones* Estacion::getAdyacentes() {
    return adyacentes;
}

double Estacion::getOcupacion() {
    return ((double) bicisDisponibles) / capacidadAnclajes;
}

void Estacion::agregarAdyacente(Estacion* estacion) {
    adyacentes->agregarEstacion(estacion);
}