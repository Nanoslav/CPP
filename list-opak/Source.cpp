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

	for (list<Osoba>::iterator it = lide.begin(); it != lide.end(); it++) {
		
	}

	system("pause");
	return 0;
}