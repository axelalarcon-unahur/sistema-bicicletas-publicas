#include "viajes/Viaje.h"

Viaje::Viaje(int idViaje, int idBicicleta, int dniUser,
             string estacionDeOrigen, string estacionDestino,
             int fecha, int duracionMin)
            {
    this->idViaje = idViaje; 
    this->idBicicleta = idBicicleta;
    this->dniUser = dniUser;
    this->estacionDeOrigen = estacionDeOrigen;
    this->estacionDestino = estacionDestino;
    this->fecha = fecha;
    this->duracionMin = duracionMin;
}
int Viaje::getViajeId() {
    return idViaje;
}
int Viaje::getBiciId() {
    return idBicicleta;
}
int Viaje::getDniUsuario() {
    return dniUser;
}
string Viaje::getEstacionDeOrigen() {
    return estacionDeOrigen;
}
string Viaje::getEstacionDestino() {
    return estacionDestino;
}
int Viaje::getFecha() {
    return fecha;
}
int Viaje::getDuracionMin() {
    return duracionMin;
}