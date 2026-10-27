#include "Bicicleta.h"

class ColaPrioridadBicicletas {
private:
    Bicicleta** heap; 
    // heap puntero a un arreglo cuyos elementos son punteros a objetos BICICLETAS
    int cantBicicletasGuardadas;
    int cantMax;

public:
    ColaPrioridadBicicletas(int cantMax);
    ~ColaPrioridadBicicletas();
};
