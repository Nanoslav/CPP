#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {

	fstream file;
	file.open("dopravni_prostredky.txt");

	if (file.fail()) {
		cout << "chyba!";
		system("pause");
		exit(1);
	}

	string nazevVozidla;
	int rokVyrobyVozidla, cenaVozidla;
	string barvaVozidla;

	int pocetCervenych = 0, pocetZelenych = 0, pocetModrych = 0, pocetVsech = 0;
	int celkovacenaCervenych = 0, celkovacenaZelenych = 0, celkovacenaModrych = 0, celkovacenaVsech = 0;

	while (file >> nazevVozidla >> rokVyrobyVozidla >> cenaVozidla >> barvaVozidla) {
		pocetVsech++;
		celkovacenaVsech += cenaVozidla;
		if (barvaVozidla == "cervena") {
			pocetCervenych++;
			celkovacenaCervenych += cenaVozidla;
		}
		else if (barvaVozidla == "modra") {
			pocetModrych++;
			celkovacenaModrych += cenaVozidla;
		}
		else if (barvaVozidla == "zelena") {
			pocetZelenych++;
			celkovacenaZelenych += cenaVozidla;
		}
	}

	file.close();

	cout << "Pocet cervenych " << pocetCervenych << " v celkove hodnote " << celkovacenaCervenych << endl;
	cout << "Pocet modrych " << pocetModrych << " v celkove hodnote " << celkovacenaModrych << endl;
	cout << "Pocet zelenych " << pocetZelenych << " v celkove hodnote " << celkovacenaZelenych << endl;
	cout << "Pocet vsech " << pocetVsech << " v celkove hodnote " << celkovacenaVsech << endl;

	system("pause");
	return 0;
}
