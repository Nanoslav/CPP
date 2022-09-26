#include <iostream>
#include <string>

using namespace std;

struct Osoba {
	int vek;
	string jmeno;
};

int main() {
	int c1;
	c1 = 15;
	cout << "promenna c1 = " << c1 << endl;

	Osoba o1;
	/*o1.jmeno = "Jana";
	o1.vek = 18;*/

	cout << "zadej sve jmeno: ";
	cin >> o1.jmeno;
	cout << "zadej svuj vek: ";
	cin >> o1.vek;

	cout << "1. osoba: " << o1.jmeno << ", ve veku " << o1.vek << " let." << endl;


	system("pause");
	return 0;
}
