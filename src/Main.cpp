#include <iostream>
#include "viajes/Viaje.h"
#include "viajes/ListaViajes.h"
#include "bicicletas/Bicicleta.h"
#include "bicicletas/ListaBicicletas.h"
#include "colas/ColaPrioridad.h"
#include "colas/ColaEspera.h"
#include "bicicletas/AbbBicicletas.h"
#include "estaciones/GestorEstaciones.h"

using namespace std;
// ----------  BICICLETAS ----------
void menuBicicletas(ListaBicicletas& listaBicicletas,
                    AbbBicicletas& arbol,
                    AbbBicicletas& arbolOrdenado) {
    int opcionElegida;
    do {
        cout << "\n===== GESTION DE BICICLETAS =====" << endl;
        cout << "1. Mostrar bicicletas con mas de X kilometros" << endl;
        cout << "2. Buscar bicicleta mediante ID" << endl;
        cout << "3. Listar bicicletas ordenadas por ID" << endl;
        cout << "4. Cantidad de bicicletas averiadas" << endl;
        cout << "5. Calcular altura del arbol" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcionElegida;
        switch (opcionElegida) {
            case 1: {
                int kilometros;
                cout << "Ingrese la cantidad de kilometros: ";
                cin >> kilometros;
                listaBicicletas.cantBicicletasSuperadasPorKm(kilometros);
                break;
            }
            case 2: {
                int id;
                cout << "Ingrese el ID de la bicicleta: ";
                cin >> id;
                arbol.buscarBici(id);
                break;
            }
            case 3:
                arbol.listarBicicletasInOrden();
                break;
            case 4:
                cout << "Cantidad de bicicletas averiadas: "
                     << arbol.cantBicicletasAveriadas() << endl;
                break;
            case 5:
                cout << "Altura arbol: "
                     << arbol.calcularAlturaArbol() << endl;
                cout << "Altura arbol ordenado: "
                     << arbolOrdenado.calcularAlturaArbol() << endl;
                break;
            case 0:
                cout << "Volviendo al menu principal..." << endl;
                break;
            default:
                cout << "Opcion incorrecta" << endl;
        }
    } while (opcionElegida != 0);
}

