#pragma once
#include "FuncionesGenerales.h"
#include <conio.h>
#include <string>>
#include <stdlib.h>
#include <iomanip>

class Producto {
private:
	int cod_producto;
	string descripcion;
	float precio;
	int stock;
public:
	Producto() {
		cod_producto = 0;
		descripcion = "";
		precio = 0.0;
		stock = 0;
	}
	Producto(int cod, string desc, float precio, int stock) {
		cod_producto = cod;
		descripcion = desc;
		this->precio = precio;
		this->stock = stock;
	}
	~Producto() {}

	void to_string() {
		cout << setw(3) << cod_producto << "\t";
		cout << setw(3) << descripcion << "\t";
		cout << setw(3) << precio << "      \t";
		cout << setw(3) << stock << "\t";
		cout << endl;
	}
	int getCodProd() {
		return cod_producto;
	}
	string getDescripcion() {
		return descripcion;
	}
	float getPrecio() {
		return precio;
	}
	int getStock() {
		return stock;
	}
};

class ListaProducto {
private:
	vector<Producto*> lp;
	int n;
public:
	ListaProducto() {
		lp.clear();
		n = 0;
	}
	~ListaProducto() {}

	void CargaProducto() {
		vector<string> registro;
		//Permite crear la instancia con el fichero
		ofstream filewrite;
		//Como fichero de entrada
		ifstream fileread;
		string linea;
		Producto* temporal;
		// enlace del archivo con el visual 
				// ios::in -> modo de entrada
		fileread.open("Archivos//Productos.txt", ios::in);
		//se utiliza para verificar si hay algun error al abrir el arcgivo
		if (fileread.fail()) {
			fileread.close();
		}
		else {
			while (getline(fileread, linea)) {
				registro = explode(";", linea);
				temporal = new Producto(stoi(registro[0]), registro[1], stof(registro[2]), stoi(registro[3]));
				Agregar(temporal);
			}
		}
	}
	void Agregar(Producto* obj) {
		lp.push_back(obj);
	}

	void CapturaProducto(int codprod, float& precio, int& stock, string& desc) {
		for (int i = 0; i < lp.size(); i++) {
			if (lp[i]->getCodProd() == codprod) {
				precio = lp[i]->getPrecio();
				stock = lp[i]->getStock();
				desc = lp[i]->getDescripcion();
				break;
			}
		}
	}

	void listar_producto() {
		vector<Producto*> lpOrdenada;
		lpOrdenada = lp;

		if (lpOrdenada.size() == 0) {
			cout << "No existe datos...";
			return;
		}
		gotoXY(23, 7);	mensaje("Codigo     Producto        Precio");
		gotoXY(23, 8);	mensaje("---------------------------------");

		for (int c = 0; c < lpOrdenada.size(); c++) {
			gotoXY(25, 9 + c); cout << lpOrdenada[c]->getCodProd();
			gotoXY(30, 9 + c); cout << lpOrdenada[c]->getDescripcion();
			gotoXY(50, 9 + c); cout << lpOrdenada[c]->getPrecio();

		}
	}
};
