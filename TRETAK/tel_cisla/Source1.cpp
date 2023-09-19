//#include <string>
//#include <iostream>
//#include <vector>
//#include <fstream>
//#include <ctime>
//
//using namespace std;
//
//int main() {
//	vector<string> contacts;
//	ifstream file("cisla.txt");
//
//	string phone;
//	while (file >> phone) {
//		contacts.push_back(phone);
//	}
//	file.close();
//
//	cout << "Zadej tel. cislo ve tvaru +420XXXXXXXXX: ";
//	cin >> phone;
//
//	ofstream file2("komunikace.txt");
//	int pocet = 100000;
//	for (int i = 0; i < pocet; i++)
//	{
//		if (rand() % 2) {
//			file2 << phone << " " << contacts[rand() % contacts.size()];
//		}
//		else {
//			file2 << contacts[rand() % contacts.size()] << " " << phone;
//		}
//		file2 << " ";
//		if (rand() % 2) {
//			file2 << "SMS " << rand() % 3 + 1 << endl;
//		}
//		else {
//			file2 << "HOVOR " << rand() % 3600 + 1 << endl;
//		}
//	}
//
//	file2.close();
//
//	system("pause");
//	return 0;
//}