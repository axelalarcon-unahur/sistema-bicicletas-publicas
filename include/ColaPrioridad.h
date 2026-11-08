#include "Bicicleta.h"
#ifndef COLAPRIORIDAD_H
#define COLAPRIORIDAD_H

class ColaPrioridadBicicletas {
private:
    Bicicleta** heap; 
    int cantBicicletasGuardadas;
    int cantMax;
    int calcularPrioridad(Bicicleta* bici);
public:
    ColaPrioridadBicicletas(int cantMax);
    ~ColaPrioridadBicicletas();
    bool extraerBicicletaConMayorPrioridad(Bicicleta& bici);
    void insertarUnaBici(Bicicleta bici);
};
#endif