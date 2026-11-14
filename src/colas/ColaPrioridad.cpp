#include "colas/ColaPrioridad.h"
#include <iostream>
using namespace std;

ColaPrioridadBicicletas::ColaPrioridadBicicletas(int cantMax) {
    this->cantMax = cantMax;
    cantBicicletasGuardadas = 0;
    heap = new Bicicleta*[cantMax];
}
int ColaPrioridadBicicletas::calcularPrioridad(Bicicleta* unaBici){
    if(unaBici->getTipo() == "Electrica"){
        return 1;
    }
    else if(unaBici->getTipo() == "Mecanica" && unaBici->getKilometros() > 5000){
        return 2;
    }
    else{
        return 3;
    }
}
void ColaPrioridadBicicletas::insertarUnaBici(Bicicleta unaBici){
    if(unaBici.getEstado() != "Averiada"){
        return;
    }
    if(cantBicicletasGuardadas == cantMax){
        return;
    }
    heap[cantBicicletasGuardadas] = new Bicicleta(unaBici);
    int i = cantBicicletasGuardadas;
    cantBicicletasGuardadas++;
   while(i > 0){
        int padre = (i-1) / 2;
        if(calcularPrioridad(heap[i]) < calcularPrioridad(heap[padre])){
            Bicicleta* aux = heap[i];
            heap[i] = heap[padre];
            heap[padre] = aux;

            i = padre;
        }
        else{
            break;
        }
   }
}
bool ColaPrioridadBicicletas::extraerBicicletaConMayorPrioridad(Bicicleta& bici){
    if(cantBicicletasGuardadas == 0){
        return false; 
    }
    bici = *heap[0]; 
    delete heap[0] ; 
    cantBicicletasGuardadas --; 
    if(cantBicicletasGuardadas == 0){
        return true;
    } 
    heap[0] = heap[cantBicicletasGuardadas];
    heap[cantBicicletasGuardadas] = nullptr;
    int i = 0;
    while(true){
        int hijoIzquierdo = 2 * i +1;
        int hijoDerecho = 2 * i + 2;
        int menor = i;
        if(hijoIzquierdo < cantBicicletasGuardadas && calcularPrioridad(heap[hijoIzquierdo]) < calcularPrioridad(heap[menor])){
            menor = hijoIzquierdo;
        }
        if(hijoDerecho < cantBicicletasGuardadas && calcularPrioridad(heap[hijoDerecho]) < calcularPrioridad(heap[menor])){
            menor = hijoDerecho;
        }
        if(menor == i){
            break;
        }
        Bicicleta* aux = heap[i];
        heap[i] = heap[menor];
        heap[menor] = aux;
        i = menor;
    }
    return true;
}
ColaPrioridadBicicletas::~ColaPrioridadBicicletas() {
    for(int i= 0; i < cantBicicletasGuardadas;i++){
        delete heap[i];
    }
    delete[] heap;
}
