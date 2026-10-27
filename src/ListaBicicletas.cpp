#include "ListaBicicletas.h"
#include <iostream>

NodoBicicleta::NodoBicicleta(Bicicleta bici) : dato(bici) {
    siguiente = nullptr;
}
ListaBicicletas::ListaBicicletas() {
    primero = nullptr;
}
ListaBicicletas::~ListaBicicletas() {
    NodoBicicleta* actual = primero;
    while (actual != nullptr) {
        NodoBicicleta* aux = actual;
        actual = actual->siguiente;
        delete aux;
    }
}
void ListaBicicletas::agregarBicicleta(Bicicleta bici){
    NodoBicicleta* nuevo = new NodoBicicleta(bici);
    if(primero == nullptr){
        primero = nuevo;
    }
    else{
        NodoBicicleta* actual = primero;
        while(actual->siguiente !=nullptr){
            actual = actual ->siguiente;
    }
    actual->siguiente = nuevo;
    }
}
// 3) Listar las bicicletas con más de X kilómetros, donde X lo ingresa el usuario, para enviarlas a revisión.
ListaBicicletas ListaBicicletas::cantBicicletasSuperadasPorKm(int kilometros){
    NodoBicicleta* actual = primero;
    ListaBicicletas nuevaLista;
    while(actual!=nullptr){
        if(actual->dato.getKilometros()>kilometros){
            nuevaLista.agregarBicicleta(actual->dato);
        }
        actual = actual->siguiente;
    }
    return nuevaLista;
}
