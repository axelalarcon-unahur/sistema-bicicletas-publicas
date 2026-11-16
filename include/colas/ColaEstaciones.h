#ifndef COLA_ESTACIONES_H
#define COLA_ESTACIONES_H
#include "estaciones/NodoEstacion.h"

class ColaEstaciones{
private:
        NodoEstacion* primero; 
        NodoEstacion* ultimo; 
public:
        ColaEstaciones();
        ~ColaEstaciones();
        void encolar(Estacion* estacion);
        Estacion* desencolar();
        bool estaVacia();
};
#endif
