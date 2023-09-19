#include <iostream>
#include <string>
#include <list>
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
	
	list<Osoba> lide;
	string jmeno;
	int vek;

	ifstream file("data.txt");

	if (file.fail()) {
		cout << "chyba!" << endl;
		system("pause");
		exit(1);
	}

	while (file >> jmeno >> vek) {
		lide.push_back(Osoba(jmeno, vek));
	}

	file.close();

	int poradi = 1;
	for (list<Osoba>::iterator it = lide.begin(); it != lide.end(); it++) {
		cout << poradi << ". - " << it->getName() << ", vek: " << it->getAge() << endl;
		poradi++;
	}

	int volba;

	do {

		if (lide.size() == 0) {
			cout << "Nejsou zadne osoby!" << endl;
			break;
		}

		cout << "Zadej cislo (0 pro ulozeni a ukonceni): ";
		cin >> volba;

		if (volba == 0) break;

		int nPoradi = 1;
		for (list<Osoba>::iterator it = lide.begin(); it != lide.end(); it++) {
			if (volba == nPoradi) {
				lide.erase(it);
				break;
				// it = lide.begin();
			}
			nPoradi++;
		}

		cout << "Osoba s cislem poradi " << volba << " byla smazana!" << endl;

		poradi = 1;
		for (list<Osoba>::iterator it = lide.begin(); it != lide.end(); it++) {
			cout << poradi << ". - " << it->getName() << ", vek: " << it->getAge() << endl;
			poradi++;
		}

	} while (volba != 0);

	ofstream file2("newData.txt");

	for (list<Osoba>::iterator it = lide.begin(); it != lide.end(); it++) {
		file2 << it->getName() << " " << it->getAge() << endl;
	}

	file2.close();

	cout << "Osoby byly ulozeny do souboru!" << endl;

	system("pause");
	return 0;
}