#include <iostream>
#include "Viaje.h"
#include "ListaViajes.h"
#include "Bicicleta.h"
#include "ListaBicicletas.h"
#include "ColaPrioridad.h"
#include "ColaEspera.h"

using namespace std;

int main() {

   /*------------ESTRUCTURAS LISTAS Y COLAS------------ */
    ListaViajes listaViajes;
    ListaBicicletas listaBicicletas;
    ColaPrioridadBicicletas colaPrioridad(10);
    ColaPrioridadBicicletas colaPrioridadChica(2);
    /* ---------- DATOS PARA PROBARRR ------------*/
    Viaje primerViaje(23, 501, 30123456, "PLZ", "PAL", 20260310, 25);
    Viaje segundoViaje(9002, 502, 27654321, "PAL", "CAB", 20260311, 40);
    Bicicleta primerBicicleta(501, "PLZ", "Mecanica", "OK", 1240);
    Bicicleta segundaBicicleta(502, "PAL", "Electrica", "Averiada", 3810);
    Bicicleta tercerBicicleta(503, "CAB", "Mecanica", "Averiada", 6000);
    Bicicleta cuartaBicicleta(504, "PLZ", "Electrica", "Averiada", 2000);
    /*-----CARGO LAS LISTAS-----------*/
    listaViajes.agregarViaje(primerViaje);
    listaViajes.agregarViaje(segundoViaje);
    listaBicicletas.agregarBicicleta(primerBicicleta);
    listaBicicletas.agregarBicicleta(segundaBicicleta);
    listaBicicletas.agregarBicicleta(tercerBicicleta);
    listaBicicletas.agregarBicicleta(cuartaBicicleta);
   
    /* CANT DE VIAJES POR ESTACION*/
    int cantidadDeViajes = listaViajes.cantViajesPorEstacion(
        "PLZ", 20260301, 20260315
    );
    cout << " VIAJES POR ESTACION" << endl;
    cout << "Cantidad de viajes desde PLZ: "
         << cantidadDeViajes << endl;
    
    /* CANT MINUTOS PEDALEADOS POR USUARIO*/
    int dni;
    cout << "MINUTOS PEDALEADOS POR UN USUARIO:"  << endl;
    cout << "Ingrese el DNI del usuario: ";
    cin >> dni;
    int minutos = listaViajes.minutosPedaleadosPorUsuarioSegunViajes(dni);
    cout << "Total de minutos: "
         << minutos << endl;
    
    /* BICICLETAS CON MAS DE X(INGRESADO POR USUARIO) KM*/
    int kilometros;
    cout << "BICICLETAS CON MAS DE X KM " << endl;
    cout << "Ingrese la cantidad de kilometros: ";
    cin >> kilometros;
    listaBicicletas.cantBicicletasSuperadasPorKm(kilometros);

    /* COLA ESPERA*/
    cout << " PRUEBA CON COLA DE ESPERA" << endl;
    ColaEspera colaEspera;
    colaEspera.encolar(301);
    colaEspera.encolar(302);
    colaEspera.encolar(303);
    cout << "Primer usuario: " << colaEspera.desencolar() << endl;
    cout << "Segundo usuario: " << colaEspera.desencolar() << endl;
    cout << "Tercer usuario: " << colaEspera.desencolar() << endl;
    cout << "¿La cola esta vacia? "
         << colaEspera.estaVacia() << endl;
   
    // PRUEBA COLA CON UN SOLO USUARIO
    ColaEspera colaUnUsuario;
    colaUnUsuario.encolar(401);
    cout << "Usuario desencolado: "
         << colaUnUsuario.desencolar() << endl;
    cout << "¿Esta vacia? "
         << colaUnUsuario.estaVacia() << endl;
    colaUnUsuario.encolar(402);
    cout << "Nuevo usuario desencolado: "
         << colaUnUsuario.desencolar() << endl;
    cout << "¿Esta vacia al final? "
         << colaUnUsuario.estaVacia() << endl;


    /* COLA DE PRIORIDAD*/
    cout << " PRUEBA COLA DE PRIORIDAD" << endl;
    colaPrioridad.insertarUnaBici(segundaBicicleta);
    colaPrioridad.insertarUnaBici(tercerBicicleta);
    colaPrioridad.insertarUnaBici(cuartaBicicleta);
    colaPrioridad.insertarUnaBici(primerBicicleta);
    Bicicleta biciExtraida(999, "TEST", "Mecanica", "OK", 0);
    while (colaPrioridad.extraerBicicletaConMayorPrioridad(biciExtraida)) {
        cout << "Bicicleta extraida: "
             << biciExtraida.getBiciId() << endl;
    }
    // PRUEBA DE CAPACIDAD MAXIMA
    cout << " PRUEBA COLA LLENA "<< endl;
    colaPrioridadChica.insertarUnaBici(segundaBicicleta);
    colaPrioridadChica.insertarUnaBici(tercerBicicleta);
    colaPrioridadChica.insertarUnaBici(cuartaBicicleta);
    while (colaPrioridadChica.extraerBicicletaConMayorPrioridad(biciExtraida)) {
        cout << "Bicicleta extraida de cola chica: "
             << biciExtraida.getBiciId() << endl;
    }

    return 0;
}