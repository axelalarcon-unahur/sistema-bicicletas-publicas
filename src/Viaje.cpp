#include "Viaje.h"

Viaje::Viaje(int idViaje, int idBicicleta, string dniUser,
             string estacionDeOrigen, string estacionDestino,
             int fecha, int duracionMin)
            {
    this->idViaje = idViaje; // permite acceder al atributo
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
string Viaje::getDniUsuario() {
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