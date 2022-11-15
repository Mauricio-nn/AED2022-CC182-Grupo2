#pragma once
#include "Librerias.h"
#include "Producto.h"
#include "Pedido.h"

void menu1()
{
	cout << "Bienvenido a BAM Fast Food!\n\n";
	cout << "Es cliente nuevo o antiguo?\n\n";
	cout << "Marque 1 si desea iniciar sesion o marque 2 si desea registrarse :D\n\n";
	cout << "1: Iniciar Sesion\n";
	cout << "2: Registrasre\n";
	cout << "Opcion:\t";

}

template<template<class> class v, class T>
void MenuPrincipal(v<T>* Controladora) {
	ListaProducto* LP = new ListaProducto();
	int opcion = 0;
	

	cout << "                  Bienvenidos a BAM Fast Food!\n\n";
	cout << "   En que lo podemos ayudar? :D\n\n";
	cout << "    1. Ver promociones del mes.\n";
	cout << "    2. Ver nuestra carta.\n";
	cout << "    3. Hacer pedido online.\n";
	cout << "    4. Ver nuestro stock de productos.\n";
	cout << "    5. Salir de la aplicacion.\n\n";
	cout << "    Seleccione la opcion que desee:"; cin >> opcion;

	
	
	switch (opcion)
	{
	case 1:
		system("CLS");
		Controladora->getPromociones()->MostrarPromociones();
		cout << "\nPresione una tecla para regresar al menu principal";
		_getch();
		system("CLS");
		MenuPrincipal(Controladora);
		break;

	case 2:
		system("cls");
		LP->CargaProducto();
		LP->listar_producto();
		_getch();
		system("CLS");
		MenuPrincipal(Controladora);
		break;

	case 3:
		system("cls");
		LP->CargaProducto();
		SeleccionPedidos(LP, "45568");
		_getch();
		system("CLS");
		MenuPrincipal(Controladora);
		break;

	case 4:
		system("CLS");
		Controladora->getStock()->MostrarStock();
		cout << "\nPresione una tecla para regresar al menu principal";
		_getch();
		system("CLS");
		MenuPrincipal(Controladora);
		break;

	case 5:
		system("CLS");
		cout << "\n\n   Gracias por utilizar nuestra aplicacion!\n\n ";
		system("PAUSE");
		break;


	}

}

template<template<class> class v, class T>
void Register(v<T>* Controladora) {

	string usuario, contrasena = "";


	cout << "Menu de Registro de Usuario BAM Fast Food\n\n";
	cout << "- Tu usuario y contrasena debe contener al menos 3 caracteres\n";
	cout << "- Tus credenciales no pueden coincidir con algun usuario registrado\n\n";

	cout << "Ingresa tu nuevo nombre de usuario -> "; cin >> usuario;

	cout << "Ingresa tu nueva contraseña-> ";  cin >> contrasena;

	auto user = Controladora->verifyExistUser(usuario);

	if (usuario.size() < 3 || contrasena.size() < 3 || user.exist == true) {

		cout << "\n\nError al crear usuario:\n";
		cout << "El usuario ya se encuentra registrado o las credenciales contienen menos de 3 caracteres\n\n";
		system("PAUSE"); system("CLS");

		Register(Controladora);
	}
	else
	{
		Controladora->insertUser(usuario, contrasena);
		system("PAUSE"); system("CLS");
		Login(Controladora);
	}
}


template<template<class> class v, class T>
int Login(v<T>* Controladora) {

	string usuario, contrasena = "";

	system("CLS"); cout << "Iniciar Sesion BAM Fast Food\n\n";

	if (Controladora->getUsers()->size() == 0) {
		cout << "No hay usuarios registrados, ve a la opcion de Registros en el menu principal\n";
		cout << "Presione una tecla para volver al menu principal.";
	}
	else {
		cout << "Nombre de Usuario -> "; cin >> usuario;
		cout << "Ingresa tu contraseña-> "; cin >> contrasena;

		auto user = Controladora->verifyExistUser(usuario);

		if (Controladora->verifyLogin(usuario, contrasena) == true) {


			cout << "\nSesion inciada con exito!";
			cout << " Presiona una tecla";
			system("CLS");
			MenuPrincipal(Controladora);
			_getch();
			return 1;

		}


		else {
			cout << "Credenciales incorrectos.  \n";
			_getch();
			Login(Controladora);

			
		}
	}
}

template<template<class> class v, class T>
void Pedido(v<T>* Controladora) {

	string docsalida, metpago = " ";
	clsPedido pedido;
	pedido.crearPedido();
	pedido.consultarPedido();


	cout << "Ingresar si requiere boleta o factura";
	cin >> docsalida;
	cout << "Ingresar su metodo de pago (Efectivo o tarjeta)";
	cin >> metpago;

	if (Controladora->monto = getprecio()) {
		cout << "Su compra ha sido realizada";
		_getch();
		system("cls");
	}

	else {
		cout << "Vuelva a ingresar el monto correcto\n";
		Pedido(Controladora);
	}
}