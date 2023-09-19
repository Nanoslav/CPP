#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Zamestnanec {
	string jmeno;
	string pozice;
	int plat;
	Zamestnanec(){}
	Zamestnanec(string jmeno, string pozice, int plat) {
		this->jmeno = jmeno;
		this->pozice = pozice;
		this->plat = plat;
	}
};

int main() {

	const int N = 100;
	Zamestnanec zamestnanci[N];

	ifstream file("zamestnanci.txt");

	if (file.fail()) {
		cout << "chyba!";
		system("pause");
		exit(1);
	}

	string jmeno;
	string pozice;
	int plat;

	int index = 0;

	while (file >> jmeno >> pozice >> plat) {
		zamestnanci[index] = Zamestnanec(jmeno, pozice, plat);
		index++;
	}

	file.close();

	int platUredniku = 0;
	int platVedoucich = 0;

	for (int i = 0; i < index; i++)
	{
		if (zamestnanci[i].pozice == "vedouci") {
			platVedoucich += zamestnanci[i].plat;
			cout << zamestnanci[i].jmeno << " - " << zamestnanci[i].pozice << ", plat: " << zamestnanci[i].plat << ",- Kc" << endl;
		}
	}

	cout << "=====================================" << endl;
	cout << "Suma platu vsech uredniku: " << platVedoucich << ",- Kc" << endl << endl
		;

	for (int i = 0; i < index; i++)
	{
		if (zamestnanci[i].pozice == "urednik") {
			platUredniku += zamestnanci[i].plat;
			cout << zamestnanci[i].jmeno << " - " << zamestnanci[i].pozice << ", plat: " << zamestnanci[i].plat << ",- Kc" << endl;
		}
	}

	cout << "=====================================" << endl;
	cout << "Suma platu vsech uredniku: " << platUredniku << ",- Kc" << endl << endl;

	system("pause");
	return 0;
}