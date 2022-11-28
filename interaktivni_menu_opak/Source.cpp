#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Vozidlo {
private:
	string nazev;
	string barva;
	string mesic;
	int rokV;
	int cena;
public:
	Vozidlo() {};
	Vozidlo(string nazev, string barva, string mesic, int rokV, int cena) {
		this->nazev = nazev;
		this->barva = barva;
		this->mesic = mesic;
		this->rokV = rokV;
		this->cena = cena;
	};
	string getName() { return this->nazev; };
	string getColor() { return this->barva; };
	string getMonth() { return this->mesic; };
	int getYear() { return this->rokV; };
	int getPrice() { return this->cena; };
};

int main() {
	int volba;
	string nazev;
	string barva;
	string mesic;
	int rokV;
	int cena;
	int index = 0;
	bool update = false;

	string mesicInput;
	int rokInput;
	int count = 0;
	bool found = false;

	const int N = 1000;
	Vozidlo vozidla[N];

	fstream file("vozidla.txt");
	ofstream file2;

	if (file.fail()) {
		cout << "Chyba s nacitanim souboru" << endl;
		system("pause");
		exit(1);
	}
	else {
		while (file >> nazev >> barva >> mesic >> rokV >> cena) {
			vozidla[index] = Vozidlo(nazev, barva, mesic, rokV, cena);
			index++;
		}
		file.close();
	}

	do {
		system("cls");
		cout << "========================================" << endl;
		cout << "			EVIDENCE VOZIDEL				" << endl;
		cout << "========================================" << endl;

		cout << "	1. Vypis vsech vozidel" << endl;
		cout << "	2. Pridani noveho vozidla" << endl;
		cout << "	3. Vypis vozidel podle mesicu" << endl;
		cout << "	4. Vypis vozidel podle roku vyroby" << endl;
		cout << "	5. Ukonceni programu" << endl;

		cout << "========================================" << endl;

		cout << "Zadej volbu: ";
		cin >> volba;

		system("cls");

		switch (volba) {
		case 1:
			cout << "		Vypis vsech vozidel" << endl;
			cout << "========================================" << endl;

			for (int i = 0; i < index; i++)
			{
				cout << i + 1 << ") Nazev: " << vozidla[i].getName() << ", barva: " << vozidla[i].getColor() << ", mesic: " << vozidla[i].getMonth() << ", rok vyroby: " << vozidla[i].getYear() << ", cena: " << vozidla[i].getPrice() << endl;
			}

			system("pause");
			break;
		case 2:
			cout << "		Pridani noveho vozidla" << endl;
			cout << "========================================" << endl;
			if (N == index) {
				cout << "Kapacita naplnena!" << endl;
			}
			else {
				cout << "Zadej nazev: ";
				cin >> nazev;
				cout << "Zadej barvu: ";
				cin >> barva;
				cout << "Zadej mesic: ";
				cin >> mesic;
				cout << "Zadej rok vyroby: ";
				cin >> rokV;
				cout << "Zadej cenu: ";
				cin >> cena;
				vozidla[index] = Vozidlo(nazev, barva, mesic, rokV, cena);
				index++;
				cout << "Zaznam pridan!" << endl;
				update = true;
			}
			system("pause");
			break;
		case 3:
			cout << "		Vypis vozidle podle mesicu" << endl;
			cout << "========================================" << endl;
			cout << "Zadej mesic (slovy): ";
			cin >> mesicInput;

			for (int i = 0; i < index; i++)
			{
				if (vozidla[i].getMonth() == mesicInput) {
					cout << count + 1 << ") Nazev: " << vozidla[i].getName() << ", barva: " << vozidla[i].getColor() << ", mesic: " << vozidla[i].getMonth() << ", rok vyroby: " << vozidla[i].getYear() << ", cena: " << vozidla[i].getPrice() << endl;
					count++;
					found = true;
				}
			}

			if (!found) cout << "Zadny zaznam nebyl nalezen" << endl;
			count = 0;
			found = false;

			system("pause");
			break;
		case 4:
			cout << "	Vypis vozidel podle roku vyroby" << endl;
			cout << "========================================" << endl;
			cout << "Zadej rok vyroby: ";
			cin >> rokInput;

			for (int i = 0; i < index; i++)
			{
				if (vozidla[i].getYear() == rokInput) {
					cout << count + 1 << ") Nazev: " << vozidla[i].getName() << ", barva: " << vozidla[i].getColor() << ", mesic: " << vozidla[i].getMonth() << ", rok vyroby: " << vozidla[i].getYear() << ", cena: " << vozidla[i].getPrice() << endl;
					count++;
					found = true;
				}
			}

			if (!found) cout << "Zadny zaznam nebyl nalezen" << endl;
			count = 0;
			found = false;

			system("pause");
			break;
		case 5:
			cout << "		Ukonceni programu" << endl;
			cout << "========================================" << endl;
			if (update) {
				file2.open("vozidla.txt");
				for (int i = 0; i < index; i++)
				{
					file2 << vozidla[i].getName() << " " << vozidla[i].getColor() << " " << vozidla[i].getMonth() << " " << vozidla[i].getYear() << " " << vozidla[i].getPrice() << endl;
				}
				file2.close();
				cout << "Probehla aktualizace dat!" << endl;
			}
			cout << "Program bude ukoncen" << endl;
			system("pause");
			break;
		}

	} while (volba != 5);

	return 0;
}