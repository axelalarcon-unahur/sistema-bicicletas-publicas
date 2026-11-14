#ifndef COLA_ESTACIONES_H
#define COLA_ESTACIONES_H
//#include "NodoEstacion.h"
#include "estaciones/NodoEstacion.h"

class ColaEstaciones{
private:
        NodoEstacion* primero; // usuario que lleva mas tiempo esperando
        NodoEstacion* ultimo; // usuario que llego ultimo
public:
        ColaEstaciones();
        ~ColaEstaciones();
        void encolar(Estacion* estacion);
        Estacion* desencolar();
        bool estaVacia();
};
#endif
