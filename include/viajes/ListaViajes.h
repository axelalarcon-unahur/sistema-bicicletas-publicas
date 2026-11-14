#include "viajes/Viaje.h"
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
    ListaViajes(); 
    ~ListaViajes(); 
    void agregarViaje(Viaje viaje); 
    int cantViajesPorEstacion(string codigoEstacion, int fechaInicial, int fechaFin);
    int minutosPedaleadosPorUsuarioSegunViajes(int dniUsuario);
};
