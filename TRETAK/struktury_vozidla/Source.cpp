#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Vozidlo {
	string barva;
	string nazev;
	int rokV;
	int cena;
	Vozidlo(){}
	Vozidlo(string nazev, int rokV, int cena, string barva) {
		this->nazev = nazev;
		this->rokV = rokV;
		this->cena = cena;
		this->barva = barva;
	}
};

int main() {
	const int N = 1000;
	Vozidlo bazar[N];

	//ifstream file;
	//file.open("vozidla.txt");
	ifstream file("vozidla.txt");

	if (file.fail()) {
		cout << "chyba!";
		system("pause");
		exit(1);
	}

	string barva;
	string nazev;
	int rokV;
	int cena;
	int index = 0;

	while (file >> nazev >> rokV >> cena >> barva) {
		bazar[index] = Vozidlo(nazev, rokV, cena, barva);
		index++;
	}
	file.close();

	for (int i = 0; i < index; i++)
	{
		if (bazar[i].rokV == 2010 && bazar[i].barva == "cervena") {
			cout << bazar[i].nazev << ", " << bazar[i].rokV << ", cena: " << bazar[i].cena << ",-Kc, barva: " << bazar[i].barva << endl;
		}
	}
	
	system("pause");
	return 0;
}
