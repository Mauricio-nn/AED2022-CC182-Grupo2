#pragma once
#include "Librerias.h"
#include "AVL.h"
#include "Transacciones.h"

class CreateAVL {
    ifstream lectura;
    ofstream escritura;
    AVLTree<Prueba>* arbolbalanced;
    vector<Prueba> datos;
private:
    void guardarEnAVL() {
        for (Prueba& r : datos)
            this->arbolbalanced->insert(r);
    }
    void swap(Prueba& a, Prueba& b) {
        Prueba c = a;
        a = b;
        b = c;
    }
public:
    CreateAVL() {
        arbolbalanced = new AVLTree<Prueba>(
            [](Prueba value) -> void {
                cout << value << "\n";
            },
            [](Prueba  a, Prueba  b) -> bool {
                return a.getcuenta() < b.getcuenta();
            }
            );
        leerLosDatos();
    }
    void leerLosDatos() {
        lectura.open("gen_dataset.csv");
        string line;
        while (getline(lectura, line, '\n')) {
            stringstream s(line);
            string aux;
            string nombreapellido;
            float consumo;
            long dni;
            getline(s, aux, ',');
            nombreapellido = aux;
            getline(s, aux, ',');
            consumo = atof(aux.c_str());
            getline(s, aux, ',');
            dni = atof(aux.c_str());
            Prueba r(nombreapellido, consumo, dni);

            datos.push_back(r);

        }
        lectura.close();
        guardarEnAVL();
    }
    void mostrarAVL() {
        arbolbalanced->IterativePreOrder();
    }
};
