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
	Osoba osoba = Osoba("Jana", 18);
	cout << "Jmeno: " << osoba.getName() << endl;
	cout << "Vek: " << osoba.getAge() << endl;
	//=================================================
	string text = "toto je text";
	string *uk_string = &text;

	string p_name;
	int p_age;
	cout << "Zadej jmeno: ";
	cin >> p_name;
	cout << "Zadej vek: ";
	cin >> p_age;

	Osoba *uk_osoba = new Osoba(p_name, p_age);
	cout << "Jmeno: " << (*uk_osoba).getName() << endl;
	cout << "Jmeno: " << uk_osoba->getName() << endl;
	cout << "Vek: " << uk_osoba->getAge() << endl;

	delete uk_osoba;

	system("pause");
	return 0;
}