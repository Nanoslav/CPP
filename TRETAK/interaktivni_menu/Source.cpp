#include <iostream>
#include <string>

using namespace std;

int main() {

	int volba;

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
			cout << "3) Smazani studenta" << endl;
			cout << "4) Editace dat studenta" << endl;
			cout << "5) Vypis vsech plnoletych studentu" << endl;
			cout << "6) Ukonceni programu" << endl;
			cout << "===================================" << endl << endl;

			cout << "Zadej volbu z menu (1-6): ";
			cin >> volba;

			if (cin.fail()) {
				cin.clear();
				cin.ignore(10000, '\n');
			}

		} while (volba < 1 || volba > 6 || cin.fail());

		system("cls");

		switch (volba) {
		case 1:
			cout << "	Vypis vsech studentu" << endl << endl;
			system("pause");
			break;
		case 2:
			cout << "	Pridani noveho studenta" << endl << endl;
			system("pause");
			break;
		case 3:
			cout << "	Smazani studenta" << endl << endl;
			system("pause");
			break;
		case 4:
			cout << "	Editace dat studenta" << endl << endl;
			system("pause");
			break;
		case 5:
			cout << "	Vypis vsech plnoletych studentu" << endl << endl;
			system("pause");
			break;
		case 6:
			cout << "	Ukonceni programu" << endl;
			cout << "Program bude ukoncen" << endl;

			system("pause");
			break;
		}

	} while (volba != 6);

	return 0;
}