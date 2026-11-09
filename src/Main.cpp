#include <iostream>
#include "Viaje.h"
#include "ListaViajes.h"
#include "Bicicleta.h"
#include "ListaBicicletas.h"
#include "ColaPrioridad.h"
#include "ColaEspera.h"
#include "AbbBicicletas.h"

using namespace std;

int main() {

   /*------------ESTRUCTURAS LISTAS Y COLAS------------ */
    ListaViajes listaViajes;
    ListaBicicletas listaBicicletas;
    ColaPrioridadBicicletas colaPrioridad(10);
    ColaPrioridadBicicletas colaPrioridadChica(2);
     /* ESTRUCTURA ARBOL*/
     AbbBicicletas arbolPrimerPrueba; // para probar el arbol
     AbbBicicletas arbolOrdenado;

    /* ---------- DATOS PARA PROBARRR ------------*/
    Viaje primerViaje(23, 501, 30123456, "PLZ", "PAL", 20260310, 25);
    Viaje segundoViaje(9002, 502, 27654321, "PAL", "CAB", 20260311, 40);
    Bicicleta primerBicicleta(501, "PLZ", "Mecanica", "OK", 1240);
    Bicicleta segundaBicicleta(502, "PAL", "Electrica", "Averiada", 3810);
    Bicicleta tercerBicicleta(503, "CAB", "Mecanica", "Averiada", 6000);
    Bicicleta cuartaBicicleta(504, "PLZ", "Electrica", "Averiada", 2000);

    /*  BICICLETAS NUEVAS PARA EL ARBOL ORDENADO*/
     Bicicleta bici1(100, "PLZ", "Mecanica", "OK", 1000);
     Bicicleta bici2(200, "PAL", "Mecanica", "OK", 2000);
     Bicicleta bici3(300, "CAB", "Electrica", "OK", 3000);
     Bicicleta bici4(400, "PLZ", "Mecanica", "Averiada", 4000);
     Bicicleta bici5(500, "PAL", "Electrica", "OK", 5000);

    /*-----CARGO LAS LISTAS-----------*/
    listaViajes.agregarViaje(primerViaje);
    listaViajes.agregarViaje(segundoViaje);
    listaBicicletas.agregarBicicleta(primerBicicleta);
    listaBicicletas.agregarBicicleta(segundaBicicleta);
    listaBicicletas.agregarBicicleta(tercerBicicleta);
    listaBicicletas.agregarBicicleta(cuartaBicicleta);
     /* CARGO EL ARBOL*/
     // desordendas para probar que el arbol pueda acomodarla.
     arbolPrimerPrueba.insertarUnaBicicleta(tercerBicicleta);
     arbolPrimerPrueba.insertarUnaBicicleta(primerBicicleta);
     arbolPrimerPrueba.insertarUnaBicicleta(cuartaBicicleta);
     arbolPrimerPrueba.insertarUnaBicicleta(segundaBicicleta);

     /* CARGO EL ARBOL ORDENADO*/
     arbolOrdenado.insertarUnaBicicleta(bici1);
     arbolOrdenado.insertarUnaBicicleta(bici2);
     arbolOrdenado.insertarUnaBicicleta(bici3);
     arbolOrdenado.insertarUnaBicicleta(bici4);
     arbolOrdenado.insertarUnaBicicleta(bici5);

     /* PRUEBO SI PUEDE CALCULAR LA ALTURA*/
     cout << "Altura del arbol ordenado: " << arbolOrdenado.calcularAlturaArbol() << endl;
     // Busco bicicleta por ID
     cout<<"Buscar Bicicleta" << endl;
     arbolPrimerPrueba.buscarBici(502);
     // listo las bicicletas ordenadas por id
     cout<< "Bicicletas ordenadas por ID "<< endl;
     arbolPrimerPrueba.listarBicicletasInOrden();
     //cant de bicis averiadas
     cout<<"Cant bicicletas averiadas :" << arbolPrimerPrueba.cantBicicletasAveriadas() << endl;
     // altura del arbol
     cout<<"La altura del arbol es :"<< arbolPrimerPrueba.calcularAlturaArbol() << endl;

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