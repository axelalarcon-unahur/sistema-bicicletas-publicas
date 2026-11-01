#include "GestorEstaciones.h"

/*
    IMPLEMENTACIÓN DE HASHING:
    - Hash Cerrado
    - Función Hash: sumatoria de valor ascii de cada caracter * 128
    - Resolución de colisiones: Quadratic probing -> (funcionHash(clave) + i²) % capacidad
*/

GestorEstaciones::GestorEstaciones(int capacidadInicial) {
    estaciones = new Estacion*[capacidadInicial]; 
    cantidadEstaciones = 0;
    capacidad = capacidadInicial;
    tombstone = new Estacion();

    for (int i = 0; i < capacidadInicial; i++) {
        estaciones[i] = nullptr;
    }
}

GestorEstaciones::~GestorEstaciones() {
    for (int i = 0; i < capacidad; i++) {
        if (hayEstacion(i)) {
            delete estaciones[i];
        }
    }

    cantidadEstaciones = 0;
    capacidad = 0;
    delete[] estaciones;
    delete tombstone;
}

int GestorEstaciones::funcionHash(string codigo) {
    int hash = 0;

    for (int i = 0; i < codigo.length(); i++) {
        hash += codigo[i] * 128;
    }

    return hash % capacidad;
}

bool GestorEstaciones::hayEstacion(int posicion) {
    return estaciones[posicion] != nullptr && estaciones[posicion] != tombstone;
}

void GestorEstaciones::agregarEstacion(Estacion* estacion) {
    int hash = funcionHash(estacion->getCodigo());
    int pos = hash;
    int i = 1;

    while (hayEstacion(pos)) {
        pos = (hash + (i*i)) % capacidad;
        i++;
    }

    estaciones[pos] = estacion;
}

void GestorEstaciones::eliminarEstacion(string codigo) {
    int hash = funcionHash(codigo);
    int pos = hash;
    int i = 1;

    while (estaciones[pos] != nullptr && estaciones[pos]->getCodigo() != codigo) {
        pos = (hash + i*i) % capacidad;
        i++;
    }

    if (estaciones[pos] != nullptr) {
        delete estaciones[pos];
        estaciones[pos] = tombstone;
    }
}

