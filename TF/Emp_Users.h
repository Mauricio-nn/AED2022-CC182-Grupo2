#pragma once

#include"Librerias.h"

template<class v>
class CEmp_users {
private:
	v emp_user, emp_password;
public:
	CEmp_users(v emp_user, v emp_password) {

		this->emp_user = emp_user;
		this->emp_password = emp_password;

	}
	~CEmp_users() {}

	v getEmpUsuario() { return this->emp_user; }
	v getEmpContrasena() { return this->emp_password; }
};
