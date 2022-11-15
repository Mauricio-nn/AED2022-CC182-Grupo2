#pragma once

#include"Nodo.h"
#include"Lista.h"
#include"NodoDE.h"
#include"ListaDE.h"
#include"Usuario.h"

template<class v>
class Controladora
{
private:
	Lista<v>* clientes;
	ListaDE<v>* promociones;
	ListaDE<v>* stock;
	vector<Usuario<v>*>* usuarios;

public:
	Controladora() {
		clientes = new Lista<v>();
		promociones = new ListaDE<v>();
		stock = new ListaDE<v>();
		usuarios = new vector<Usuario<v>*>();

	}
	~Controladora() {};
	template<template<class> class v, class T>
	void agregarNodo(v<T>* datas, string filename) {
		string data1, data2, data3 = "";
		ifstream getdata;

		getdata.open(filename, ios::in);

		if (getdata.is_open()) {
			while (!getdata.eof()) {
				getline(getdata, data1);
				getline(getdata, data2);
				getline(getdata, data3);
				datas->agregarNodo(data1, data2, data3);
				data1, data2, data3 = "No data";
			}
			getdata.close();
		}
		else {
			cout << "Error\n" << filename;
			_getch(); exit(0);
		}

	}

	template<template<class> class v, class T>
	void agregarNodoDE(v<T>* datas, string filename) {
		string data1, data2, data3 = "";
		ifstream getdata;

		getdata.open(filename, ios::in);

		if (getdata.is_open()) {
			while (!getdata.eof()) {
				getline(getdata, data1);
				getline(getdata, data2);
				getline(getdata, data3);
				datas->AgregarNodoDE(data1, data2, data3);
				data1, data2, data3 = "No data";
			}
			getdata.close();
		}
		else {
			cout << "Error\n" << filename;
			_getch(); exit(0);
		}

	}

	void Agregar_Datos() {
		agregarNodo(clientes, "Archivos//usuarios.txt");
		agregarNodoDE(promociones, "Archivos//promociones.txt");
		agregarNodoDE(stock, "Archivos//stock.txt");

		string data1, data2, data3, data4 = ""; ifstream getdata;
		getdata.open("Archivos//usuarios.txt", ios::in);


		if (getdata.is_open()) {
			while (!getdata.eof()) {
				getline(getdata, data1);
				getline(getdata, data2);

				usuarios->push_back(new Usuario<v>(data1, data2));

				data1, data2 = "No data";

			}
			getdata.close();
		}
		else {
			cout << "Error\n";
			_getch(); exit(0);
		}

	}

	Lista<string>* getUsuarios() { return clientes; }
	ListaDE<string>* getPromociones() { return  promociones; }
	ListaDE<string>* getStock() { return  stock; }

	void insertUser(v usuario, v contrasena) {
		usuarios->push_back(new Usuario<v>(usuario, contrasena));

		ofstream file;
		file.open("Archivos//usuarios.txt", ofstream::app);
		if (file.is_open()) {
			file << usuario << "\n" << contrasena << "\n";
			file.close();
		}
		else {
			cout << "Error \n";
			cout << "Presiona una tecla para volver al menu principal...";
		}
		cout << "\n\nBienvenido " << usuario << " te has registrado con exito!\n";

	}

	auto verifyExistUser(v usuario) {
		struct Userdata {
			bool exist;
			uint id;
		};
		for (uint i = 0; i < usuarios->size(); i++) {
			if (usuarios->at(i)->getUsuario() == usuario) {
				return Userdata{ true, i };
			}
		}
	}

	bool verifyLogin(v usuario, v contrasena) {
		for (uint i = 0; i < usuarios->size(); i++) {
			if (usuarios->at(i)->getUsuario() == usuario && usuarios->at(i)->getContrasena() == contrasena) {
				return true;
			}
		}
	}
	vector<Usuario<v>*>* getUsers() { return usuarios; }

};

//void BubbleSort(int a[], int n)
//{
//	bool ordenado;
//	for (int i = 0; i < n - 1; i++)
//	{
//		ordenado = true;
//		for (int j = 0; j < n - (i + 1); j++)
//		{
//			if (a[j] > a[j + 1])
//			{
//				int aux = a[j];
//				a[j] = a[j + 1];
//				a[j + 1] = aux;
//				ordenado = false;
//			}
//		}
//	}
//}


