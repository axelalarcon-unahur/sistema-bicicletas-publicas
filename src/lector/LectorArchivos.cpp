#include <fstream>
#include <sstream>
#include "lector/LectorArchivos.h"
#include "estaciones/GestorEstaciones.h"
using namespace std;

LectorArchivos::LectorArchivos(GestorEstaciones* gestor, AbbBicicletas* abbBicicletas, ListaViajes* listaViajes) {
    this->gestor = gestor;
    this->abbBicicletas = abbBicicletas;
    this->listaViajes = listaViajes;
}

void LectorArchivos::leerArchivos() {
    leerEstaciones();
    leerBicicletas();
    leerViajes();
    leerCiclovias();
}

void LectorArchivos::leerEstaciones() {
    ifstream archivo("../../entradas/estaciones.txt"); // crea objeto para leer archivo
    string linea; // usado para leer cada linea del archivo

    // mientras haya lineas que leer
    while (getline(archivo, linea)) { 
        string codigo, nombre, barrio;
        int capacidadAnclajes, bicisDisponibles;
        stringstream ss(linea);
        string aux;

        getline(ss, codigo, ' '); // lee hasta el primer espacio, y pone el contenido en codigo 
        getline(ss, nombre, ' ');
        getline(ss, barrio, ' ');
        getline(ss, aux, ' ');
        capacidadAnclajes = stoi(aux); // convierte de string a int
        getline(ss, aux, ' ');
        bicisDisponibles = stoi(aux);

        gestor->agregarEstacion(new Estacion(codigo, nombre, barrio, capacidadAnclajes, bicisDisponibles));
    }
    
    archivo.close();
}

void LectorArchivos::leerBicicletas() {
    ifstream archivo("../../entradas/bicicletas.txt");
    string linea;

    while (getline(archivo, linea)) { 
        int biciId, kilometros;
        string codigoEstacion, tipo, estado;
        stringstream ss(linea);
        string aux;

        getline(ss, aux, ' ');
        biciId = stoi(aux);
        getline(ss, codigoEstacion, ' ');
        getline(ss, tipo, ' ');
        getline(ss, estado, ' ');
        getline(ss, aux, ' ');
        kilometros = stoi(aux);

        abbBicicletas->insertarUnaBicicleta(Bicicleta(biciId, codigoEstacion, tipo, estado, kilometros));
    }
    
    archivo.close();
}

void LectorArchivos::leerViajes() {
    ifstream archivo("../../entradas/viajes.txt");
    string linea;

    while (getline(archivo, linea)) { 
        int idViaje, idBicicleta, dniUser, fecha, duracionMin;
        string estacionOrigen, estacionDestino;
        stringstream ss(linea);
        string aux;

       getline(ss, aux, ' ');
       idViaje = stoi(aux);
       getline(ss, aux, ' ');
       idBicicleta = stoi(aux);
       getline(ss, aux, ' ');
       dniUser = stoi(aux);
       getline(ss, estacionOrigen, ' ');
       getline(ss, estacionDestino, ' ');
       getline(ss, aux, ' ');
       fecha = stoi(aux);
       getline(ss, aux, ' ');
       duracionMin = stoi(aux);

       listaViajes->agregarViaje(Viaje(idViaje, idBicicleta, dniUser, estacionOrigen, estacionDestino, fecha, duracionMin));
    }
    
    archivo.close();
}

void LectorArchivos::leerCiclovias() {
    ifstream archivo("../../entradas/estaciones.txt"); 
    string linea; 

    while (getline(archivo, linea)) { 
        string origen, destino;
        stringstream ss(linea);
        string aux;

        getline(ss, origen, ' ');
        getline(ss, destino, ' ');

        gestor->agregarCiclovia(origen, destino);
    }
    
    archivo.close();
}