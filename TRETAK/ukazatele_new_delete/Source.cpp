#include <iostream>
#include <string>

using namespace std;

int main() {
	int a = 20;
	a = 40;
	int *uk = &a;
	const int KONSTANTA = 15;
	int cisla[KONSTANTA];
	int *uk = cisla;

	//--------------------------------------------------
	string *uk_string = new string;
	//--------------------------------------------------
	//					KONSTATNI UKAZATEL
	//
	//	 const string *uk_string = new string;
	//
	// !!! NELZE pøeadresovat pomocí uk_string = new string;
	//--------------------------------------------------

	*uk_string = "toto je nejaky text";
	cout << "vypis textu: " << *uk_string << endl;
	cout << "adresa uk_string: " << uk_string << endl;

	delete uk_string;

	uk_string = new string;

	*uk_string = "toto je dalsi text";
	cout << "vypis textu: " << *uk_string << endl;
	cout << "adresa uk_string: " << uk_string << endl;

	cout << "adresa pole cisla: " << cisla << endl;

	delete uk_string;
	system("pause");
	return 0;
}