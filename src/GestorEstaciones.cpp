#include <iostream>
#include "GestorEstaciones.h"

GestorEstaciones::GestorEstaciones(int capacidadInicial) {
    tablaHash = new TablaHash(capacidadInicial);
    grafo = new GrafoEstaciones();
}

GestorEstaciones::~GestorEstaciones() {
    delete tablaHash;
    delete grafo;
}

void GestorEstaciones::mostrarInformacion(string codigo) {
    Estacion* estacion = tablaHash->buscarEstacion(codigo);

    cout << "--------------------------------------------" << endl;
    if (estacion == nullptr) {
        cout << "Estación no encontrada para el código " << codigo << "." << endl;
    }
    else {
        cout << "Código: " << codigo << endl;
        cout << "Nombre: " << estacion->getNombre() << endl;
        cout << "Barrio: " << estacion->getBarrio() << endl;
        cout << "Capacidad de Anclajes: " << estacion->getCapacidadAnclajes() << endl;
        cout << "Bicicletas disponibles: " << estacion->getBicisDisponibles() << endl;
    }
    cout << "--------------------------------------------" << endl;
}

void GestorEstaciones::agregarEstacion(Estacion* estacion) {
    tablaHash->agregarEstacion(estacion);
}

void GestorEstaciones::eliminarEstacion(string codigo) {
    tablaHash->eliminarEstacion(codigo);
}

void GestorEstaciones::estacionesOrdenadasPorCapacidad() {
    Estacion** estaciones = tablaHash->estacionesOrdenadasPorCapacidad();

    cout << "--------------------------------------------" << endl;
    cout << "Estaciones ordenadas por capacidad: " << endl;

    for (int i = 0; i < tablaHash->getCantidadEstaciones(); i++) {
        cout << i + 1 << ". " << estaciones[i]->getCodigo() << endl;
    }

    cout << "--------------------------------------------" << endl;
    delete[] estaciones;
}

void GestorEstaciones::estacionesOrdenadasPorDisponibilidad() {
    Estacion** estaciones = tablaHash->estacionesOrdenadasPorDisponibilidad();

    cout << "--------------------------------------------" << endl;
    cout << "Estaciones ordenadas por disponibilidad: " << endl;

    for (int i = 0; i < tablaHash->getCantidadEstaciones(); i++) {
        cout << i + 1 << ". " << estaciones[i]->getCodigo() << endl;
    }

    cout << "--------------------------------------------" << endl;
    delete[] estaciones;
}

void GestorEstaciones::estacionesConOcupacionBaja() {
    ListaEstaciones* estaciones = tablaHash->estacionesConOcupacionBaja();

    if (estaciones->getLargo() == 0) {
        cout << "No hay estaciones con ocupación menor al 20%." << endl;
    }
    else {

        cout << "--------------------------------------------" << endl;
        for (int i = 0; i < estaciones->getLargo(); i++) {
            cout << estaciones->getEstacion(i)->getCodigo() << endl;
        }

        cout << "--------------------------------------------" << endl;
    }

    delete estaciones;
}

void GestorEstaciones::caminoMasCorto(string origen, string destino) {
    Estacion* inicio = tablaHash->buscarEstacion(origen);
    Estacion* fin = tablaHash->buscarEstacion(destino);
    Estacion** aux = tablaHash->listarEstaciones();

    ListaEstaciones* estaciones = grafo->caminoMasCorto(inicio, fin, aux, tablaHash->getCantidadEstaciones());

    cout << "--------------------------------------------" << endl;
    if (estaciones == nullptr) {
        cout << "No hay camino entre las estaciones " << origen << " y " << destino << "." << endl;
    }
    else {
        cout << inicio->getCodigo();
        for (int i = 1; i < estaciones->getLargo(); i++) {
            cout << " -> " << estaciones->getEstacion(i)->getCodigo();
        }
        cout << endl;
    }

    cout << "--------------------------------------------" << endl;

    delete estaciones;
    delete[] aux;
}

void GestorEstaciones::agregarCiclovia(string a, string b) {
    Estacion* inicio = tablaHash->buscarEstacion(a);
    Estacion* fin = tablaHash->buscarEstacion(b);

    if (inicio == nullptr || fin == nullptr) {
        cout << "Códigos de estación inválidos" << endl;
    }
    else {
        inicio->agregarAdyacente(fin);
        fin->agregarAdyacente(inicio);
    }
}

void GestorEstaciones::totalColisiones() {
    cout << "Colisiones totales: " << tablaHash->getTotalColisiones() << endl;;
}

void GestorEstaciones::factorDeCarga() {
    cout << "Factor de Carga: " << tablaHash->getFactorCarga() << endl;
}