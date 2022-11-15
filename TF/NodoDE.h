#pragma once
#include"Librerias.h"

template<class v>
class ListaDE;

template<class v>
class NodoDE {
private:
	v data1, data2, data3;
	NodoDE* next;
	NodoDE* prev;
	friend class ListaDE<v>;
public:
	NodoDE(v data1, v data2, v data3) {
		this->data1 = data1;
		this->data2 = data2;
		this->data3 = data3;

		next = nullptr;
		prev = nullptr;
	}
	~NodoDE() {}

	v getData1() { return this->data1; }
	v getData2() { return this->data2; }
	v getData3() { return this->data3; }

	void setData1(v data1) { this->data1 = data1; }
	void setData2(v data2) { this->data2 = data2; }
	void setData3(v data3) { this->data3 = data3; }
};