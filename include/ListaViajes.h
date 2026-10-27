#include "Viaje.h"
#include <string>

struct NodoViaje {
    Viaje dato; 
    NodoViaje* siguiente; 
    NodoViaje(Viaje viaje);
};
class ListaViajes {
private:
    NodoViaje* primero; 
public:
    ListaViajes(); // contructor
    ~ListaViajes(); // lo utilizamos para liberar memoria
    void agregarViaje(Viaje viaje); 
    int cantViajesPorEstacion(string codigoEstacion, int fechaInicial, int fechaFin);
    int calcularMinutosPorUsuario(int dniUser); 
    ListaViajes viajesHechosPorUnUserConDni(int dni);
};
