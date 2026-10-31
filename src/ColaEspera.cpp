#include "ColaEspera.h"
#include <iostream>
using namespace std;

ColaEspera::ColaEspera(){
    // ambos null porque cuando arrancamos no hay ningun usuario
    primero = nullptr;
    ultimo == nullptr;
}
ColaEspera::~ColaEspera(){
    while(primero!=nullptr){
        NodoEspera* aux = primero;
        primero = primero -> siguiente;
        delete aux;
    }
    ultimo = nullptr;
}
void ColaEspera::encolar(int dni){
    NodoEspera* nuevo = new NodoEspera(dni);
    if(primero ==  nullptr){
        primero = nuevo;
        ultimo = nuevo;
    }
    else{
        ultimo->siguiente = nuevo;
        ultimo = nuevo;
    }
}
int ColaEspera::desencolar(){
    if(estaVacia()){
       return -1;
    }
    NodoEspera* aux = primero;
    int dni = aux->dniUser;
    primero = primero->siguiente;
    if(primero == nullptr){
        ultimo = nullptr;
    }
    delete aux;
    return dni;
}
bool ColaEspera::estaVacia(){
    return primero == nullptr;
}
