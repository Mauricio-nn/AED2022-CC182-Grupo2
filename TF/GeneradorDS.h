#pragma once
#include"Librerias.h"

const int ch_MAX = 52;

class csvGen {
private:
public:
	csvGen() {}
	~csvGen() {}
	string RandomString(int ch) {
		char alpha[ch_MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
							  'h', 'i', 'j', 'k', 'l', 'm', 'n',
							  'o', 'p', 'q', 'r', 's', 't', 'u',
							  'v', 'w', 'x', 'y', 'z',
							  'A', 'B', 'C', 'D', 'E', 'F', 'G',
							  'H', 'I', 'J', 'K', 'L', 'M','N',
							  'O', 'P', 'Q', 'R', 'S', 'T', 'U',
							  'V', 'W', 'X', 'Y', 'Z' };
		string result = "";
		for (int i = 0; i < ch; i++)
			result = result + alpha[rand() % ch_MAX];

		return result;
	}
	void generate_dataset() {
		int n = rand() % 1000000 + 200000;
		//int n = 1000000;
		int counter = 0;
		cout << "Generating dataset . . .\nProgress: 0%";

		ofstream file;
		file.open("Dependencies//generated_data_set.csv");
		if (file.is_open()) {
			int data1;
			string data2, data3, data4;
			for (int i = 0; i < n; i++) {
				data1 = rand() % 99999999 + 1;
				data2 = RandomString(rand() % 10 + 3);
				file << data2 << "," << data1 << "\n";

				counter++;
				if (counter > 8000) {
					counter = 0;
					system("CLS");
					cout << "Generating dataset . . .\n";
					cout << "Progress: " << int((100 * i) / n) << "%";
				}
			}
		}
		file.close();

		cout << "\nDataset generated\n\n";
	}

};