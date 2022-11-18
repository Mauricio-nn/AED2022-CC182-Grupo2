#include"iostream"
#include"fstream"
#include"conio.h";

using namespace std;

class GeneradorCSV {
private:
	string randNames[20] = {
		"Mauricio",
		"Alejandra",
		"Chamber",
		"Alvaro",
		"Sofia",
		"Liliana",
		"Camila",
		"William",
		"Ahri",
		"Astra",
		"Juan",
		"Enzo",
		"Miguel",
		"Bryan",
		"Silvana",
		"Reyna",
		"Diana",
		"Briana",
		"Sage",
		"Yoru"
	};
	string randSur[20] = {
		"Brimstone",
		"Oliveira",
		"Phoenix",
		"Rodriguez",
		"Arevalo",
		"Quispe",
		"Werner",
		"Fukuda",
		"Pato",
		"Palacios",
		"Fu",
		"Garcia",
		"Iglesias",
		"Diaz",
		"Torre",
		"Smith",
		"Lopez",
		"Ruiz",
		"Harbor",
		"Fernandez"
	};
public:
	GeneradorCSV() {

	}
	~GeneradorCSV() {}

	void generarCSV(int n) {
		cout << " Cargando datos...\n";

		ofstream file;
		file.open("dataset.csv");
		if (file.is_open()) {
			string data1;
			float monto;
			long dni;
			float a = 2.0;

			for (int i = 0; i < n; i++) {
				data1 = randNames[rand() % 20] + " " + randSur[rand() % 20];
				monto = rand() % 80 + 20;

				dni = (rand() % 89999999) + 10000000;
				file << setw(20) << data1 << ";" << setw(18) << monto << "." << rand() % 10 << ";" << setw(22) << dni << "\n";
			}
		}

		file.close();
		cout << " Datos cargados con exito! :D\n";
		system("PAUSE");
	}

};
