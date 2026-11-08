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
void ListaBicicletas::cantBicicletasSuperadasPorKm(int kilometros){
    NodoBicicleta* actual = primero;
    while(actual!=nullptr){
        if(actual->dato.getKilometros()>kilometros){
           cout<< "El id de la bicicleta es : " << actual->dato.getBiciId()<<endl;
           cout<< "Estacion :" << actual->dato.getCodigoEstacion()<<endl;
           cout<< "Estado : " << actual->dato.getEstado()<<endl;
           cout<< "Kilometros : " << actual->dato.getKilometros()<<endl;
        }
        actual = actual->siguiente;
    }
}
