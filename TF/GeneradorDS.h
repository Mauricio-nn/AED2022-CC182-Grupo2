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

	string emp_names[21] = {
		"Ali",
		"Robyn",
		"Yelena",
		"Frankie",
		"Seka",
		"Nicolette",
		"Laina",
		"Nicoline",
		"Gerry",
		"Agretha",
		"Josef",
		"Noreen",
		"Krystalle",
		"Jeff",
		"Stephani",
		"Letta",
		"Frederico",
		"Kraig",
		"Augustin",
		"Emily",
		"Rolando"
	};

	string emp_pass[25] = {
		"a",
		"b",
		"c",
		"d",
		"f",
		"g",
		"h",
		"i",
		"j",
		"k",
		"l",
		"m",
		"n",
		"o",
		"p",
		"q",
		"r",
		"s",
		"t",
		"u",
		"v",
		"w",
		"x",
		"y",
		"z"
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
			double monto;
			long dni;
			

			for (int i = 0; i < n; i++) {
				data1 = randNames[rand() % 20] + " " + randSur[rand() % 20];
				monto = (rand() % 80 + 20) + (float)((rand() % 99)/100);

				dni = rand() % 99999999 + 90000000;
				file << setw(20) << data1 << "," << monto << "." << rand() % 80+10 << "," << dni << "\n";
			}
		}

		file.close();


	
		file.open("dataset2.csv");
		if (file.is_open()) {
			string emp_users;
			string emp_passwords;
		


			for (int i = 0; i < n; i++) {
				emp_users = emp_names[rand() % 21] ;
				emp_passwords = emp_pass[rand() % 25] + emp_pass[rand() % 25] + emp_pass[rand() % 25] + emp_pass[rand() % 25] + emp_pass[rand() % 25] + emp_pass[rand() % 25] + emp_pass[rand() % 25] + emp_pass[rand() % 25] + emp_pass[rand() % 25] + emp_pass[rand() % 25];
			
				file << emp_users << "," << emp_passwords << "\n";
			}
		}

		file.close();

		cout << " Datos cargados con exito! :D\n";
		system("PAUSE");
	}

};
