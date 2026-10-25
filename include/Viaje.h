// Declaramos la clase viaje --> viaje individual
//#ifndef VIAJE_H
//#define VIAJE_H

#include <string>
using namespace std;

class Viaje {
private:
    int idViaje; // identificador de viaje
    int idBicicleta; // id de la bicicleta
    string dniUser; // dni del usuario --> que la utiliza
    string estacionDeOrigen; // codigo de la estacion de salida 
    string estacionDestino; // codigo de la estacion a la que voy
    int fecha; // fecha del viaje
    int duracionMin; // la duracion del viaje

public:
    // CONSTRUCTOR ---> PARA CREAR EL OBJETO
    Viaje(int viajeId, int biciId, string dniUsuario,
          string estacionOrigen, string estacionDestino,
          int fecha, int duracionMin);
    
    int getViajeId(); // permite consultar los datos privados.
    int getBiciId();
    string getDniUsuario();
    string getEstacionDeOrigen();
    string getEstacionDestino();
    int getFecha();
    int getDuracionMin();
};
//#endif
