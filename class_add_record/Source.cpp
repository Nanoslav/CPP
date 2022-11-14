#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Osoba {
private:
	string jmeno;
	string pohlavi;
	string zakusek;
	int vek;
public:
	Osoba() {}
	Osoba(string jmeno, string pohlavi, string zakusek, int vek) {
		this->jmeno = jmeno;
		this->pohlavi = pohlavi;
		this->zakusek = zakusek;
		this->vek = vek;
	}
	int getAge() {
		return this->vek;
	}
	string getZakusek() {
		return this->zakusek;
	}
	string getPohlavi() {
		return this->pohlavi;
	} 
	string getName() {
		return this->jmeno;
	}
};

//Kolik plnoletých mužù mìlo Kostka_jahoda?

int main() {

	const int N = 12;
	Osoba osoby[N];

	ifstream file("test.txt");

	if (file.fail()) {
		cout << "Chyba s nacitanim souboru";
		system("pause");
		exit(1);
	}

	string jmeno;
	string pohlavi;
	string zakusek;
	int vek;
	int index = 0;

	while (file >> jmeno >> pohlavi >> zakusek >> vek) {
		osoby[index] = Osoba(jmeno, pohlavi, zakusek, vek);
		index++;
	}

	file.close();

	for (int i = 0; i < index; i++)
	{
		cout << i + 1 << ". osoba, jmeno: " << osoby[i].getName() << ", pohlavi: " << osoby[i].getPohlavi() << ", zakusek: " << osoby[i].getZakusek() << ", vek: " << osoby[i].getAge() << endl;
	}

	string volba;

	while (true) {
		if (N == index) {
			cout << "Je naplnena kapacita pole..." << endl;
			break;
		}else{
			cout << "Prejete si pridat novou osobu? [a/n]: ";
			cin >> volba;
			if (volba == "n") {
				for (int i = 0; i < index; i++)
				{
					cout << i + 1 << ". osoba, jmeno: " << osoby[i].getName() << ", pohlavi: " << osoby[i].getPohlavi() << ", zakusek: " << osoby[i].getZakusek() << ", vek: " << osoby[i].getAge() << endl;
				}
				break;
			}
			cout << "Zadej jmeno: ";
			cin >> jmeno;
			cout << "Zadej pohlavi: ";
			cin >> pohlavi;
			cout << "Zadej zakusek: ";
			cin >> zakusek;
			cout << "Zadej vek: ";
			cin >> vek;
			osoby[index] = Osoba(jmeno, pohlavi, zakusek, vek);
			index++;
		}
	}

	system("pause");
	return 0;
}