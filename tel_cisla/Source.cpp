//#include <iostream>
//#include <string>
//#include <vector>
//#include <ctime>
//#include <fstream>
//
//using namespace std;
//
//string generujCislo() {
//	string cislo = "";
//	for (int i = 0; i < 6; i++) {
//		cislo += to_string((rand() % 10));
//	}
//
//	return cislo;
//}
//
//int main() {
//	string predvolba;
//	int cislo;
//	int index;
//	vector<string> predvolby;
//
//	ifstream file("predvolby.txt");
//	ofstream file2;
//
//	while (file >> predvolba) {
//		predvolby.push_back(predvolba);
//	}
//
//	file.close();
//
//	srand(time(NULL));
//
//	int pocet;
//	cout << "Zadej pocet tel. cisel: ";
//	cin >> pocet;
//
//	file2.open("cisla.txt");
//
//	for (int i = 0; i < pocet; i++) {
//		string cislo2 = "";
//		cislo2 += "+420" + predvolby[rand() % predvolby.size()];
//		for (int j = 0; j < 6; j++) {
//			cislo2 += to_string(rand() % 10);
//		}
//		file2 << cislo2 << endl;
//		cislo2 = "";
//	}
//
//	file2.close();
//
//	system("pause");
//	return 0;
//}