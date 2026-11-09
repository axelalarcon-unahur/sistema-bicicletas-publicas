#include "GestorEstaciones.h"

GestorEstaciones::GestorEstaciones(int capacidadInicial) {
    tablaHash = new TablaHash(capacidadInicial);
    grafo = new GrafoEstaciones();
}

GestorEstaciones::~GestorEstaciones() {
    delete tablaHash;
    delete grafo;
}