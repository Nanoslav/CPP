#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {
	map<string, string> dictionary;

	ifstream file("dictionary.txt");
	ofstream file2;

	if (file.fail()) {
		cout << "Error opening file" << endl;
		cout << "Dictionary is empty" << endl;
		system("pause");
	}

	string cz, en, word;
	int volba, pozice, poradi;
	bool aktualizace = false;

	while (file >> cz >> en) {
		dictionary[cz] = en;
	}

	file.close();

	do {
		system("cls");
		cout << " Slovnik [cz-en] [en-cz]" << endl << endl;
		cout << "Ovladani:" << endl;
		cout << "\t[1] - Vypis slovicek" << endl;
		cout << "\t[2] - Pridani slovicek" << endl;
		cout << "\t[3] - Smazani slovicek" << endl;
		cout << "\t[4] - Editace slovicek" << endl;
		cout << "\t[5] - Preklad slovicek" << endl;
		cout << "\t[6] - Ukonceni programu" << endl << endl;

		cout << "Vyber: ";
		cin >> volba;

		system("cls");
		switch (volba) {
		case 1:
			cout << "Vypis slovicek" << endl << endl;
			cout << "==========================" << endl;
			for (map<string, string>::iterator it = dictionary.begin(); it != dictionary.end(); it++) {
				cout << it->first << " - " << it->second << endl;
			}
			system("pause");
			break;
		case 2:
			cout << "Pridani slovicek" << endl << endl;
			cout << "==========================" << endl;
			cout << "Slovo cesky: ";
			cin >> cz;
			cout << "Slovo anglicky: ";
			cin >> en;
			dictionary[cz] = en;
			aktualizace = true;
			break;
		case 3:
			cout << "Smazani slovicek" << endl << endl;
			cout << "==========================" << endl;

			poradi = 1;
			for (map<string, string>::iterator it = dictionary.begin(); it != dictionary.end(); it++) {
				cout << poradi << ": " << it->first << " - " << it->second << endl;
				poradi++;
			}
			cout << "==========================" << endl;
			cout << "Vyber slovo ktere chces smazat: ";
			cin >> pozice;

			poradi = 1;
			for (map<string, string>::iterator it = dictionary.begin(); it != dictionary.end(); it++) {
				if (pozice == poradi) {
					dictionary.erase(it);
					aktualizace = true;
					break;
				}
				poradi++;
			}

			break;
		case 4:
			cout << "Editace slovicek" << endl << endl;
			cout << "==========================" << endl;
			cout << "Zadej slovicko pro editaci:";
			cin >> word;

			for (map<string, string>::iterator it = dictionary.begin(); it != dictionary.end(); it++) {
				if (word == it->first) {
					cout << "Zadej nove ceske slovicko: ";
					cin >> cz;
					dictionary[cz] = dictionary[word];
					dictionary.erase(it->first);
					aktualizace = true;
					break;
				}
				else if (word == it->second) {
					cout << "Zadej nove anglicke slovicko: ";
					cin >> en;
					dictionary[it->first] = en;
					aktualizace = true;
					break;
				}
			}

			break;
		case 5:
			while (true) {
				system("cls");
				cout << "Preklad slovicek" << endl << endl;
				cout << "==========================" << endl;
				cout << "Zadej slovicko k prekladu: " << endl;
				cout << "(Pro ukonceni prekladu zadej znak [*])" << endl;
				cout << "	>>v> ";
				cin >> word;


				if (word == "*") {
					break;
				}
			
				for (map<string, string>::iterator it = dictionary.begin(); it != dictionary.end(); it++) {
					if (word == it->first) {
						cout << it->first << " - " << it->second << endl;
					}
					else if (word == it->second) {
						cout << it->second << " - " << it->first << endl;
					}
				}
				system("pause");
			}
			
			break;

		case 6:
			cout << "Ukonceni programu" << endl << endl;
			cout << "==========================" << endl;
			
			if (aktualizace) {
				cout << "Zmena slovniku zjistena\nSlovnicek bude aktualizovan" << endl;

				file2.open("dictionary.txt");

				for (map<string, string>::iterator it = dictionary.begin(); it != dictionary.end(); it++) {
					file2 << it->first << " " << it->second << endl;
				}

				file2.close();

				cout << "Slovnicek byl aktualizovan!" << endl;

			}

			cout << "Ukoncuji program...";

			break;
		}
	} while (volba != 6);

	return 0;
}