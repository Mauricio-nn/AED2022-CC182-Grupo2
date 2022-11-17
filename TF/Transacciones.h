#pragma once
#include"Librerias.h"

using namespace std;
class Prueba {
    string nombreapellido;
    float consumo;
    long dni;


public:
    Prueba(string nombreapellido, float consumo, long dni)
        :nombreapellido(nombreapellido), consumo(consumo), dni(dni) {}
    double getcuenta() {
        return this->consumo;
    }
    friend ostream& operator<<(ostream& os, Prueba p) {
        os << p.nombreapellido << " " << p.consumo << " " << p.dni;
        return os;
    }
};
