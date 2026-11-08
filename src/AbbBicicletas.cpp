#include "AbbBicicletas.h"
#include <iostream>
using namespace std;

NodoABBBicicletas::NodoABBBicicletas(Bicicleta unaBici)
    :dato(unaBici) //contruye el objeto bici con el dato q recibimos
{
    izquierdo = nullptr;
    derecho = nullptr;
}
AbbBicicletas::AbbBicicletas(){
    raiz = nullptr;
}
void AbbBicicletas::insertarUnaBicicleta(Bicicleta unaBici){
    insertarRecursivo(raiz,unaBici);
}
void AbbBicicletas::insertarRecursivo(NodoABBBicicletas*& actual, Bicicleta unaBici){
    if(actual == nullptr){
        actual = new NodoABBBicicletas(unaBici);
    }
    else if(unaBici.getBiciId() < actual->dato.getBiciId()){
        insertarRecursivo(actual->izquierdo,unaBici);
    }
    else if(unaBici.getBiciId() > actual->dato.getBiciId()){
        insertarRecursivo(actual->derecho,unaBici);
    }
}
void AbbBicicletas::buscarBici(int id){
    busquedaYMuestroRecursivo(raiz,id);
}
void AbbBicicletas::busquedaYMuestroRecursivo(NodoABBBicicletas* actual, int id){
    if(actual == nullptr){
        cout <<"No se encuentra la bicicleta" << endl;
    }
    else if(actual->dato.getBiciId() == id){
        cout<<"Bicicleta encontrada :" << endl;
        cout << "ID: " << actual->dato.getBiciId() << endl;
        cout << "Estacion: " << actual->dato.getCodigoEstacion() << endl;
        cout << "Tipo: " << actual->dato.getTipo() << endl;
        cout << "Estado: " << actual->dato.getEstado() << endl;
        cout << "Kilometros: " << actual->dato.getKilometros() << endl;
    }
    else if(id < actual->dato.getBiciId()){
        busquedaYMuestroRecursivo(actual->izquierdo,id);
    
    }
    else{
        busquedaYMuestroRecursivo(actual->derecho,id);
    }
}
void AbbBicicletas::listarBicicletasInOrden(){
    listarInOrdenRecursivo(raiz);
}
void AbbBicicletas::listarInOrdenRecursivo(NodoABBBicicletas* actual){
    if(actual != nullptr){
        listarInOrdenRecursivo(actual->izquierdo);
        cout << "ID: " << actual->dato.getBiciId() << endl;
        cout << "Estacion: " << actual->dato.getCodigoEstacion() << endl;
        cout << "Tipo: " << actual->dato.getTipo() << endl;
        cout << "Estado: " << actual->dato.getEstado() << endl;
        cout << "Kilometros: " << actual->dato.getKilometros() << endl;
        listarInOrdenRecursivo(actual->izquierdo);
    }
}
int AbbBicicletas::cantBicicletasAveriadas(){
    return contarBicicletasAveriadas(raiz);
}
int AbbBicicletas::contarBicicletasAveriadas(NodoABBBicicletas* actual){
    if(actual == nullptr){
        return 0;
    }
    int cantBicisAveriadas = 0; //inicializo;
    if(actual->dato.getEstado() == "Averiada"){
        cantBicisAveriadas = cantBicisAveriadas + 1;
    }
    int sumaCantidad = cantBicisAveriadas + contarBicicletasAveriadas(actual->izquierdo) 
    + contarBicicletasAveriadas(actual->derecho);
    return sumaCantidad;
}
int AbbBicicletas::calcularAlturaArbol(){
    return alturaArbol(raiz);
}
int AbbBicicletas::alturaArbol(NodoABBBicicletas* actual){
    if(actual == nullptr){
        return 0;
    }
    int alturaIzq = alturaArbol(actual->izquierdo);
    int alturaDer = alturaArbol(actual->derecho);
    if(alturaIzq > alturaDer){
        return alturaIzq + 1;
    }
    else{
        return alturaDer + 1;
    }
}
AbbBicicletas::~AbbBicicletas(){
    liberarPostOrden(raiz);
}
void AbbBicicletas::liberarPostOrden(NodoABBBicicletas* actual){
    if(actual != nullptr){
        liberarPostOrden(actual->izquierdo);
        liberarPostOrden(actual->derecho);
        delete actual;
    }
}
