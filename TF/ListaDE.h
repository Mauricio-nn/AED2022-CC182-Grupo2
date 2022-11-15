#pragma once
#include"NodoDE.h"

#include <iostream>
#include <string>

using namespace std;

template<class v>
class ListaDE {
private:
	NodoDE<v>* start;
	int size;

public:
	ListaDE() {
		start = nullptr;
		size = 0;
	}
	~ListaDE() {
		Limpiar();
	}

	void Limpiar() {
		NodoDE<v>* aux;

		for (int i = 0; i < size; i++) {
			aux = start;
			start = start->next;
			delete aux;
		}
		start = nullptr;
		size = 0;
	}

	bool AgregarNodoDE(v data1, v data2, v data3) {
		NodoDE<v>* aux;

		if (size == 0) {
			start = new NodoDE<v>(data1,data2,data3);
			if (start->next != nullptr) {
				start->next->prev = start;
			}
			++size;
			return true;
		}
		aux = start;

		while (aux->next != nullptr) {
			aux = aux->next;
		}
		aux->next = new NodoDE<v>(data1, data2, data3);
		aux->next->prev = aux;
		++size;
		return true;
	}

	bool Eliminar_al_final() {
		if (size < 0) {
			return false;
		}

		NodoDE<v>* aux = start;
		for (int i = 0; i < size - 1; i++) {
			aux = aux->next;
		}
		aux->prev->next = aux->next;
		delete aux;
		--size;

		return true;
	}

	bool Eliminar_elementos(int pi, int pf) {
		int num = size;
		if (size < 0) {
			return false;
		}
		NodoDE<v>* aux1 = start;
		NodoDE<v>* aux2;

		for (int i = 0; i < pi; i++) {
			aux1 = aux1->next;
		}
		for (int j = pi - 1; j < pf; j++) {
			aux1 = aux2;
			aux1 = aux1->next;
			delete aux2;
			--num;
		}
		aux1->prev->next = aux1->next;
		if (aux1->next != nullptr) {
			aux1->next->prev = aux1->prev;
		}
		return true;
	}

	void MostrarPromociones() {
		NodoDE<v>* aux = start;
		int c = 1;

		cout << "  PROMOCIONES ACTUALES:\n";
		cout << "  ---------------------\n\n";


		while (aux) {
			cout <<"     Promocion "<< c << "\n\n";
			cout << aux->getData1() << "\n" << aux->getData2() << "\n" << aux->getData3() << "\n\n";
			++c;
			
			aux = aux->next;
		}
	}

	void MostrarStock() {
		NodoDE<v>* aux = start;
		int c = 1;

		cout << "  STOCK DE PRODUCTOS DISPONIBLES:\n";
		cout << "  -------------------------------\n\n";


		while (aux) {
			cout << "     Producto " << c << "\n\n";
			cout << aux->getData1() << "\n" << aux->getData2() << "\n" << aux->getData3() << "\n\n";
			++c;

			aux = aux->next;
		}
	}

	

};
