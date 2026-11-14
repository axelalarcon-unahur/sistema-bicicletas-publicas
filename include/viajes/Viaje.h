#ifndef VIAJE_H
#define VIAJE_H
#include <string>

using namespace std;

class Viaje {
private:
    int idViaje; 
    int idBicicleta; 
    int dniUser; 
    string estacionDeOrigen; 
    string estacionDestino; 
    int fecha; 
    int duracionMin; 

public:
    Viaje(int idViaje, int idBicicleta, int dniUser,
          string estacionDeOrigen, string estacionDestino,
          int fecha, int duracionMin);
    int getViajeId(); 
    int getBiciId();
    int getDniUsuario();
    string getEstacionDeOrigen();
    string getEstacionDestino();
    int getFecha();
    int getDuracionMin();
};
#endif