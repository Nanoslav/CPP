#include <iostream>
#include <string>
#include <list>
#include <fstream>

using namespace std;

class Osoba {
private:
	string jmeno;
	string pohlavi;
	int vek;
public:
	Osoba() {}
	Osoba(string jmeno, string pohlavi, int vek) {
		this->jmeno = jmeno;
		this->pohlavi = pohlavi;
		this->vek = vek;
	}
	string getName() { return this->jmeno; }
	string getSex() { return this->pohlavi; }
	int getAge() { return this->vek; }
};

int main() {
	
	list<Osoba> lide;
	string jmeno;
	string pohlavi;
	int vek;

	ifstream file("data.txt");

	if (file.fail()) {
		cout << "chyba!" << endl;
		system("pause");
		exit(1);
	}

	while (file >> jmeno >> pohlavi >> vek) {
		lide.push_back(Osoba(jmeno, pohlavi, vek));
	}

	file.close();

	int poradi = 1;
	for (list<Osoba>::iterator it = lide.begin(); it != lide.end(); it++) {
		cout << poradi << ". - " << it->getName() << ", pohlavi: " << it->getSex() << ", vek: " << it->getAge() << endl;
		poradi++;
	}

	cout << "=============================" << endl;

	for (list<Osoba>::iterator it = lide.begin(); it != lide.end(); it++) {
		if (it->getSex() == "zena" || it->getAge() >= 18) {
			lide.erase(it);
			it = lide.begin();
		}	
	}


	cout << "Muzi 18-: " << endl;

	poradi = 1;
	for (list<Osoba>::iterator it = lide.begin(); it != lide.end(); it++) {
		cout << poradi << ". - " << it->getName() << ", pohlavi: " << it->getSex() << ", vek: " << it->getAge() << endl;
		poradi++;
	}
	

	system("pause");
	return 0;
}