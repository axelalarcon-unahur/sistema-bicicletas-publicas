#ifndef AbbBicicletas_h
#define AbbBicicletas_h
#include "Bicicleta.h"

struct NodoABBBicicletas{
    Bicicleta dato;
    NodoABBBicicletas* izquierdo;
    NodoABBBicicletas* derecho;
    NodoABBBicicletas(Bicicleta unaBici);
};
class AbbBicicletas{
private:
    NodoABBBicicletas* raiz;
    void insertarRecursivo(NodoABBBicicletas*& actual, Bicicleta unaBici);
    void busquedaYMuestroRecursivo(NodoABBBicicletas* actual, int id);
    void listarInOrdenRecursivo(NodoABBBicicletas* actual);
    int contarBicicletasAveriadas(NodoABBBicicletas* actual);
    int alturaArbol(NodoABBBicicletas* actual);
    void liberarPostOrden(NodoABBBicicletas* actual);
public:
    void insertarUnaBicicleta(Bicicleta unaBici);
    void buscarBici(int id);
    void listarBicicletasInOrden();
    int cantBicicletasAveriadas();
    int calcularAlturaArbol();
    AbbBicicletas();
    ~AbbBicicletas();
};
#endif