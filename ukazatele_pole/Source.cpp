#include <iostream>
#include <string>

using namespace std;

class Osoba {
private:
	string jmeno;
	int vek;
public:
	Osoba(){}
	Osoba(string jmeno, int vek) {
		this->jmeno = jmeno;
		this->vek = vek;
	}
	string getName() { return this->jmeno; }
	int getAge() { return this->vek; }
};

int main() {
	const int N = 5;
	int cisla[N] = {10,20,30,40,50};

	cout << "Hodnota prvni polozky: " << cisla[0] << endl;
	//cout << "Adresa pole cisla: " << &cisla << endl;
	cout << "Adresa pole cisla: " << cisla << endl;
	cout << "Adresa prvni polozky: " << &cisla[0] << endl;
	cout << "Adresa druhe polozky: " << &cisla[1] << endl;
	cout << "Hodnota prvni polozky: " << *cisla << endl;
	//=============================================================

	int pocet;
	cout << "Zadej pocet cisel: ";
	cin >> pocet;

	int *uk_pole_int = new int[pocet];

	for (int i = 0; i < pocet; i++) {
		uk_pole_int[i] = i * 2;
	}

	cout << "1. vypis cisel: " << endl;
	for (int i = 0; i < pocet; i++)
	{
		cout << uk_pole_int[i] << " ";
	}
	cout << endl;
	delete[] uk_pole_int;

	cout << "================================================" << endl;

	cout << "Zadej pocet cisel: ";
	cin >> pocet;

	uk_pole_int = new int[pocet];

	for (int i = 0; i < pocet; i++) {
		uk_pole_int[i] = i * 2;
	}

	cout << "2. vypis cisel: " << endl;
	for (int i = 0; i < pocet; i++)
	{
		cout << uk_pole_int[i] << " ";
	}
	cout << endl;

	/*
	// Pøeplnìní dynamické pamìti
	string *uk;
	while (true) {
		uk = new string[1000000];
		//delete[] uk;
	}
	*/


	system("pause");
	return 0;
}