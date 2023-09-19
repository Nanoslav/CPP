#include <iostream>
#include <string>

using namespace std;

int a = 20;

// Pøi deklaraci:
// * = ukazatel
// & = adresa

int main() {
	int cislo = 20;
	cout << "Velikost int = " << sizeof(int) << "B" << endl;
	cout << "Adresa promenne cislo: " << &cislo << endl;

	int *ukazatel = &cislo;
	cout << "Velikost ukazatele = " << sizeof(ukazatel) << "B" << endl;
	cout << "Hodnota ukazatele: " << ukazatel << endl;
	cout << "Hodnota na kterou ukazatel ukazuje: " << *ukazatel << endl;

	//cislo = 40;
	*ukazatel = 40;
	cout << "Hodnota na kterou ukazatel ukazuje: " << *ukazatel << endl;
	cout << "promenna cislo: " << cislo << endl;

	char znak = 'a';
	char *uk = &znak;
	cout << "Velikost uk = " << sizeof(uk) << "B" << endl;

	*uk = 'A';

	string text = "toto je text";
	string *ukazatel_string = &text;

	system("pause");
	return 0;
}