// ----------  VIAJES ----------
void menuViajes(ListaViajes& listaViajes) {
    int opcionElegida;
    do {
        cout << "\n===== GESTION DE VIAJES =====" << endl;
        cout << "1. Cantidad de viajes por estacion y rango de fechas" << endl;
        cout << "2. Minutos pedaleados por usuario" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcionElegida;
        switch (opcionElegida) {
            case 1: {
                string codigo;
                int fechaInicial, fechaFinal;

                cout << "Ingrese el codigo de la estacion: ";
                cin >> codigo;
                cout << "Ingrese la fecha inicial (AAAAMMDD): ";
                cin >> fechaInicial;
                cout << "Ingrese la fecha final (AAAAMMDD): ";
                cin >> fechaFinal;

                int cantidad = listaViajes.cantViajesPorEstacion(
                    codigo, fechaInicial, fechaFinal
                );
                cout << "Cantidad de viajes: " << cantidad << endl;
                break;
            }
            case 2: {
                int dni;
                cout << "Ingrese el DNI del usuario: ";
                cin >> dni;
                int minutos =
                    listaViajes.minutosPedaleadosPorUsuarioSegunViajes(dni);
                cout << "Total minutos: " << minutos << endl;
                break;
            }
            case 0:
                cout << "Volviendo al menu principal..." << endl;
                break;
            default:
                cout << "Opcion incorrecta" << endl;
        }
    } while (opcionElegida != 0);
}
// ----------  COLAS ----------
void menuColas(const Bicicleta& primeraBicicleta,
               const Bicicleta& segundaBicicleta,
               const Bicicleta& tercerBicicleta,
               const Bicicleta& cuartaBicicleta) {
    int opcionElegida;
    do {
        cout << "\n===== GESTION DE COLAS =====" << endl;
        cout << "1. Probar cola de espera" << endl;
        cout << "2. Probar cola de prioridad" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcionElegida;
        switch (opcionElegida) {
            case 1: {
                ColaEspera colaEspera;
                colaEspera.encolar(301);
                colaEspera.encolar(302);
                colaEspera.encolar(303);
                cout << "Primer usuario: " << colaEspera.desencolar() << endl;
                cout << "Segundo usuario: " << colaEspera.desencolar() << endl;
                cout << "Tercer usuario: " << colaEspera.desencolar() << endl;
                cout << "¿La cola esta vacia? "
                     << colaEspera.estaVacia() << endl;
                ColaEspera colaUnUsuario;
                colaUnUsuario.encolar(401);
                cout << "Usuario desencolado: "
                     << colaUnUsuario.desencolar() << endl;
                colaUnUsuario.encolar(402);
                cout << "Nuevo usuario desencolado: "
                     << colaUnUsuario.desencolar() << endl;
                break;
            }
            case 2: {
                ColaPrioridadBicicletas colaPrioridad(10);
                ColaPrioridadBicicletas colaPrioridadChica(2);
                colaPrioridad.insertarUnaBici(segundaBicicleta);
                colaPrioridad.insertarUnaBici(tercerBicicleta);
                colaPrioridad.insertarUnaBici(cuartaBicicleta);
                colaPrioridad.insertarUnaBici(primeraBicicleta);
                Bicicleta biciExtraida(999, "TEST", "Mecanica", "OK", 0);
                cout << "Extraccion de la cola de prioridad:" << endl;
                while (colaPrioridad.extraerBicicletaConMayorPrioridad(
                    biciExtraida)) {
                    cout << "Bicicleta extraida: "
                         << biciExtraida.getBiciId() << endl;
                }
                cout << "Prueba de capacidad maxima:" << endl;
                colaPrioridadChica.insertarUnaBici(segundaBicicleta);
                colaPrioridadChica.insertarUnaBici(tercerBicicleta);
                colaPrioridadChica.insertarUnaBici(cuartaBicicleta);
                while (colaPrioridadChica.extraerBicicletaConMayorPrioridad(
                    biciExtraida)) {
                    cout << "Bicicleta extraida: "
                         << biciExtraida.getBiciId() << endl;
                }
                break;
            }
            case 0:
                cout << "Volviendo al menu principal..." << endl;
                break;
            default:
                cout << "Opcion incorrecta" << endl;
        }
    } while (opcionElegida != 0);
}
// ---------- ESTACIONES ----------
void menuEstaciones(GestorEstaciones& gestor) {
    int opcionElegida;
    do {
        cout << "\n===== GESTION DE ESTACIONES =====" << endl;
        cout << "1. Buscar una estacion" << endl;
        cout << "2. Agregar estacion" << endl;
        cout << "3. Ordenar estaciones por capacidad" << endl;
        cout << "4. Ordenar estaciones por bicicletas disponibles" << endl;
        cout << "5. Mostrar estaciones con ocupacion baja" << endl;
        cout << "6. Buscar camino mas corto" << endl;
        cout << "7. Mostrar el total de colisiones" << endl;
        cout << "8. Mostrar factor de carga" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcionElegida;
        switch (opcionElegida) {
            case 1: {
                string codigo;
                cout << "Ingrese el codigo de la estacion: ";
                cin >> codigo;
                gestor.mostrarInformacion(codigo);
                break;
            }
            case 2: {
                string codigo, nombre, barrio;
                int capacidad, bicicletas;
                cout << "Ingresa el codigo: ";
                cin >> codigo;
                cout << "Ingresa el nombre: ";
                cin >> nombre;
                cout << "Ingresa el barrio: ";
                cin >> barrio;
                cout << "Ingresa la capacidad de anclajes: ";
                cin >> capacidad;
                cout << "Ingresa las bicicletas disponibles: ";
                cin >> bicicletas;
                if (capacidad <= 0 || bicicletas < 0 ||
                    bicicletas > capacidad) {
                    cout << "Datos de capacidad o bicicletas incorrectos"
                         << endl;
                    break;
                }
                Estacion* nuevaEstacion = new Estacion(
                    codigo, nombre, barrio, capacidad, bicicletas
                );
                gestor.agregarEstacion(nuevaEstacion);
                cout << "Estacion agregada." << endl;
                break;
            }
            case 3:
                gestor.estacionesOrdenadasPorCapacidad();
                break;
            case 4:
                gestor.estacionesOrdenadasPorDisponibilidad();
                break;
            case 5:
                gestor.estacionesConOcupacionBaja();
                break;
            case 6: {
                string origen, destino;
                cout << "Ingrese el codigo de la estacion de origen: ";
                cin >> origen;
                cout << "Ingrese el codigo de la estacion de destino: ";
                cin >> destino;
                gestor.caminoMasCorto(origen, destino);
                break;
            }
            case 7:
                gestor.totalColisiones();
                break;
            case 8:
                gestor.factorDeCarga();
                break;
            case 0:
                cout << "Volviendo al menu principal..." << endl;
                break;
            default:
                cout << "Opcion incorrecta." << endl;
        }
    } while (opcionElegida != 0);
}
// ---------- REDISTRIBUCION ----------
void menuRedistribucion(GestorEstaciones& gestor) {
    string estaciones[5] = {"ABC", "BCA", "TAZ", "ZTA", "FJA"};
    int capacidadCamion;

    cout << "\n===== REDISTRIBUCION DE BICICLETAS =====" << endl;
    cout << "Estaciones consideradas: ABC, BCA, TAZ, ZTA, FJA" << endl;
    cout << "Ingrese la capacidad del camion: ";
    cin >> capacidadCamion;
    gestor.mostrarRestribucionBicicletas(
        estaciones, 5, capacidadCamion
    );
}
/*CARGO LAS ESTACIONES*/
void cargarEstacionesPrueba(GestorEstaciones& gestor) {
    gestor.agregarEstacion(new Estacion("ABC", "Estacion 1", "A", 50, 47));
    gestor.agregarEstacion(new Estacion("BCA", "Estacion 2", "A", 50, 43));
    gestor.agregarEstacion(new Estacion("TAZ", "Estacion 3", "A", 50, 45));
    gestor.agregarEstacion(new Estacion("ZTA", "Estacion 4", "A", 50, 48));
    gestor.agregarEstacion(new Estacion("FJA", "Estacion 5", "A", 50, 45));
    gestor.agregarEstacion(new Estacion("ZED", "Estacion 6", "A", 50, 50));
    gestor.agregarEstacion(new Estacion("ZEN", "Estacion 7", "A", 50, 50));
    gestor.agregarEstacion(new Estacion("DEC", "Estacion 8", "A", 50, 50));
    gestor.agregarEstacion(new Estacion("MAT", "Estacion 9", "A", 50, 50));
    gestor.agregarEstacion(new Estacion("LOL", "Estacion 10", "A", 50, 50));
    gestor.agregarEstacion(new Estacion("UNR", "Estacion 11", "A", 50, 50));
    // CICLOVIAS
    gestor.agregarCiclovia("ABC", "BCA");
    gestor.agregarCiclovia("ABC", "ZED");
    gestor.agregarCiclovia("ABC", "TAZ");
    gestor.agregarCiclovia("BCA", "DEC");
    gestor.agregarCiclovia("TAZ", "ZTA");
    gestor.agregarCiclovia("TAZ", "DEC");
    gestor.agregarCiclovia("TAZ", "LOL");
    gestor.agregarCiclovia("ZTA", "FJA");
    gestor.agregarCiclovia("ZTA", "ZEN");
    gestor.agregarCiclovia("FJA", "ZED");
    gestor.agregarCiclovia("DEC", "MAT");
}
// ---------- MENU PRINCIPAL ----------
int main() {
    // ESTRUCTURA
    ListaViajes listaViajes;
    ListaBicicletas listaBicicletas;
    AbbBicicletas arbolPrimerPrueba;
    AbbBicicletas arbolOrdenado;
    GestorEstaciones gestorEstaciones(11);
    cargarEstacionesPrueba(gestorEstaciones);
    // DATOS DE PRUEBA
    Viaje primerViaje(23, 501, 30123456, "PLZ", "PAL", 20260310, 25);
    Viaje segundoViaje(9002, 502, 27654321, "PAL", "CAB", 20260311, 40);
    Bicicleta primerBicicleta(501, "PLZ", "Mecanica", "OK", 1240);
    Bicicleta segundaBicicleta(502, "PAL", "Electrica", "Averiada", 3810);
    Bicicleta tercerBicicleta(503, "CAB", "Mecanica", "Averiada", 6000);
    Bicicleta cuartaBicicleta(504, "PLZ", "Electrica", "Averiada", 2000);
    Bicicleta bici1(100, "PLZ", "Mecanica", "OK", 1000);
    Bicicleta bici2(200, "PAL", "Mecanica", "OK", 2000);
    Bicicleta bici3(300, "CAB", "Electrica", "OK", 3000);
    Bicicleta bici4(400, "PLZ", "Mecanica", "Averiada", 4000);
    Bicicleta bici5(500, "PAL", "Electrica", "OK", 5000);
    // CARGA DE LISTAS
    listaViajes.agregarViaje(primerViaje);
    listaViajes.agregarViaje(segundoViaje);
    listaBicicletas.agregarBicicleta(primerBicicleta);
    listaBicicletas.agregarBicicleta(segundaBicicleta);
    listaBicicletas.agregarBicicleta(tercerBicicleta);
    listaBicicletas.agregarBicicleta(cuartaBicicleta);
    // CARGA DE ARBOLES
    arbolPrimerPrueba.insertarUnaBicicleta(tercerBicicleta);
    arbolPrimerPrueba.insertarUnaBicicleta(primerBicicleta);
    arbolPrimerPrueba.insertarUnaBicicleta(cuartaBicicleta);
    arbolPrimerPrueba.insertarUnaBicicleta(segundaBicicleta);
    arbolOrdenado.insertarUnaBicicleta(bici1);
    arbolOrdenado.insertarUnaBicicleta(bici2);
    arbolOrdenado.insertarUnaBicicleta(bici3);
    arbolOrdenado.insertarUnaBicicleta(bici4);
    arbolOrdenado.insertarUnaBicicleta(bici5);
    // MENU PRINCIPAL
    int opcionElegida;
    do {
        cout << "\n===== SISTEMA DE BICICLETAS PUBLICAS =====" << endl;
        cout << "1. Gestion de  bicicletas" << endl;
        cout << "2. Gestion de viajes" << endl;
        cout << "3. Gestion de colas" << endl;
        cout << "4. Gestion de estaciones" << endl;
        cout << "5. Redistribucion de bicicletas" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcionElegida;
        switch (opcionElegida) {
            case 1:
                menuBicicletas(listaBicicletas, arbolPrimerPrueba,
                               arbolOrdenado);
               break;
            case 2:
                menuViajes(listaViajes);
               break;
            case 3:
                menuColas(primerBicicleta, segundaBicicleta,
                          tercerBicicleta, cuartaBicicleta);
               break;
            case 4:
                    menuEstaciones(gestorEstaciones);
               break;
            case 5:
                    menuRedistribucion(gestorEstaciones);
               break;
            case 0:
                cout << "Saliendo del sistema..." << endl;
               break;
            default:
                cout << "Opcion incorrecta, Intente nuevamente." << endl;
        }
    } while (opcionElegida != 0);
    return 0;
}
