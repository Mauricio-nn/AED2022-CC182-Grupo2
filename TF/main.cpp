#include"Controladora.h"
#include"Lista.h"
#include "Menus.h"
#include "GeneradorDS.h"


int main()
{
	srand(time(NULL));

	GeneradorCSV generar;
	generar.generarCSV(5);

	int a;
	
	Controladora<string>* controladora = new Controladora<string>();
	controladora->Agregar_Datos();

	menu1();
	cin >> a;

	system("cls");

	if (a == 2) {

		Register(controladora);
		getch();
		system("cls");

	}
	else {
		Login(controladora) == 1;
	}
}