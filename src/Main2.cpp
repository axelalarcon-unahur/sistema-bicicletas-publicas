#include <iostream>
#include "viajes/Viaje.h"
#include "viajes/ListaViajes.h"
#include "bicicletas/Bicicleta.h"
#include "colas/ColaPrioridad.h"
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
        cout << "3. Agregar bicicleta" << endl;
        cout << "4. Listar bicicletas ordenadas por ID" << endl;
        cout << "5. Cantidad de bicicletas averiadas" << endl;
        cout << "6. Calcular altura del arbol" << endl;
        cout << "7. Eliminar bicicleta por ID" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcionElegida;
        switch (opcionElegida) {
            case 1: {
                int kilometros;
                cout << "Ingrese la cantidad de kilometros: ";
                cin >> kilometros;
                arbol.bicicletasConMasDeXKm(kilometros);
                break;
            }
            case 2: {
                int id;
                cout << "Ingrese el ID de la bicicleta: ";
                cin >> id;
                arbol.buscarBici(id);
                break;
            }
            case 3: {
                string codigo, tipo, estado;
                int biciId, kilometros;
                cout << "Ingresa el id: ";
                cin >> biciId;
                cout << "Ingresa el codigo de estación: ";
                cin >> codigo;
                cout << "Ingresa el tipo: ";
                cin >> tipo;
                cout << "Ingresa el estado: ";
                cin >> estado;
                cout << "Ingresa los kilometros recorridos: ";
                cin >> kilometros;
                if (kilometros < 0) {
                    cout << "Los kilómetros no pueden ser negativos" << endl;
                    break;
                }
                arbol.insertarUnaBicicleta(Bicicleta(biciId, codigo, tipo, estado, kilometros));
                break;
            }
            case 4:
                arbol.listarBicicletasInOrden();
                break;
            case 5:
                cout << "Cantidad de bicicletas averiadas: "
                     << arbol.cantBicicletasAveriadas() << endl;
                break;
            case 6:
                cout << "Altura arbol: "
                     << arbol.calcularAlturaArbol() << endl;
                break;
            case 7:
                int biciId;
                cout << "Ingresa el id: ";
                cin >> biciId;
                arbol.eliminarBicicleta(biciId);
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
void menuColas(AbbBicicletas& arbol, ColaPrioridadBicicletas& cola, GestorEstaciones& gestor) {
    int opcionElegida;
    do {
        cout << "\n===== GESTION DE COLAS =====" << endl;
        cout << "1. Ingresar bicicleta por ID al taller de reparación." << endl;
        cout << "2. Extraer bicicleta con mayor urgencia del taller al taller de reparación." << endl;
        cout << "3. Devolver bicicleta a estación." << endl;
        cout << "4. Retirar bicicleta de estación" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcionElegida;
        switch (opcionElegida) {
            case 1: {
                int id;
                cout << "Ingrese el id de la bicicleta: ";
                cin >> id;
                Bicicleta bici = Bicicleta(-1, "", "", "", -1); // dummy

                if (!arbol.obtenerBicicleta(id, bici)) {
                    cout << "La bicicleta no se encontró en el sistema." << endl;
                }
                else {
                    cola.insertarUnaBici(bici);
                }
                break;
            }
            case 2: {
                Bicicleta bici = Bicicleta(-1, "", "", "", -1); // dummy
                if (!cola.extraerBicicletaConMayorPrioridad(bici)) {
                    cout << "No hay bicicletas en el taller." << endl;
                }
                else {
                    cout << "Bicicleta extraida: " << bici.getBiciId() << endl;
                }
                break;
            }
            case 3: {
                string codigo;
                cout << "Ingrese el codigo de la estacion: ";
                cin >> codigo;
                gestor.devolverBicicletaAEstacion(codigo);
                break;
            }
            case 4: {
                int dni;
                string codigo;
                cout << "Ingrese el DNI del usuario: ";
                cin >> dni;
                cout << "Ingrese el codigo de la estacion: ";
                cin >> codigo;
                gestor.retirarBicicletaDeEstacion(codigo, dni);
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
        cout << "3. Eliminar estación" << endl;
        cout << "4. Ordenar estaciones por capacidad" << endl;
        cout << "5. Ordenar estaciones por bicicletas disponibles" << endl;
        cout << "6. Mostrar estaciones con ocupacion baja" << endl;
        cout << "7. Buscar camino mas corto" << endl;
        cout << "8. Mostrar el total de colisiones" << endl;
        cout << "9. Mostrar factor de carga" << endl;
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
            case 3: {
                string codigo;
                cout << "Ingrese el codigo de la estacion: ";
                cin >> codigo;
                gestor.eliminarEstacion(codigo);
                break;
            }
            case 4:
                gestor.estacionesOrdenadasPorCapacidad();
                break;
            case 5:
                gestor.estacionesOrdenadasPorDisponibilidad();
                break;
            case 6:
                gestor.estacionesConOcupacionBaja();
                break;
            case 7: {
                string origen, destino;
                cout << "Ingrese el codigo de la estacion de origen: ";
                cin >> origen;
                cout << "Ingrese el codigo de la estacion de destino: ";
                cin >> destino;
                gestor.caminoMasCorto(origen, destino);
                break;
            }
            case 8:
                gestor.totalColisiones();
                break;
            case 9:
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
    int i = 0;

    cout << "\n===== REDISTRIBUCION DE BICICLETAS =====" << endl;
    cout << "Ingrese la cantidad de estaciones a las cuales redistribuir bicicletas: ";
    cin >> cantidadEstaciones;
    cout << "Ingrese la capacidad del camion: ";
    cin >> capacidadCamion;
    string* codigos = new string[capacidadCamion];

    do {
        cout << "Ingrese el código de la estación número " << i + 1 << ". ";
        cin >> codigos[i++];
    } 
    while (i < cantidadEstaciones);

    gestor.mostrarRestribucionBicicletas(codigos, cantidadEstaciones, capacidadCamion);
    delete[] codigos;
}

// ---------- MENU PRINCIPAL ----------
int main() {
    // crea las estructuras principales y lee de los archivos de entrada
    GestorEstaciones gestorEstaciones = GestorEstaciones(11);
    AbbBicicletas arbol = AbbBicicletas();
    ListaViajes listaViajes = ListaViajes();
    ColaPrioridadBicicletas colaTaller = ColaPrioridadBicicletas(10);
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
                menuColas(arbol, colaTaller, gestorEstaciones);
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
