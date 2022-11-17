#include"iostream"
#include"fstream"
#include"conio.h";

using namespace std;

class GeneradorCSV {
private:
	string randNames[20] = {
		"Mauricio",
		"Elsa",
		"Chamber",
		"Alvaro",
		"Alejandra",
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
		"Omen",
		"Phoenix",
		"Skye",
		"Arevalo",
		"Quispe",
		"Breach",
		"Fukuda",
		"Pato",
		"Po",
		"Fu",
		"Oliveira",
		"Propeth",
		"Huscar",
		"Sniper",
		"Smith",
		"Razor",
		"Fade",
		"Harbor",
		"Cypher"
	};
public:
	GeneradorCSV() {

	}
	~GeneradorCSV() {}

	void generarCSV(int n) {
		cout << "Generando datos uwu ...\n";

		ofstream file;
		file.open("gen_dataset.csv");
		if (file.is_open()) {
			string data1;
			float monto;
			long dni;
			float a = 2.0;

			for (int i = 0; i < n; i++) {
				data1 = randNames[rand() % 20] + " " + randSur[rand() % 20];
				monto = rand() % 80 + 20;

				dni = rand() % 9999999 + 10000000;
				file << data1 << "," << monto << "." << rand() % 10 << "," << dni << "," << "\n";
			}
		}

		file.close();
		cout << "Datos generados uwu ...\n";
	}

};
