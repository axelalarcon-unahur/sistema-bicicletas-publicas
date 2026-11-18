#include "bicicletas/AbbBicicletas.h"
#include <iostream>
using namespace std;

NodoABBBicicletas::NodoABBBicicletas(Bicicleta unaBici)
    :dato(unaBici) 
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
        listarInOrdenRecursivo(actual->derecho);
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
void AbbBicicletas::bicicletasConMasDeXKm(int kilometros){
    bicicletasConMasdeKmRecursivo(raiz,kilometros);
}
void AbbBicicletas::bicicletasConMasdeKmRecursivo(NodoABBBicicletas* actual, int kilometros){
    if(actual!=nullptr){
        bicicletasConMasdeKmRecursivo(actual->izquierdo,kilometros);
        if(actual->dato.getKilometros() > kilometros){
            cout<<"Id de bicicleta : " << actual->dato.getBiciId() <<endl;
            cout<<"Estacion : " << actual->dato.getCodigoEstacion() <<endl;
            cout<<"Estado : " << actual->dato.getEstado() <<endl;
            cout<<"Kilometros : " << actual->dato.getKilometros() <<endl;
        }
        bicicletasConMasdeKmRecursivo(actual->derecho,kilometros);
    }
}
bool AbbBicicletas::obtenerBicicleta(int id, Bicicleta& bici) {
    return obtenerBicicletaRecursivo(raiz, id, bici);
}
bool AbbBicicletas::obtenerBicicletaRecursivo(
    NodoABBBicicletas* actual, int id, Bicicleta& bici) {
    if (actual == nullptr) {
        return false;
    }
    if (actual->dato.getBiciId() == id) {
        bici = actual->dato;
        return true;
    }
    if (id < actual->dato.getBiciId()) {
        return obtenerBicicletaRecursivo(actual->izquierdo, id, bici);
    }
    return obtenerBicicletaRecursivo(actual->derecho, id, bici);
}
void AbbBicicletas::eliminarBicicleta(int id) {
    raiz = eliminarRecursivo(raiz, id);
}
NodoABBBicicletas* AbbBicicletas::eliminarRecursivo(
    NodoABBBicicletas* actual, int id) {
    if (actual == nullptr) {
        return nullptr;
    }
    if (id < actual->dato.getBiciId()) {
        actual->izquierdo =
            eliminarRecursivo(actual->izquierdo, id);
    }
    else if (id > actual->dato.getBiciId()) {
        actual->derecho =
            eliminarRecursivo(actual->derecho, id);
    }
    else {
        //  nodo hoja
        if (actual->izquierdo == nullptr &&
            actual->derecho == nullptr) {

            delete actual;
            return nullptr;
        }
        //  nodo con un solo hijo
        if (actual->izquierdo == nullptr) {
            NodoABBBicicletas* aux = actual->derecho;
            delete actual;
            return aux;
        }
        if (actual->derecho == nullptr) {
            NodoABBBicicletas* aux = actual->izquierdo;
            delete actual;
            return aux;
        }
        // nodo con dos hijos
        NodoABBBicicletas* sucesor = buscarMenor(actual->derecho);
        actual->dato = sucesor->dato;
        actual->derecho =
            eliminarRecursivo(
                actual->derecho,
                sucesor->dato.getBiciId()
            );
    }
    return actual;
}
NodoABBBicicletas* AbbBicicletas::buscarMenor(
    NodoABBBicicletas* actual) {
    while (actual->izquierdo != nullptr) {
        actual = actual->izquierdo;
    }
    return actual;
}