#include <string>

using namespace std;

class Viaje {
private:
    int idViaje; 
    int idBicicleta; 
    string dniUser; 
    string estacionDeOrigen; 
    string estacionDestino; 
    int fecha; 
    int duracionMin; 

public:
    Viaje(int idViaje, int idBicicleta, string dniUser,
          string estacionDeOrigen, string estacionDestino,
          int fecha, int duracionMin);
    int getViajeId(); 
    int getBiciId();
    string getDniUsuario();
    string getEstacionDeOrigen();
    string getEstacionDestino();
    int getFecha();
    int getDuracionMin();
};
