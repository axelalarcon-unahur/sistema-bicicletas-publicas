#ifndef LECTOR_ARCHIVOS_H
#define LECTOR_ARCHIVOS_H
#include "estaciones/GestorEstaciones.h"
#include "bicicletas/AbbBicicletas.h"
#include "viajes/ListaViajes.h"

class LectorArchivos {
    private:
        GestorEstaciones* gestor;
        AbbBicicletas* abbBicicletas;
        ListaViajes* listaViajes;

    public:
        LectorArchivos(GestorEstaciones* gestor, AbbBicicletas* abbBicicletas, ListaViajes* listaViajes);
        void leerArchivos();
        void leerEstaciones();
        void leerBicicletas();
        void leerViajes();
        void leerCiclovias();
};

#endif