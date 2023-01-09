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
	cout << "============================================================" << endl;
	cout << "			Zadej pocet osob: ";
	int pocet;
	cin >> pocet;
	cout << "============================================================" << endl;

	string jmeno;
	int vek;

	Osoba *uk = new Osoba[pocet];

	for (int i = 0; i < pocet; i++)
	{
		cout << "Zadej jmeno " << i + 1 << ". osoby: ";
		cin >> jmeno;
		cout << "Zadej vek " << i + 1 << ". osoby: ";
		cin >> vek;
		uk[i] = Osoba(jmeno, vek);
		cout << "============================================================" << endl;
	}

	cout << "			Vypis osob" << endl;
	cout << "============================================================" << endl;

	for (int i = 0; i < pocet; i++)
	{
		cout << i + 1 << ". osoba - jmeno: " << uk[i].getName() << " - vek: " << uk[i].getAge() << endl;
	}

	system("pause");
	return 0;
}