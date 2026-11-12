#include "Backtracker.h"

Backtracker::Backtracker(Estacion** estaciones, int cantidadEstaciones, int capacidadCamion) {
    this->estaciones = estaciones;
    this->cantidadEstaciones = cantidadEstaciones;
    this->capacidadCamion = capacidadCamion;

    t = cantidadEstaciones;
    soluciones = new ListaEstaciones*[t];
    cantidadSoluciones = 0;

    for (int i = 0; i < t; i++) {
        soluciones[i] = nullptr;
    }
}

// deberia eliminar algo?
Backtracker::~Backtracker() {
    for (int i = 0; i < cantidadSoluciones; i++) {
        delete soluciones[i];
    }

    delete[] soluciones;
}

ListaEstaciones** Backtracker::encontrarSolucion() {
    backtracking(0, new ListaEstaciones(), 0);
    return soluciones;
}

void Backtracker::backtracking(int capacidadActual, ListaEstaciones* solucionActual, int posActual) {
    if (capacidadActual == capacidadCamion) {
        verificarCambioCapacidad();
        soluciones[cantidadSoluciones++] = new ListaEstaciones(*solucionActual);
        // return; // si se retorna, se excluyen estaciones en posiciones futuras con 0 faltantes
    }

    for (int i = posActual; i < cantidadEstaciones; i++) {
        if (capacidadActual + estaciones[i]->getFaltantes() > capacidadCamion) {
            continue;
        }

        solucionActual->agregarEstacion(estaciones[i]);
        backtracking(capacidadActual + estaciones[i]->getFaltantes(), solucionActual, i + 1);
        solucionActual->quitarEstacion(estaciones[i]);
    }
}

void Backtracker::verificarCambioCapacidad() {
    if (cantidadSoluciones == t) {
        cambiarCapacidad();
    }
}

void Backtracker::cambiarCapacidad() {
    int tamanioNuevo = t * 2;
    ListaEstaciones** nueva = new ListaEstaciones*[tamanioNuevo];

    for (int i = 0; i < tamanioNuevo; i++) {
        nueva[i] = i < cantidadEstaciones ? soluciones[i] : nullptr;
    }

    t = tamanioNuevo;

    delete[] soluciones;
    soluciones = nueva;
}

int Backtracker::getCantidadSoluciones() {
    return cantidadEstaciones;
}