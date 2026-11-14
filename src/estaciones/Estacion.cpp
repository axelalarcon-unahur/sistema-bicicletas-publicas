#include <iostream>
#include "estaciones/Estacion.h"
#include "estaciones/ListaEstaciones.h"

Estacion::Estacion(string codigo, string nombre, string barrio, int capacidadAnclajes, int bicisDisponibles) {
    this->codigo = codigo;
    this->nombre = nombre;
    this->barrio = barrio;
    this->capacidadAnclajes = capacidadAnclajes;
    this->bicisDisponibles = bicisDisponibles;
    this->adyacentes = new ListaEstaciones();
    cola = new ColaEspera();
    visitada = false;
    padre = nullptr;
}

// usado para tombstones en hash
Estacion::Estacion() {
    codigo = "";
    nombre = "";
    barrio = "";
    capacidadAnclajes = 1;
    bicisDisponibles = 1;
    adyacentes = new ListaEstaciones();
    cola = new ColaEspera();
    visitada = false;
    padre = nullptr;
}

Estacion::~Estacion() {
    // se quita a si misma de la lista de adyacentes de cada vecino
    for (int i = 0; i < adyacentes->getLargo(); i++) {
        adyacentes->getEstacion(i)->getAdyacentes()->quitarEstacion(this);
    }
    delete adyacentes;
    delete cola; //agregado para probar
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

void Estacion::visitar() {
    visitada = true;
}

void Estacion::setPadre(Estacion* padre) {
    this->padre = padre;
}

void Estacion::resetearAtributosBusqueda() {
    visitada = false;
    padre = nullptr;
}

int Estacion::devolverBicicleta() {
    // si hay usuario esperando, devuelve el dni del usuario 
    if (!cola->estaVacia()) {
        return cola->desencolar();
    }
    // si la estacion no esta llena, incrementa la cantidad
    if (bicisDisponibles < capacidadAnclajes) {
        bicisDisponibles++;
    }

    // -1 como señal de que ningún usuario tomó la bicicleta
    return -1; 
}

// devuelve si el usuario recibio bicicleta o no 
bool Estacion::retirarBicicleta(int dni) {
    if (bicisDisponibles > 0) {
        bicisDisponibles--;
        return true;
    }

    else {
        cola->encolar(dni);
        return false;
    }
}

Estacion* Estacion::getPadre() {
    return padre;
}
bool Estacion::isVisitada() {
    return visitada;
}