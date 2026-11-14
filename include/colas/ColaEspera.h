#ifndef COLA_ESPERA_H
#define COLA_ESPERA_H

struct NodoEspera {
    int dniUser;
    NodoEspera* siguiente;
};
class ColaEspera{
private:
        NodoEspera* primero; // usuario que lleva mas tiempo esperando
        NodoEspera* ultimo; // usuario que llego ultimo
public:
        ColaEspera();
        ~ColaEspera();
        void encolar(int dni);
        int desencolar();
        bool estaVacia();
};
#endif
