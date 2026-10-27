#include "ColaPrioridad.h"

ColaPrioridadBicicletas::ColaPrioridadBicicletas(int cantMax) {
    this->cantMax = cantMax;
    cantBicicletasGuardadas = 0;
    heap = new Bicicleta*[cantMax];
}

ColaPrioridadBicicletas::~ColaPrioridadBicicletas() {
    delete[] heap;
}