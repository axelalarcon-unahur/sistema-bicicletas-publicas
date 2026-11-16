#include <iostream>
#include "viajes/Viaje.h"
#include "viajes/ListaViajes.h"
#include "bicicletas/Bicicleta.h"
#include "bicicletas/ListaBicicletas.h"
#include "colas/ColaPrioridad.h"
#include "colas/ColaEspera.h"
#include "bicicletas/AbbBicicletas.h"
#include "estaciones/GestorEstaciones.h"
#include "lector/LectorArchivos.h"

using namespace std;
// ----------  BICICLETAS ----------
void menuBicicletas(AbbBicicletas& arbol) {
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
                // arbol.bicicletasSuperadasPorKm(kilometros);
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
    int capacidadCamion;
    int cantidadEstaciones;
    int i = 1;

    cout << "\n===== REDISTRIBUCION DE BICICLETAS =====" << endl;
    cout << "Ingrese la cantidad de estaciones a las cuales redistribuir bicicletas: ";
    cin >> cantidadEstaciones;
    cout << "Ingrese la capacidad del camion: ";
    cin >> capacidadCamion;
    string* codigos = new string[capacidadCamion];

    do {
        string aux;
        cout << "Ingrese el código de la estación número " << i << ". ";
        cin >> aux;
        i++;
    } while (i <= capacidadCamion);

    gestor.mostrarRestribucionBicicletas(codigos, cantidadEstaciones, capacidadCamion);
    delete[] codigos;
}

// ---------- MENU PRINCIPAL ----------
int main() {
    GestorEstaciones gestorEstaciones = GestorEstaciones(11);
    AbbBicicletas arbol = AbbBicicletas();
    ListaViajes listaViajes = ListaViajes();
    LectorArchivos lector = LectorArchivos(&gestorEstaciones, &arbol, &listaViajes);
    lector.leerArchivos();

    int opcionElegida;
    do {
        cout << "\n===== SISTEMA DE BICICLETAS PUBLICAS =====" << endl;
        cout << "1. Gestion de bicicletas" << endl;
        cout << "2. Gestion de viajes" << endl;
        cout << "3. Gestion de colas" << endl;
        cout << "4. Gestion de estaciones" << endl;
        cout << "5. Redistribucion de bicicletas" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcionElegida;
        switch (opcionElegida) {
            case 1:
                menuBicicletas(arbol);
               break;
            case 2:
                menuViajes(listaViajes);
               break;
            case 3:
                /* menuColas(primerBicicleta, segundaBicicleta,
                          tercerBicicleta, cuartaBicicleta); */
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
