#pragma once
#include "Producto.h"
#include <conio.h>
using namespace std;

class Lista_prod {
private:
    producto arreglo;
    int n;
public:
    Lista_prod() {
        arreglo = nullptr;
        n = 0;
    }
    ~Lista_prod() {}

    void crear(producto* obj) {
        producto aux = new producto * [n + 1];
        for (int c = 0; c < n; c++) {
            aux[c] = arreglo[c];
        }
        aux[n] = obj;
        n++;
        if (arreglo != nullptr) {
            delete[]arreglo;
        }
        arreglo = aux;

    }

    void listar_producto() {
        cout << "nombre     \t" << "stock     \t" << "precio     \t" << endl;
        if (this->n == 0) {
            cout << "No existe datos...";
            _getch();
            return;
        }
        for (int c = 0; c < n; c++) {
            arreglo[c]->to_string();
        }
    }
    void eliminar(int pos) {
        for (int f = 0; f < n; f++) {
            if (f == pos) {
                for (int c = pos; c < n - 1; c++) {
                    arreglo[c] = arreglo[c + 1];
                }
            }
        }
        n--;
    }
    void consultarStock(int valor) {
        for (int c = 0; c < n; c++) {
            if (arreglo[c]->get_stock() == valor) {
                arreglo[c]->to_string();
            }
        }
    }
};