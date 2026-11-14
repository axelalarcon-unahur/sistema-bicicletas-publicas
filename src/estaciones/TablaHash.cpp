#include "estaciones/TablaHash.h"
#include <iostream>
using namespace std;
/*
    IMPLEMENTACIÓN DE HASHING:
    - Hash Cerrado
    - Función Hash: sumatoria de valor ascii de cada caracter * 128
    - Resolución de colisiones: Sondeo Lineal -> (funcionHash(clave) + i) % capacidad
*/

TablaHash::TablaHash(int capacidadInicial) {
    estaciones = new Estacion*[capacidadInicial]; 
    cantidadEstaciones = 0;
    capacidad = capacidadInicial;
    tombstone = new Estacion();
    totalColisiones = 0;

    for (int i = 0; i < capacidadInicial; i++) {
        estaciones[i] = nullptr;
    }
}

TablaHash::~TablaHash() {
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

int TablaHash::funcionHash(string codigo) {
    int hash = 0;
    
    for (int i = 0; i < (int) codigo.length(); i++) {
        hash = hash * 31 + codigo[i];
    }
    
    return hash % capacidad;
}

bool TablaHash::hayEstacion(int posicion) {
    return estaciones[posicion] != nullptr && estaciones[posicion] != tombstone;
}

void TablaHash::cambiarCapacidad(int nuevaCapacidad) {
    Estacion** vieja = estaciones;
    int capacidadVieja = capacidad;
    capacidad = nuevaCapacidad;
    estaciones = new Estacion*[capacidad];
    totalColisiones = 0;

    for (int i = 0; i < capacidad; i++) {
        estaciones[i] = nullptr;
    }

    for (int i = 0; i < capacidadVieja; i++) {
        if (vieja[i] != nullptr && vieja[i] != tombstone) {
            agregarEstacion(vieja[i]);
            cantidadEstaciones--; // cada agregarEstacion() incrementa en 1
        }
    }

    delete[] vieja;
}

void TablaHash::verificarCambioCapacidad() {
    if (getFactorCarga() >= MAX_FACTOR_CARGA) {
        cambiarCapacidad(capacidad * 1.5);
    }
}

Estacion* TablaHash::buscarEstacion(string codigo) {
    int hash = funcionHash(codigo);
    int pos = hash;
    int i = 1;

    while (estaciones[pos] != nullptr && estaciones[pos]->getCodigo() != codigo) {
        pos = (hash + i) % capacidad;
        i++;
    }

    return estaciones[pos];
}

void TablaHash::agregarEstacion(Estacion* estacion) {
    int hash = funcionHash(estacion->getCodigo());
    int pos = hash;
    int i = 1;

    while (hayEstacion(pos)) {
        pos = (hash + i) % capacidad;
        i++;
        totalColisiones++;
    }

    estaciones[pos] = estacion;
    cantidadEstaciones++;
    verificarCambioCapacidad();
}

void TablaHash::eliminarEstacion(string codigo) {
    int hash = funcionHash(codigo);
    int pos = hash;
    int i = 1;

    while (estaciones[pos] != nullptr && estaciones[pos]->getCodigo() != codigo) {
        pos = (hash + i) % capacidad;
        i++;
    }

    if (estaciones[pos] != nullptr) {
        delete estaciones[pos];
        estaciones[pos] = tombstone;
        cantidadEstaciones--;
    }
}


Estacion** TablaHash::listarEstaciones() {
    Estacion** resultado = new Estacion*[cantidadEstaciones];
    int posActual = 0;
    
    for (int i = 0; i < capacidad; i++) {
        if (hayEstacion(i)) {
            resultado[posActual++] = estaciones[i];
        }
    }
    
    return resultado;
}

Estacion** TablaHash::estacionesOrdenadasPorCapacidad() {
    Estacion** resultado = listarEstaciones();
    
    for (int i = 0; i < cantidadEstaciones - 1; i++) {
        int min = i;
        
        for (int j = i + 1; j < cantidadEstaciones; j++) {
            if (resultado[j]->getCapacidadAnclajes() < resultado[min]->getCapacidadAnclajes()) {
                min = j;
            }
        }
        
        Estacion* aux = resultado[i];
        resultado[i] = resultado[min];
        resultado[min] = aux;
    }
    
    return resultado;
}

Estacion** TablaHash::estacionesOrdenadasPorDisponibilidad() {
    Estacion** resultado = listarEstaciones();
    
    for (int i = 0; i < cantidadEstaciones - 1; i++) {
        int min = i;

        for (int j = i + 1; j < cantidadEstaciones; j++) {
            if (resultado[j]->getBicisDisponibles() < resultado[min]->getBicisDisponibles()) {
                min = j;
            }
        }

        Estacion* aux = resultado[i];
        resultado[i] = resultado[min];
        resultado[min] = aux;
    }
    
    return resultado;
}

ListaEstaciones* TablaHash::estacionesConOcupacionBaja() {
    ListaEstaciones* resultado = new ListaEstaciones();
    
    for (int i = 0; i < capacidad; i++) {
        if (hayEstacion(i) && estaciones[i]->getPorcentajeOcupacion() < 20) {
            resultado->agregarEstacion(estaciones[i]);
        }
    }
    
    return resultado;
}


int TablaHash::getCantidadEstaciones() {
    return cantidadEstaciones;
}

double TablaHash::getFactorCarga() {
    return ((double) cantidadEstaciones) / capacidad;
}

int TablaHash::getTotalColisiones() {
    return totalColisiones;
}