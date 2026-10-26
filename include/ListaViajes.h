//  declaramos la lista enlazada que va a almacenar los viajes
#include "Viaje.h"

struct NodoViaje {
    Viaje dato; // almacenamos el objeto de tipo viaje
    NodoViaje* siguiente; // apunto hacia el siguiente viaje
    NodoViaje(Viaje viaje);
};
class ListaViajes {
private:
    NodoViaje* primero; // primer nodo de la lista
public:
    ListaViajes(); // contructor
    ~ListaViajes(); // lo utilizamos para liberar memoria
    void agregarViaje(Viaje viaje); //incorporo viajes a la lista
    // ------ METODOS --------------
    int cantViajesPorEstacion(string codigoEstacion, int fechaInicial, int fechaFin);
    int calcularMinutosPorUsuario(string dniUser); 
};
