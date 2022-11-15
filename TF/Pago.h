#pragma once
#include "Librerias.h"
template <class v>
//recursividad 

class Pago {
private:
	v docSalida;
	v metPago;
public:
	Pago(v docSalida, v metPago) {
		this->docSalida = docSalida;
		this->metPago = metPago;

	}
	~Pago() {}

	v calcular_monto() { return this->monto; }
};