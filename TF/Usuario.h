#pragma once

#include"Librerias.h"

template<class v>
class Usuario {
private:
	v usuario, contrasena;
public:
	Usuario(v usuario, v contrasena) {

		this->usuario = usuario;
		this->contrasena = contrasena;
		
	}
	~Usuario() {}

	v getUsuario() { return this->usuario; }
	v getContrasena() { return this->contrasena; }
};
