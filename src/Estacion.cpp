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

// usado para tombstones en hash
Estacion::Estacion() {
    codigo = "";
    nombre = "";
    barrio = "";
    capacidadAnclajes = 1;
    bicisDisponibles = 1;
    adyacentes = new ListaEstaciones();
}

Estacion::~Estacion() {
    // se quita a si misma de la lista de adyacentes de cada vecino
    for (int i = 0; i < adyacentes->getLargo(); i++) {
        adyacentes->getEstacion(i)->getAdyacentes()->eliminarEstacion(this);
    }
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

int Estacion::getFaltantes() {
    return capacidadAnclajes - bicisDisponibles;
}

ListaEstaciones* Estacion::getAdyacentes() {
    return adyacentes;
}

double Estacion::getPorcentajeOcupacion() {
    return ((double) bicisDisponibles) / capacidadAnclajes * 100;
}

void Estacion::agregarAdyacente(Estacion* estacion) {
    adyacentes->agregarEstacion(estacion);
}