#include "GestorEstaciones.h"
#include "ColaEstaciones.h"
/*
    IMPLEMENTACIÓN DE HASHING:
    - Hash Cerrado
    - Función Hash: sumatoria de valor ascii de cada caracter * 128
    - Resolución de colisiones: Quadratic probing -> (funcionHash(clave) + i²) % capacidad
*/

GestorEstaciones::GestorEstaciones(int capacidadInicial) {
    estaciones = new Estacion*[capacidadInicial]; 
    cantidadEstaciones = 0;
    capacidad = capacidadInicial;
    tombstone = new Estacion();

    for (int i = 0; i < capacidadInicial; i++) {
        estaciones[i] = nullptr;
    }
}

GestorEstaciones::~GestorEstaciones() {
    for (int i = 0; i < capacidad; i++) {
        if (hayEstacion(i)) {
            delete estaciones[i];
        }
    }

    cantidadEstaciones = 0;
    capacidad = 0;
    delete[] estaciones;
    delete tombstone;
}

int GestorEstaciones::funcionHash(string codigo) {
    int hash = 0;

    for (int i = 0; i < codigo.length(); i++) {
        hash += codigo[i] * 128;
    }

    return hash % capacidad;
}

bool GestorEstaciones::hayEstacion(int posicion) {
    return estaciones[posicion] != nullptr && estaciones[posicion] != tombstone;
}

void GestorEstaciones::agregarEstacion(Estacion* estacion) {
    int hash = funcionHash(estacion->getCodigo());
    int pos = hash;
    int i = 1;

    while (hayEstacion(pos)) {
        pos = (hash + (i*i)) % capacidad;
        i++;
    }

    estaciones[pos] = estacion;
}

void GestorEstaciones::eliminarEstacion(string codigo) {
    int hash = funcionHash(codigo);
    int pos = hash;
    int i = 1;

    while (estaciones[pos] != nullptr && estaciones[pos]->getCodigo() != codigo) {
        pos = (hash + i*i) % capacidad;
        i++;
    }

    if (estaciones[pos] != nullptr) {
        delete estaciones[pos];
        estaciones[pos] = tombstone;
    }
}

Estacion* GestorEstaciones::buscarEstacion(string codigo) {
    int hash = funcionHash(codigo);
    int pos = hash;
    int i = 1;

    while (estaciones[pos] != nullptr && estaciones[pos]->getCodigo() != codigo) {
        pos = (hash + (i*i)) % capacidad;
        i++;
    }

    return estaciones[pos];
}


Estacion** GestorEstaciones::listarEstaciones() {
    Estacion** resultado = new Estacion*[cantidadEstaciones];
    int posActual = 0;

    for (int i = 0; i < capacidad; i++) {
        if (hayEstacion(i)) {
            resultado[posActual++] = estaciones[i];
        }
    }

    return resultado;
}

Estacion** GestorEstaciones::estacionesOrdenadasPorCapacidad() {
    Estacion** resultado = listarEstaciones();

    for (int i = 0; i < cantidadEstaciones - 1; i++) {
        int min = i;

        for (int j = 0; j < cantidadEstaciones; j++) {
            if (resultado[j]->getCapacidadAnclajes() < resultado[min]->getCapacidadAnclajes()) {
                min = j;
            }
        }

        Estacion* aux = resultado[i];
        resultado[i] = resultado[min];
        resultado[min] = aux;
    }

    return resultado;
}

Estacion** GestorEstaciones::estacionesOrdenadasPorDisponibilidad() {
    Estacion** resultado = listarEstaciones();

    for (int i = 0; i < cantidadEstaciones - 1; i++) {
        int min = i;

        for (int j = 0; j < cantidadEstaciones; j++) {
            if (resultado[j]->getBicisDisponibles() < resultado[min]->getBicisDisponibles()) {
                min = j;
            }
        }

        Estacion* aux = resultado[i];
        resultado[i] = resultado[min];
        resultado[min] = aux;
    }

    return resultado;
}

int GestorEstaciones::getCantidadEstaciones() {
    return cantidadEstaciones;
}

ListaEstaciones* GestorEstaciones::estacionesConOcupacionBaja() {
    ListaEstaciones* resultado = new ListaEstaciones();

    for (int i = 0; i < capacidad; i++) {
        if (hayEstacion(i) && estaciones[i]->getPorcentajeOcupacion() < 20) {
            resultado->agregarEstacion(estaciones[i]);
        }
    }

    return resultado;
}

ListaEstaciones* GestorEstaciones::caminoMasCorto(string origen, string destino) {
    Estacion* inicio = buscarEstacion(origen);
    Estacion* fin = buscarEstacion(destino);

    if (inicio == nullptr || fin == nullptr) {
        return nullptr;
    }

    Estacion** previos = new Estacion*[capacidad]; 

    for (int i = 0; i < capacidad; i++) {
        previos[i] = nullptr;
    }

    ColaEstaciones *c = new ColaEstaciones();
    c->encolar(inicio);
    agregarPrevio(inicio, inicio, previos);

    while (!c->estaVacia()) {
        Estacion* actual = c->desencolar();

        if (actual->getCodigo() == destino) {
            break;
        }

        ListaEstaciones* adyacentesActual = actual->getAdyacentes();

        for (int i = 0; i < adyacentesActual->getLargo(); i++) {
            Estacion* adyacente = adyacentesActual->getEstacion(i);

            if (buscarPrevio(adyacente, previos) == nullptr) {
                c->encolar(adyacentesActual->getEstacion(i));
                agregarPrevio(adyacente, actual, previos);
            }
        }
    }

    return caminoEncontrado(inicio, fin, previos);
}

void GestorEstaciones::agregarPrevio(Estacion* estacion, Estacion* previo, Estacion** previos) {
    int hash = funcionHash(estacion->getCodigo());
    int pos = hash;
    int i = 1;

    while (hayEstacion(pos)) {
        pos = (hash + (i*i)) % capacidad;
        i++;
    }

    previos[pos] = previo;
}

Estacion* GestorEstaciones::buscarPrevio(Estacion* estacion, Estacion** previos) {
    int hash = funcionHash(estacion->getCodigo());
    int pos = hash;
    int i = 1;

    while (estaciones[pos] != nullptr && estaciones[pos]->getCodigo() != estacion->getCodigo()) {
        pos = (hash + (i*i)) % capacidad;
        i++;
    }

    return previos[pos];
}

ListaEstaciones* caminoEncontrado(Estacion* origen, Estacion* destino, Estacion** previos) {
    
}
