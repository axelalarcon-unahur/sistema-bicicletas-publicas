#ifndef BACKTRACKER_H
#define BACKTRACKER_H
#include "estaciones/ListaEstaciones.h"

class Backtracker {
private:
    // ATRIBUTOS DE ENTRADA 
    Estacion** estaciones;
    int cantidadEstaciones; // cantidad de estaciones dadas como input
    int capacidadCamion;

    // ATRIBUTOS DE BACKTRACKING
    ListaEstaciones** soluciones;
    int t; // tamaño del array soluciones
    int cantidadSoluciones;
    
    void backtracking(int capacidadActual, ListaEstaciones* solucionActual, int posActual);
    void verificarCambioCapacidad();
    void cambiarCapacidad();

public:
    Backtracker(Estacion** estaciones, int cantidadEstaciones, int capacidadCamion);
    ~Backtracker();

    ListaEstaciones** encontrarSoluciones();
    int getCantidadSoluciones();
};

#endif
