#include "ColaPrioridad.h"
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
    // verifico que la bicicleta este averiada
    if(unaBici.getEstado() != "Averiada"){
        return;
    }
    // verifico que haya espacio en el heap
    if(cantBicicletasGuardadas == cantMax){
        return;
    }
    // creo la copia dinamica de la bicicleta
    heap[cantBicicletasGuardadas] = new Bicicleta(unaBici);
    //guardo la posicion en la que insertamos
    int i = cantBicicletasGuardadas;
    cantBicicletasGuardadas++;
    /*
    ------------ SUBO LA BICICLETA SI TIENE PRIORIDAD -----------
    */
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
        return false; // no hay bicicletas guardadas
    }
    bici = *heap[0]; // guardo la mayor prioridad -> raiz
    delete heap[0] ; // libero la que estaba en la raiz
    cantBicicletasGuardadas --; // si era la unica bici ya terminamos.
    if(cantBicicletasGuardadas == 0){
        return true;
    } 
    //Movemos el ultimo elemento a la raiz
    heap[0] = heap[cantBicicletasGuardadas];
    heap[cantBicicletasGuardadas] = nullptr;
    int i = 0;
    // --------- REACOMODAMOS HACIA ABAJO -----------------
    while(true){
        int hijoIzquierdo = 2 * i +1;
        int hijoDerecho = 2 * i + 2;
        int menor = i;
        // comparamos con el hijo izquierdo
        if(hijoIzquierdo < cantBicicletasGuardadas && calcularPrioridad(heap[hijoIzquierdo]) < calcularPrioridad(heap[menor])){
            menor = hijoIzquierdo;
        }
        // comparo con el hijo izquierdo
        if(hijoDerecho < cantBicicletasGuardadas && calcularPrioridad(heap[hijoDerecho]) < calcularPrioridad(heap[menor])){
            menor = hijoDerecho;
        }
        // si el padre es el menor -> terminamos
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
    // tenemos que liberar cada bicicleta antes de liberar el arreglo
    for(int i= 0; i < cantBicicletasGuardadas;i++){
        delete heap[i];
    }
    delete[] heap;
}
