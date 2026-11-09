#include "GrafoEstaciones.h"
#include "ColaEstaciones.h"

ListaEstaciones* GrafoEstaciones::caminoMasCorto(Estacion* origen, Estacion* destino, Estacion** estaciones, int cantidadEstaciones) {
    if (origen == nullptr || destino == nullptr) {
        return nullptr;
    }

    ColaEstaciones *c = new ColaEstaciones();
    c->encolar(origen);
    origen->visitar();

    while (!c->estaVacia()) {
        Estacion* actual = c->desencolar();

        if (actual == destino) {
            break;
        }

        ListaEstaciones* adyacentesActual = actual->getAdyacentes();

        for (int i = 0; i < adyacentesActual->getLargo(); i++) {
            Estacion* adyacente = adyacentesActual->getEstacion(i);

            if (!adyacente->isVisitada()) {
                c->encolar(adyacentesActual->getEstacion(i));
                adyacente->setPadre(actual);
                adyacente->visitar();
            }
        }
    }

    ListaEstaciones* camino = caminoEncontrado(destino, cantidadEstaciones);
    limpiarEstaciones(estaciones, cantidadEstaciones);
    delete c;
    return camino;
}

ListaEstaciones* GrafoEstaciones::caminoEncontrado(Estacion* destino, int cantidadEstaciones) {
    if (!destino->isVisitada()) {
        return nullptr;
    }
    
    Estacion** aux = new Estacion*[cantidadEstaciones];
    int i = 0;
    Estacion* actual = destino;
    ListaEstaciones* resultado = new ListaEstaciones();
    
    while (actual != nullptr) {
        aux[i++] = actual;
        actual = actual->getPadre();
    }

    // ultima posicion no fue usada, por lo que hay que decrementar i antes de agregar
    while (--i >= 0) {
        resultado->agregarEstacion(aux[i]);
    }   

    delete[] aux;
    return resultado;
}

void GrafoEstaciones::limpiarEstaciones(Estacion** estaciones, int cantidadEstaciones) {
    for (int i = 0; i < cantidadEstaciones; i++) {
        estaciones[i]->resetearAtributosBusqueda();
    }
}