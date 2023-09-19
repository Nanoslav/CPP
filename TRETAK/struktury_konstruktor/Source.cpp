#include <iostream>
#include <string>

using namespace std;

struct Osoba {
	string jmeno;
	int vek;
	Osoba(){}
	Osoba(string jm, int v) {
		jmeno = jm;
		vek = v;
	}
};

int main() {
	int cislo = 12;
	const int KONSTANTA = 10;

	string jme;
	int ve;

	Osoba osoby[KONSTANTA];

	for (int i = 0; i < KONSTANTA; i++) {
		cout << "Zadej jmeno: ";
		cin >> jme;
		cout << "Zadej vek: ";
		cin >> ve;
		osoby[i] = Osoba(jme, ve);
	}

	for (int i = 0; i < KONSTANTA; i++) {
		cout << "jmeno: " << osoby[i].jmeno << ", vek: " << osoby[i].vek << endl;
	}

	//string jme;
	//int ve;
	//cout << "Zadej jmeno: ";
	//cin >> jme;
	//cout << "Zadej vek: ";
	//cin >> ve;

	//Osoba osoba(jme, ve);
	////osoba.jmeno = "Tomas";
	////osoba.vek = 20;

	//cout << "jmeno: " << osoba.jmeno << ", vek: " << osoba.vek << endl;

	system("pause");
	return 0;
}
