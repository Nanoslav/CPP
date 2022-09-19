#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {

	fstream file;
	file.open("studenti.txt");

	if (file.fail()) {
		cout << "Error!";
		system("pause");
		return 1;
	}

	string jmeno;
	int rocnik, vek;
	int prvniRocnik = 0, druhyRocnik = 0, tretiRocnik = 0, ctvrtyRocnik = 0;
	int soucetVeku = 0, pocetStudentu = 0;

	ofstream zapis;
	zapis.open("studenti_new.txt");

	while (file >> jmeno >> rocnik >> vek) {
		zapis << jmeno << " " << rocnik << " " << vek << endl;
		pocetStudentu++;
		soucetVeku += vek;
		if (rocnik == 1) {
			prvniRocnik++;
		}
		else if (rocnik == 2) {
			druhyRocnik++;
		}
		else if (rocnik == 3) {
			tretiRocnik++;
		}
		else if (rocnik == 4) {
			ctvrtyRocnik++;
		}
	}
	zapis.close();

	cout << "---------------------------------------------" << endl;
	zapis.open("studenti_statistiky.txt");
	zapis << "Pocet studentu: " << pocetStudentu << endl;
	zapis << "Prumerny vek studentu: " << (double)soucetVeku / pocetStudentu << endl;
	zapis << "Pocet studentu v 1. rocniku: " << prvniRocnik << endl;
	zapis << "Pocet studentu v 2. rocniku: " << druhyRocnik << endl;
	zapis << "Pocet studentu v 3. rocniku: " << tretiRocnik << endl;
	zapis << "Pocet studentu v 4. rocniku: " << ctvrtyRocnik << endl;
	zapis.close();

	file.close();

	system("pause");
	return 0;
}
