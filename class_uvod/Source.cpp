#include <iostream>
#include <string>

using namespace std;

class Osoba {
private:
	string jmeno;
	int vek;
public:
	Osoba(){}
	Osoba(string jmeno, int vek) {
		this->jmeno = jmeno;
		this->vek = vek;
	}
	void setName(string jmeno) {
		this->jmeno = jmeno;
	}
	void setAge(int vek) {
		this->vek = vek;
	}
	string showName() {
		return this->jmeno;
	}
	int showAge() {
		return this->vek;
	}
};

int main() {

	const int N = 100;

	Osoba osoby[N];
	int pocet;
	cout << "Zadej pocet lidi (max. " << N << "): ";
	cin >> pocet;

	string pJmeno;
	int pVek;
	for (int i = 0; i < pocet; i++)
	{
		cout << "Zadej jmeno: ";
		cin >> pJmeno;
		cout << "Zadej vek: ";
		cin >> pVek;
		osoby[i] = Osoba(pJmeno, pVek);
		system("cls");
	}

	for (int i = 0; i < pocet; i++)
	{
		if (osoby[i].showAge() >= 18) {
			cout << i + 1 << ". jmeno: " << osoby[i].showName() << ", vek: " << osoby[i].showAge() << endl;
		}
		//cout << i+1 << ". jmeno: " << osoby[i].showName() << ", vek: " << osoby[i].showAge() << endl;
	}

	system("pause");
	return 0;
}