#include <iostream>
#include "GestorEstaciones.h"

int main() {
    GestorEstaciones* gestor = new GestorEstaciones(11);

    /* ESTACIONES DE PRUEBA */
    Estacion* estacion1 = new Estacion("ABC", "Estacion 1", "A", 50, 50);
    Estacion* estacion2 = new Estacion("BCA", "Estacion 2", "A", 50, 50);
    Estacion* estacion3 = new Estacion("TAZ", "Estacion 3", "A", 50, 50);
    Estacion* estacion4 = new Estacion("ZTA", "Estacion 4", "A", 50, 50);
    Estacion* estacion5 = new Estacion("FJA", "Estacion 5", "A", 50, 50);
    Estacion* estacion6 = new Estacion("ZED", "Estacion 6", "A", 50, 50);
    Estacion* estacion7 = new Estacion("ZEN", "Estacion 7", "A", 50, 50);
    Estacion* estacion8 = new Estacion("DEC", "Estacion 8", "A", 50, 50);
    Estacion* estacion9 = new Estacion("MAT", "Estacion 9", "A", 50, 50);
    Estacion* estacion10 = new Estacion("LOL", "Estacion 10", "A", 50, 50);
    Estacion* estacion11 = new Estacion("UNR", "Estacion 11", "A", 50, 50); // vértice aislado

    gestor->agregarEstacion(estacion1);
    gestor->agregarEstacion(estacion2);
    gestor->agregarEstacion(estacion3);
    gestor->agregarEstacion(estacion4);
    gestor->agregarEstacion(estacion5);
    gestor->agregarEstacion(estacion6);
    gestor->agregarEstacion(estacion7);
    gestor->agregarEstacion(estacion8);
    gestor->agregarEstacion(estacion9);
    gestor->agregarEstacion(estacion10);
    gestor->agregarEstacion(estacion11);
 
    /* CICLOVIAS */
    gestor->agregarCiclovia("ABC", "BCA"); // 1 - 2
    gestor->agregarCiclovia("ABC", "ZED"); // 1 - 6
    gestor->agregarCiclovia("ABC", "TAZ"); // 1 - 3
    gestor->agregarCiclovia("BCA", "DEC"); // 2 - 8
    gestor->agregarCiclovia("TAZ", "ZTA"); // 3 - 4
    gestor->agregarCiclovia("TAZ", "DEC"); // 3 - 8
    gestor->agregarCiclovia("TAZ", "LOL"); // 3 - 10
    gestor->agregarCiclovia("ZTA", "FJA"); // 4 - 5
    gestor->agregarCiclovia("ZTA", "ZEN"); // 4 - 7
    gestor->agregarCiclovia("FJA", "ZED"); // 5 - 6
    gestor->agregarCiclovia("DEC", "MAT"); // 8 - 9

    // PRUEBAS
    gestor->caminoMasCorto("ABC", "ZTA");
    gestor->caminoMasCorto("ABC", "UNR");
    gestor->totalColisiones();
    gestor->factorDeCarga();

    delete gestor;
}