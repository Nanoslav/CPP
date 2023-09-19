#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Student {
private:
	string jmeno;
	int vek;
	int rocnik;
public:
	Student(){}
	Student(string jmeno, int vek, int rocnik) {
		this->jmeno = jmeno;
		this->vek = vek;
		this->rocnik = rocnik;
	}
	string getName() { return jmeno;  }
	int getAge() { return vek; }
	int getGrade() { return rocnik; }
};

int main() {

	int volba;
	const int N = 1000;


	Student studenti[N];
	int pocet = 0;
	string jmeno;
	int vek;
	int rocnik;
	bool isNew = false;

	ifstream file("studenti.txt");
	ofstream file2;

	if (file.fail()) {
		cout << "Evidence studentu je prazdna." << endl;
		system("pause");
	}
	else {
		while (file >> jmeno >> vek >> rocnik) {
			studenti[pocet] = Student(jmeno, vek, rocnik);
			pocet++;
		}
		file.close();
	}

	do {
		do {
			system("cls");
			cout << "======================================================" << endl;
			cout << "		EVIDENCE STUDENTU" << endl;
			cout << "======================================================" << endl << endl;

			cout << "===================================" << endl;
			cout << "	MENU PROGRAMU" << endl;
			cout << "===================================" << endl;
			cout << "1) Vypis vsech studentu" << endl;
			cout << "2) Pridani noveho studenta" << endl;
			cout << "3) Ukonceni programu" << endl;
			cout << "===================================" << endl << endl;

			cout << "Zadej volbu z menu (1-3): ";
			cin >> volba;

			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');
			}

		} while (volba < 1 || volba > 3 || cin.fail());

		system("cls");

		switch (volba) {
		case 1:
			cout << "	Vypis vsech studentu" << endl << endl;

			for (int i = 0; i < pocet; i++)
			{
				cout << i + 1 << ". student: " << studenti[i].getName() << ", vek: " << studenti[i].getAge() << ", " << studenti[i].getGrade() << ". rocnik" << endl;
			}

			system("pause");
			break;
		case 2:
			cout << "	Pridani noveho studenta" << endl << endl;
			if (N == pocet) {
				cout << "Kapacita studentu byla naplnena, nelze pridat dalsiho noveho studenta" << endl;
				system("pause");
			}
			else {
				cout << "Zadej jmeno: ";
				cin >> jmeno;
				cout << "Zadej vek: ";
				cin >> vek;
				cout << "Zadej rocnik: ";
				cin >> rocnik;
				studenti[pocet] = Student(jmeno, vek, rocnik);
				pocet++;
				isNew = true;
			}
			break;
		case 3:
			cout << "	Ukonceni programu" << endl;
			cout << "Program bude ukoncen" << endl;
			if (isNew) {
				file2.open("studenti.txt");
				for (int i = 0; i < pocet; i++)
				{
					file2 << studenti[i].getName() << " " << studenti[i].getAge() << " " << studenti[i].getGrade() << " " << endl;
				}
				file2.close();
				cout << "Byla provedena aktualizace dat" << endl;
			}
			system("pause");
			break;
		}

	} while (volba != 3);

	return 0;
}