#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Osoba {
private:
	string jmeno;
	string pohlavi;
	string dort;
	int vek;
	int cena;
public:
	Osoba(){}
	Osoba(string jmeno, string pohlavi, string dort, int vek, int cena) {
		this->jmeno = jmeno;
		this->pohlavi = pohlavi;
		this->dort = dort;
		this->vek = vek;
		this->cena = cena;
	}
	string getJmeno() { return this->jmeno; };
	string getPohlavi() { return this->pohlavi; };
	string getDortik() { return this->dort; };
	int getVek() { return this->vek; };
	int getCena() { return this->cena; };
};

int main() {
	int volba;
	int volba2;
	string soubor = "dorty.txt";
	const int N = 1000;
	string jmeno;
	string pohlavi;
	string dort;
	int vek;
	int cena;
	int index = 0;
	int celkovaCena = 0;
	bool isNew = false;

	Osoba osoby[N];

	fstream file;
	ofstream file2;
	file.open(soubor);

	if (file.fail()) {
		cout << "Soubor nebyl nacten." << endl;
		system("pause");
		return 1;
	}

	while (file >> jmeno >> pohlavi >> dort >> vek >> cena) {
		osoby[index] = Osoba(jmeno, pohlavi, dort, vek, cena);
		index++;
	}

	file.close();

	do {

		system("cls");

		cout << "==================================" << endl;
		cout << "	EVIDENCE DORTIKU :3" << endl;
		cout << "==================================" << endl;

		cout << "1. Vypis vsech udaju" << endl;
		cout << "2. Pridani noveho udaje" << endl;
		cout << "3. Vypis celkove ceny dortu u muzu/zen" << endl;
		cout << "4. Vypis celkove ceny dortu" << endl;
		cout << "5. Ukonceni programu" << endl;
		
		cout << "==================================" << endl;
		cout << "Vyberte volbu: ";
		cin >> volba;

		system("cls");

		switch (volba) {
		case 1:
			cout << "	Vypis vsech udaju" << endl;
			cout << "==================================" << endl;
			for (int i = 0; i < index; i++)
			{
				cout << i + 1 << ". " << osoby[i].getJmeno() << ", pohlavi: " << osoby[i].getPohlavi() << ", dort: " << osoby[i].getDortik() << ", vek: " << osoby[i].getVek() << ", cena: " << osoby[i].getCena() << endl;
			}
			system("pause");
			break;
		case 2:
			cout << "	Pridani noveho udaje" << endl;
			cout << "==================================" << endl;
			if (N == index) {
				cout << "Celkova kapacita byla naplnena!" << endl;
			}
			else {
				cout << "Zadej jmeno: ";
				cin >> jmeno;
				cout << "Zadej pohlavi: ";
				cin >> pohlavi;
				cout << "Zadej dortik: ";
				cin >> dort;
				cout << "Zadej vek: ";
				cin >> vek;
				cout << "Zadej cenu dortiku: ";
				cin >> cena;
				osoby[index] = Osoba(jmeno, pohlavi, dort, vek, cena);
				index++;
				isNew = true;
				cout << "Zaznam byl vytvoren!" << endl;
			}
			system("pause");
			break;
		case 3:
			do {
				system("cls");
				cout << "	Vypis celkove ceny dortu u muzu/zen" << endl;
				cout << "==================================" << endl;
				cout << "1. Zeny" << endl << "2. Muzi" << endl << "3. Zpet do menu" << endl;
				cout << "==================================" << endl;
				cout << "Vyber volbu: ";
				cin >> volba2;

				system("cls");

				switch (volba2) {
				case 1:
					cout << "Vypis celkove ceny dortu u **zen**" << endl;
					cout << "==================================" << endl;
					for (int i = 0; i < index; i++)
					{
						if (osoby[i].getPohlavi() == "zena") {
							celkovaCena += osoby[i].getCena();
						}
					}
					cout << "Celkova cena dortiku u zen: " << celkovaCena << ",-Kc" << endl;
					celkovaCena = 0;
					system("pause");
					break;
				case 2:
					cout << "Vypis celkove ceny dortu u **muzu**" << endl;
					cout << "==================================" << endl;
					for (int i = 0; i < index; i++)
					{
						if (osoby[i].getPohlavi() == "muz") {
							celkovaCena += osoby[i].getCena();
						}
					}
					cout << "Celkova cena dortiku u muzu: " << celkovaCena << ",-Kc" << endl;
					celkovaCena = 0;
					system("pause");
					break;
				case 3:
					break;
				}

			} while (volba2 != 3);
			break;
		case 4:
			cout << "	Vypis celkove ceny dortu" << endl;
			cout << "==================================" << endl;
			for (int i = 0; i < index; i++)
			{
				celkovaCena += osoby[i].getCena();
			}
			cout << "Celkova cena dortiku: " << celkovaCena << ",-Kc" << endl;
			celkovaCena = 0;
			system("pause");
			break;
		case 5:
			cout << "	Ukonceni programu" << endl;
			cout << "==================================" << endl;
			cout << "Program bude ukoncen..." << endl;
			if (isNew) {
				cout << "Byla zjistena uprava dat, ukladam zmeny..." << endl;

				file2.open(soubor);

				for (int i = 0; i < index; i++)
				{
					file2 << osoby[i].getJmeno() << " " << osoby[i].getPohlavi() << " " << osoby[i].getDortik() << " " << osoby[i].getVek() << " " << osoby[i].getCena() << endl;
				}

				cout << "Data ulozena!" << endl;

			}
			system("pause");
			break;
		}

	} while (volba != 5);

}