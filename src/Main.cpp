#include <iostream>
#include "Viaje.h"
#include "ListaViajes.h"
#include "Bicicleta.h"
#include "ListaBicicletas.h"
#include "ColaPrioridad.h"
#include "ColaEspera.h"
using namespace std;

int main(){
    ListaViajes pruebaLista;
    ListaBicicletas pruebaBicicletas;
    ColaPrioridadBicicletas  primeraPruebaCola(10); // para probar si funciona

    // PRUEBA COLA DE ESPERA
    ColaEspera colaPrueba;
    colaPrueba.encolar(301);
    colaPrueba.encolar(302);
    colaPrueba.encolar(303);

    

    cout << "Primer usuario: " << colaPrueba.desencolar() << endl;
    cout << "Segundo usuario: " << colaPrueba.desencolar() << endl;
    cout << "Tercer usuario: " << colaPrueba.desencolar() << endl;

    cout << "¿La cola esta vacia? " << colaPrueba.estaVacia() << endl;

    // UNICO USUARIO EN LA COLA
    ColaEspera pruebaColaUnico;
    pruebaColaUnico.encolar(401);

    cout<<"Usuario desencolado: " << pruebaColaUnico.desencolar()<<endl;
    cout<<"Esta vacia?" << pruebaColaUnico.estaVacia() << endl;

    pruebaColaUnico.encolar(402);
    cout<<"Nuevo desencolado" << pruebaColaUnico.desencolar() <<endl;
    cout<<"esta vacia al final?" << pruebaColaUnico.estaVacia()<<endl;


    // PRUEBA SI LA COLA ESTA LLENA ¿QUE SUCEDE?
    ColaPrioridadBicicletas pruebaColaLlena(2);

    Viaje primerViaje(23,501,30123456,"PLZ","PAL",20260310,25);
    Viaje segundoViaje(9002,502,27654321,"PAL","CAB",20260311,40);


    Bicicleta primerBicicleta(501,"PLZ","Mecanica","OK",1240);
    Bicicleta segundaBicicleta(502,"PAL","Electrica","Averiada",3810);
    Bicicleta tercerBicicleta(503, "CAB", "Mecanica", "Averiada", 6000);
    Bicicleta cuartaBicicleta(504, "PLZ", "Electrica", "Averiada", 2000);

    pruebaLista.agregarViaje(primerViaje);
    pruebaLista.agregarViaje(segundoViaje);
    pruebaBicicletas.agregarBicicleta(primerBicicleta);
    pruebaBicicletas.agregarBicicleta(segundaBicicleta);

    primeraPruebaCola.insertarUnaBici(segundaBicicleta);
    primeraPruebaCola.insertarUnaBici(tercerBicicleta);
    primeraPruebaCola.insertarUnaBici(cuartaBicicleta);
    primeraPruebaCola.insertarUnaBici(primerBicicleta); // pruebo
    // para ver si la cola de prioridad la rechaza

    // ------- COLA LLENA -------------
    pruebaColaLlena.insertarUnaBici(segundaBicicleta);
    pruebaColaLlena.insertarUnaBici(tercerBicicleta);
    pruebaColaLlena.insertarUnaBici(cuartaBicicleta);

    Bicicleta biciPrueba(999, "TEST", "Mecanica", "OK", 0);
    while(pruebaColaLlena.extraerBicicletaConMayorPrioridad(biciPrueba)){
        cout << "Extraida de cola chica: " << biciPrueba.getBiciId() << endl;
    }


    // ------------- PRUEBA SI FUNCIONA LA COLA DE PRIORIDAD --------------
    Bicicleta biciExtraida(999, "TEST", "Mecanica", "OK", 0);
    while(primeraPruebaCola.extraerBicicletaConMayorPrioridad(biciExtraida)){
        cout<<"Bicicleta extraida : " << biciExtraida.getBiciId() << endl;
    }

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