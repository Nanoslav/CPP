#include <iostream>
#include <string>

using namespace std;

struct Student {
	string jmeno;
	int vek;
	int rocnik;
	Student(){}
	Student(string jmeno, int vek, int rocnik) {
		this->jmeno = jmeno;
		this->vek = vek;
		this->rocnik = rocnik;
	}
};

int main() {

	const int N = 500;

	int pocet;
	cout << "Zadej pocet studentu (max. " << N << "): ";
	cin >> pocet;

	while (pocet < 1 || pocet > N || cin.fail()) {
		system("cls");
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Zadej pocet studentu (max. " << N << "): ";
		cin >> pocet;
		system("cls");
	}

	Student studenti[N];

	string jm;
	int v;
	int r;

	for (int i = 0; i < pocet; i++)
	{
		cout << "Zadej jmeno " << i + 1 << ". osoby: ";
		cin >> jm;
		cout << "Zadej vek " << i + 1 << ". osoby: ";
		cin >> v;
		cout << "Zadej rocnik " << i + 1 << ". osoby: ";
		cin >> r;
		studenti[i] = Student(jm, v, r);
		cout << "======================================" << endl;
	}

	system("cls");

	for (int i = 0; i < pocet; i++)
	{
		cout << i + 1 << ". student - jmeno: " << studenti[i].jmeno << ", vek: " << studenti[i].vek << ", rocnik: " << studenti[i].rocnik << endl;
	}

	system("pause");
	return 0;
}