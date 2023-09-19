#include <iostream>
#include <string>

using namespace std;

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
	string volba;
	string nazev;
	string barva;
	int rokV;
	int pocet = 0;

	Vozidlo *tmp_vozidla;
	Vozidlo *vozidla = new Vozidlo[pocet];

	while(true){
		cout << "Chcete pridat novy zaznam: (ano/ne) ";
		cin >> volba;

		if (volba != "ano") {
			break;
		}

		tmp_vozidla = new Vozidlo[pocet];

		for (int i = 0; i < pocet; i++)
		{
			tmp_vozidla[i] = vozidla[i];
		}
		delete[] vozidla;

		pocet++;
		vozidla = new Vozidlo[pocet];

		for (int i = 0; i < pocet - 1; i++) {
			vozidla[i] = tmp_vozidla[i];
		}
		delete[] tmp_vozidla;

		cout << "Zadej nazev: ";
		cin >> nazev;
		cout << "Zadej barvu: ";
		cin >> barva;
		cout << "Zadej rok vyroby: ";
		cin >> rokV;
		cout << "Zaznam pridan!" << endl;
		system("cls");

		vozidla[pocet - 1] = Vozidlo(nazev, barva, rokV);

	}

	cout << "========== Vypis ==========" << endl;
	for (int i = 0; i < pocet; i++)
	{
		cout << i + 1 << ". nazev: " << vozidla[i].getName() << ", barva: " << vozidla[i].getColor() << ", rok vyroby: " << vozidla[i].getYear() << endl;
	}

	system("pause");
	return 0;
}