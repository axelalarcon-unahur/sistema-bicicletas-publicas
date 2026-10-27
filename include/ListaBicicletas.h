#include "Bicicleta.h"

struct NodoBicicleta {
    Bicicleta dato; 
    NodoBicicleta* siguiente; 
    NodoBicicleta(Bicicleta bici);
};
class ListaBicicletas {
private:
    NodoBicicleta* primero; 
public:
    ListaBicicletas(); 
    ~ListaBicicletas();
    void agregarBicicleta(Bicicleta bici); 
    ListaBicicletas cantBicicletasSuperadasPorKm(int kilometros);
};
