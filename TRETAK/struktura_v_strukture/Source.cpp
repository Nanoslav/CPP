#include <iostream>
#include <string>

using namespace std;

struct Osoba {
	string jmeno;
	int vek;
	Osoba(){}
	Osoba(string jmeno, int vek) {
		this->jmeno = jmeno;
		this->vek = vek;
	}
};

struct Student {
	Osoba osoba;
	int rocnik;
	Student(){}
	Student(string jmeno, int vek, int rocnik){
		this->rocnik = rocnik;
		/*this->osoba.jmeno = jmeno;
		this->osoba.vek = vek;*/
		this->osoba = Osoba(jmeno, vek);
	}
};

int main() {
	Student s1;
	s1.rocnik = 4;
	s1.osoba.jmeno = "Petr";
	s1.osoba.vek = 19;

	cout << "Student S1: " << s1.osoba.jmeno << ", vek: " << s1.osoba.vek << ", " << s1.rocnik << ". rocnik" << endl;

	Student s2("Jiri", 18, 3);

	cout << "Student S2: " << s2.osoba.jmeno << ", vek: " << s2.osoba.vek << ", " << s2.rocnik << ". rocnik" << endl;

	system("pause");
	return 0;
}