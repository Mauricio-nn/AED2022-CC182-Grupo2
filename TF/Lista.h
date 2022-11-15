#pragma once
//#include"Nodo.h"

template<class v>
class Lista {
private:
	Nodo<v>* start;
	uint size;
public:
	Lista() {
		start = nullptr;
		size = 0;
	}
	~Lista() {}

	void agregarNodo(v data1, v data2, v data3) {
		Nodo<v>* newNodo = new Nodo<v>(data1, data2, data3);

		if (start == nullptr)
			start = newNodo;
		else {
			newNodo->next = start;
			start = newNodo;
		}

		size++;
	}

	void mostrarTodo() {
		Nodo<v>* current = start;
		uint cont = 1;

		cout << "Total de datos -> " << size << "\n\n";
		while (current != nullptr) {
			cout << cont << "\n";
			cout << current->getData1() << "\n" << current->getData2() << "\n" << current->getData3() << "\n\n";

			current = current->next;
			cont++;
		}
	}

	void mostrarDato2() {
		Nodo<v>* current = start;
		uint cont = 1;

		cout << "Total de datos -> " << size << "\n\n";
		while (current != nullptr) {
			cout << cont << "\n";
			cout << current->getData2() << "\n\n";

			current = current->next;
			cont++;
		}
	}

	void mostrarDato1() {
		Nodo<v>* current = start;
		uint cont = 1;

		cout << "Total de datos -> " << size << "\n\n";
		while (current != nullptr) {
			cout << cont << "\n";
			cout << current->getData1() << "\n\n";

			current = current->next;
			cont++;
		}
	}

	uint getSize() { return this->size; }

};