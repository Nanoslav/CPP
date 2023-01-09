#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Osoba {
private:
	string jmeno;
	int vek;
public:
	Osoba() {}
	Osoba(string jmeno, int vek) {
		this->jmeno = jmeno;
		this->vek = vek;
	}
	string getName() { return this->jmeno; }
	int getAge() { return this->vek; }
};

int main() {
	string soubor = "data.txt";

	fstream file(soubor);

	if (file.fail()) {
		cout << "chyba nacitani souboru" << endl;
		system("pause");
		exit(1);
	}

	string jmeno;
	int vek;
	int pocet = 0;

	while (file >> jmeno >> vek) {
		pocet++;
	}

	Osoba *osoby = new Osoba[pocet];
	file.clear();
	file.seekg(0);

	for (int i = 0; i < pocet; i++) {
		file >> jmeno >> vek;
		osoby[i] = Osoba(jmeno, vek);
	}

	file.close();

	cout << "=======================================" << endl;
	cout << "		Vypis osob" << endl;
	cout << "=======================================" << endl;

	for (int i = 0; i < pocet; i++)
	{
		cout << i + 1 << ". osoba - jmeno: " << osoby[i].getName() << " - vek: " << osoby[i].getAge() << endl;
	}

	delete[] osoby;

	system("pause");
	return 0;
}