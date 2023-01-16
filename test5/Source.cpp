#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//vypis
//vypis podle barvy
//rok vyroby 2000

class Vozidlo {
private:
	string nazev;
	string barva;
	int rokV;
public:
	Vozidlo(){}
	Vozidlo(string nazev, string barva, int rokV) {
		this->nazev = nazev;
		this->barva = barva;
		this->rokV = rokV;
	}
	string getName() { return this->nazev; }
	string getColor() { return this->barva; }
	int getYear() { return this->rokV; }
};

int main() {

	int volba;
	int pocet = 0;
	string nazev;
	string barva;
	int rokV;
	string selectedColor;
	int selectedYear;
	int tempCount = 0;

	
	fstream file("vozidla.txt");

	while (file >> nazev >> barva >> rokV) {
		pocet++;
	}

	Vozidlo *vozidla = new Vozidlo[pocet];

	file.clear();
	file.seekg(0);

	for (int i = 0; i < pocet; i++) {
		file >> nazev >> barva >> rokV;
		vozidla[i] = Vozidlo(nazev, barva, rokV);
	}

	file.close();

	do {

		system("cls");

		cout << "===================================" << endl;
		cout << "	EVIDENCE FOFRNIK v1" << endl;
		cout << "===================================" << endl;
		cout << "1) Vypis vsech vozidel" << endl;
		cout << "2) Vypis vozidel podle barvy" << endl;
		cout << "3) Vypis vozidel podle roku vyroby" << endl;
		cout << "4) Ukoncit program" << endl;
		cout << "===================================" << endl;
		cout << "Zvoleno: ";
		cin >> volba;

		system("cls");

		switch (volba) {
		case 1:
			cout << "===================================" << endl;
			cout << "	VYPIS VSECH VOZIDEL" << endl;
			cout << "===================================" << endl;
			for (int i = 0; i < pocet; i++) {
				cout << i + 1 << ". Nazev: " << vozidla[i].getName() << ", barva: " << vozidla[i].getColor() << ", rok vyroby: " << vozidla[i].getYear() << endl;
			}
			system("pause");
			break;
		case 2:
			cout << "===================================" << endl;
			cout << "	VYPIS VOZIDEL PODLE BARVY" << endl;
			cout << "===================================" << endl;
			cout << "Zadej barvu: ";
			cin >> selectedColor;

			for (int i = 0; i < pocet; i++) {
				if (vozidla[i].getColor() == selectedColor) {
					tempCount++;
					cout << tempCount << ". Nazev: " << vozidla[i].getName() << ", barva: " << vozidla[i].getColor() << ", rok vyroby: " << vozidla[i].getYear() << endl;
				}
			}

			if (tempCount == 0) {
				cout << "Zadne vozidlo s barvou '" << selectedColor << "' nebylo nalezeno" << endl;
			}

			tempCount = 0;

			system("pause");
			break;
		case 3:
			cout << "===================================" << endl;
			cout << "	VYPIS VOZIDEL PODLE ROKU VYROBY" << endl;
			cout << "===================================" << endl;
			cout << "Zadej rok vyroby: ";
			cin >> selectedYear;

			for (int i = 0; i < pocet; i++) {
				if (vozidla[i].getYear() == selectedYear) {
					tempCount++;
					cout << tempCount << ". Nazev: " << vozidla[i].getName() << ", barva: " << vozidla[i].getColor() << ", rok vyroby: " << vozidla[i].getYear() << endl;
				}
			}

			if (tempCount == 0) {
				cout << "Zadne vozidlo s rokem vyroby '" << selectedYear << "' nebylo nalezeno" << endl;
			}

			tempCount = 0;

			system("pause");
			break;
		case 4:
			cout << "===================================" << endl;
			cout << "	UKONCENI PROGRAMU" << endl;
			cout << "===================================" << endl;
			cout << "Program bude ukoncen..." << endl;
			delete[] vozidla;
			system("pause");
			break;
		}

	} while (volba != 4);

}