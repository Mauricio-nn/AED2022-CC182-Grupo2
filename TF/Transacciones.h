#pragma once
#include"Librerias.h"

using namespace std;
class Transacciones {
    string nombreapellido;
    float consumo;
    long dni;


public:
    Transacciones(string nombreapellido, float consumo, long dni)
        :nombreapellido(nombreapellido), consumo(consumo), dni(dni) {}
    double getcuenta() {
        return this->consumo;
    }
    friend ostream& operator<<(ostream& os, Transacciones p) {
        os << p.nombreapellido << " " << p.consumo << " " << p.dni;
        return os;
    }
};
