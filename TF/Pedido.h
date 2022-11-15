#include "FuncionesGenerales.h"
#include <queue>
#pragma once

class PedidoProducto {
private:
	int codProducto;
	int cant;
	string descripcion;
	float precio, subtotal;
public:
	PedidoProducto(int codprod, int cant, float precio, string desc) {
		this->codProducto = codprod;
		this->cant = cant;
		this->precio = precio;
		subtotal = precio * cant;
		descripcion = desc;
	}
	~PedidoProducto() {}
	void to_string() {
		cout << setw(3) << codProducto << "\t";
		cout << setw(3) << cant << "\t";
		cout << setw(3) << precio << "\t";
		cout << setw(3) << subtotal << "\t";
		cout << endl;
	}
	float getSubtotal() {
		return subtotal;
	}
	int getCodProd() {
		return codProducto;
	}
	int getCant() {
		return cant;
	}
	float getPrecio() {
		return precio;
	}
	string getDescripcion() {
		return descripcion;
	}
};

class clsPedido {
private:
	int numPedido;
	string codUsuario;
	float total;
	vector<PedidoProducto*> ListaPProducto;
public:
	clsPedido(string codusuario) {
		ListaPProducto.clear();
		total = 0.00;
		this->codUsuario = codusuario;
	}
	~clsPedido() {}
	void AgregarProducto(int codprod, int cant, float precio, string desc) {
		PedidoProducto* temporal = new PedidoProducto(codprod, cant, precio, desc);
		ListaPProducto.push_back(temporal);
		CalcularTotal();
	}
	void CalcularTotal() {
		total = 0;
		for (int i = 0; i < ListaPProducto.size(); i++) {
			total += ListaPProducto[i]->getSubtotal();
		}
	}

	void listar_pedido() {
		if (ListaPProducto.size() == 0) {
			cout << "No existe datos...";
			return;
		}
		for (int c = 0; c < ListaPProducto.size(); c++) {
			gotoXY(15, 9 + c); cout << ListaPProducto[c]->getCodProd();
			gotoXY(23, 9 + c); cout << ListaPProducto[c]->getDescripcion();
			gotoXY(40, 9 + c); cout << ListaPProducto[c]->getCant();
			gotoXY(52, 9 + c); cout << ListaPProducto[c]->getPrecio();
			gotoXY(60, 9 + c); cout << ListaPProducto[c]->getSubtotal();
		}
	}
	float getTotal() {
		return total;
	}
	int getNumPedido() {
		return numPedido;
	}
	string getCodUsuario() {
		return codUsuario;
	}
	void setNumPedido(int num) {
		numPedido = num;
	}
};

///
void MostrarPedido(clsPedido* p) {
	int pintar = 10;
	Marco(pintar, 1, 80, 24, ConsoleColor::Black, ConsoleColor::White);
	gotoXY(pintar + 32, 3);	mensaje("Pedido");
	gotoXY(pintar + 32, 4);	mensaje("------");
	gotoXY(pintar + 3, 7);	mensaje("Codigo    Producto      Cantidad      Precio    Subtotal");
	gotoXY(pintar + 3, 8);	mensaje("----------------------------------------------------------");
	p->listar_pedido();
	gotoXY(pintar + 3, 18);	mensaje("----------------------------------------------------------");
	gotoXY(pintar + 3, 19);	mensaje("Total a pagar: ");	cout << p->getTotal();

	color(ConsoleColor::Black, ConsoleColor::DarkRed);
	gotoXY(pintar + 4, 20); mensaje("(Presione una tecla para continuar)");
	color(ConsoleColor::Black, ConsoleColor::DarkRed);
	_getch();
	system("cls");
}
void SeleccionPedidoMenu(ListaProducto* l) {
	int pintar = 10;
	Marco(pintar, 1, 80, 24, ConsoleColor::Black, ConsoleColor::White);
	gotoXY(pintar + 3, 2);	mensaje("Usuario:");
	gotoXY(pintar + 33, 4);	mensaje("Menu");
	gotoXY(pintar + 33, 5);	mensaje("----");
	gotoXY(pintar + 13, 7);	mensaje("Codigo     Producto        Precio");
	gotoXY(pintar + 13, 8);	mensaje("---------------------------------");
	l->listar_producto();
	gotoXY(pintar + 30, 18);	mensaje("Seleccione la opcion:");
	gotoXY(pintar + 3, 21);	mensaje("[0] Cancelar        [10] Ver pedido        [7] Ir a pagar");

	gotoXY(pintar + 50, 23);	mensaje("Total S/.");
}

void SeleccionPedidos(ListaProducto* l, string codUsuario) {
	//queue<clsPedido*> ca;
	clsPedido* pedido = new clsPedido(codUsuario);
	int opc = 0, cant = 0, stock = 0, numpedido = 0;
	bool opcCorrecta = false;
	float precio = 0.0;
	string descripcion = "";
	while (true) {
		do
		{
			SeleccionPedidoMenu(l);
			gotoXY(62, 18);
			cin >> opc;
			if (opc == 10) {
				opcCorrecta = true;
			}
			if (opc == 7) {
				opcCorrecta = true;
			}
			if (opc == 0) {
				opcCorrecta = true;
			}
			if (opcCorrecta == false) {
				stock = 0;
				precio = 0.0;
				descripcion = "";
				l->CapturaProducto(opc, precio, stock, descripcion);
				if (precio == 0) {
					color(ConsoleColor::Black, ConsoleColor::White);
					gotoXY(22, 19); mensaje("Producto seleccionado no valido.");
					gotoXY(22, 20); mensaje("(Presione una tecla para continuar)");
					color(ConsoleColor::Black, ConsoleColor::White);
					_getch();
					system("cls");

				}
				else {
					opcCorrecta = true;
				}
			}

		} while (!opcCorrecta);
		if (opc == 0) {
			break;
		}
		if (opc == 7) {
			//pagar();

			numpedido = CapturarNumPedido();
			if (numpedido == 0) {
				color(ConsoleColor::Black, ConsoleColor::White);
				gotoXY(22, 19); mensaje("No se establecio el # de pedido para la atencion.");
				gotoXY(22, 20); mensaje("(Presione una tecla para continuar)");
				color(ConsoleColor::Black, ConsoleColor::White);
				_getch();
				system("cls");
			}/*
			else {
				pedido->setNumPedido(numpedido);
				ca.push(pedido);

			}*/
			break;
		}
		if (opc == 10) {
			MostrarPedido(pedido);
			continue;
		}

		if (opc != 0 && opc != 7) {
			do
			{
				gotoXY(22, 19); mensaje("Ingrese la cantidad que desea consumir: ");
				gotoXY(62, 19);  cin >> cant;
				//Capturar datos del producto
				stock = 0;
				precio = 0.0;
				descripcion = "";
				l->CapturaProducto(opc, precio, stock, descripcion);
			} while (cant > stock);
			//Adicionar pedido
			pedido->AgregarProducto(opc, cant, precio, descripcion);
		}
		//system("cls");
	}
}