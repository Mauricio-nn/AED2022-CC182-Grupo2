#pragma once
#include "Librerias.h"
#include "AVL.h"
#include "Transacciones.h"

class CreateAVL {
    ifstream lectura;
    ofstream escritura;
    AVLTree<Transacciones>* arbolbalanced;
    vector<Transacciones> datos;
private:
    void guardarEnAVL() {
        for (Transacciones& r : datos)
            this->arbolbalanced->insert(r);
    }
    void swap(Transacciones& a, Transacciones& b) {
        Transacciones c = a;
        a = b;
        b = c;
    }
public:
    CreateAVL() {
        arbolbalanced = new AVLTree<Transacciones>(
            [](Transacciones value) -> void {
                cout << value << "\n";
            },
            [](Transacciones  a, Transacciones  b) -> bool {
                return a.getcuenta() < b.getcuenta();
            }
            );
        leerLosDatos();
    }
    void leerLosDatos() {
        lectura.open("dataset.csv");
        string line;
        while (getline(lectura, line, '\n')) {
            stringstream s(line);
            string aux;
            string nombreapellido;
            double consumo;
            long dni;
            getline(s, aux, ',');
            nombreapellido = aux;
            getline(s, aux, ',');
            consumo = atof(aux.c_str());
            getline(s, aux, ',');
            dni = atof(aux.c_str());
            Transacciones r(nombreapellido, consumo, dni);

            datos.push_back(r);

        }
        lectura.close();
        guardarEnAVL();
    }
    void mostrarAVL() {
        arbolbalanced->IterativePreOrder();
    }
};
