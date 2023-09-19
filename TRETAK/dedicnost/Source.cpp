#include <string>
#include <iostream>

using namespace std;

class Osoba {
protected:
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

class Zamestnanec : public Osoba {
private:
	int plat;
public:
	Zamestnanec(){}
	Zamestnanec(string jmeno, int vek, int plat){
		this->plat = plat;
		this->jmeno = jmeno;
		this->vek = vek;
	}
	void getInfo() {
		cout << "Zamestnanec: " << this->jmeno << " (" << this->vek << "), plat: " << this->plat << endl;
	}
};

class Student : public Osoba {
private:
	string predmet;
public:
	Student() {}
	Student(string jmeno, int vek, string predmet) : Osoba(jmeno, vek){
		this->predmet = predmet;
	}
	string getSubject() { return this->predmet; }
	void getInfo() {
		cout << "Student: " << getName() << " (" << getAge() << "), predmet: " << getSubject() << endl;
	}
};

int main() {
	Student s1 = Student("Petr", 17, "AJ");
	Zamestnanec z1 = Zamestnanec("Vojta", 20, 5000000000000);

	//cout << "Jmeno studenta: " << s1.getName() << endl;
	//cout << "Vek studenta: " << s1.getAge() << endl;
	//cout << "Predmet studenta: " << s1.getSubject() << endl;
	
	s1.getInfo();
	z1.getInfo();


	return 0;
}