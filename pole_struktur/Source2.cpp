#include <string>
#include <iostream>

using namespace std;

struct Vozidlo {
	string nazev;
	string barva;
	int rokV;
	Vozidlo() {}
	Vozidlo(string nazev, string barva, int rokV) {
		this->nazev = nazev;
		this->barva = barva;
		this->rokV = rokV;
	}
};

int main() {
	const int N = 3;
	Vozidlo bazar[N];

	string nazev;
	string barva;
	int rokV;
	
	for (int i = 0; i < N; i++)
	{
		cout << "Zadej nazev: ";
		cin >> nazev;
		cout << "Zadej barvu: ";
		cin >> barva;
		cout << "Zadej rok vyroby: ";
		cin >> rokV;
		bazar[i] = Vozidlo(nazev, barva, rokV);
	}

	system("cls");

	for (int i = 0; i < N; i++)
	{
		cout << i + 1 << ". vozidlo - Nazev: " << bazar[i].nazev << ", barva: " << bazar[i].barva << ", rok vyroby: " << bazar[i].rokV << endl;
	}

	system("pause");
	return 0;
}