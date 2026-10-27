#include <iostream>
#include "Viaje.h"
#include "ListaViajes.h"
#include "Bicicleta.h"
#include "ListaBicicletas.h"

using namespace std;

int main(){
    ListaViajes pruebaLista;
    ListaBicicletas pruebaBicicletas;

    Viaje primerViaje(23,501,30123456,"PLZ","PAL",20260310,25);
    Viaje segundoViaje(9002,502,27654321,"PAL","CAB",20260311,40);


    Bicicleta primerBicicleta(501,"PLZ","Mecanica","OK",1240);
    Bicicleta segundaBicicleta(502,"PAL","Electrica","Averiada",3810);

    pruebaLista.agregarViaje(primerViaje);
    pruebaLista.agregarViaje(segundoViaje);
    pruebaBicicletas.agregarBicicleta(primerBicicleta);
    pruebaBicicletas.agregarBicicleta(segundaBicicleta);


    /// ------------- FUNCIONA -------------------------
    int cantidadDeViajes = pruebaLista.cantViajesPorEstacion("PLZ",20260301,20260315);
    cout<<"Cantidad de viajes desde PLZ :" << cantidadDeViajes <<endl;


    /// ------------- FUNCIONA --------------------------
    int cantidadMinutos = pruebaLista.calcularMinutosPorUsuario(30123456);
    cout<<"Cantidad de minutos :" << cantidadMinutos <<endl;

    /// ------------- FUNCIONA ------------------------
    cout<< "Exito en agregar los viajes" << endl;
    cout<< "Exito en agregar las bicicletas" << endl;

    return 0;
}