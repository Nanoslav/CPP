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
};

//Kolik plnoletých mužù mìlo Kostka_jahoda?

int main() {

	const int N = 1000;
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

	int pocet = 0;

	for (int i = 0; i < index; i++)
	{
		if (osoby[i].getPohlavi() == "muz" && osoby[i].getAge() >= 18 && osoby[i].getZakusek() == "Kostka_jahoda") {
			pocet++;
		}
	}

	cout << "Celkem plnoletych muzu co melo zakusek Kostka_jahoda: " << pocet << endl;

	system("pause");
	return 0;
}