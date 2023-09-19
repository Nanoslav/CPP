#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Vozidlo {
private:
	string nazev;
	int rokV;
	int cena;
	string barva;
public:
	Vozidlo() {}
	Vozidlo(string nazev, int rokV, int cena, string barva) {
		this->nazev = nazev;
		this->rokV = rokV;
		this->cena = cena;
		this->barva = barva;
	}
	string getName() {
		return this->nazev;
	}
	int getYear() {
		
		return this->rokV;
	}
	int getPrice() {
		return this->cena;
	}
	string getColor() {
		return this->barva;
	}
};

int main() {

	const int N = 1000;
	Vozidlo vozidla[N];

	fstream file("vozidla.txt");

	string nazev;
	int rokV;
	int cena;
	string barva;
	int index = 0;

	while (file >> nazev >> rokV >> cena >> barva) {
		vozidla[index] = Vozidlo(nazev, rokV, cena, barva);
		index++;
	}

	file.close();

	int redCars = 0;
	int blueCars = 0;
	int greenCars = 0;

	int redPrice = 0;
	int bluePrice = 0;
	int greenPrice = 0;

	for (int i = 0; i < index; i++)
	{
		if (vozidla[i].getColor() == "cervena") {
			redCars++;
			redPrice += vozidla[i].getPrice();
			//cout << "Nazev: " << vozidla[i].getName() << ", rok: " << vozidla[i].getYear() << ", cena: " << vozidla[i].getPrice() << ", barva: " << vozidla[i].getColor() << "\n";
		}
	}

	cout << "Celkem cervenych: " << redCars << ", prumer ceny: " << double(redPrice / redCars) << endl;
	cout << "===================================================" << endl;

	for (int i = 0; i < index; i++)
	{
		if (vozidla[i].getColor() == "modra") {
			blueCars++;
			bluePrice += vozidla[i].getPrice();
			//cout << "Nazev: " << vozidla[i].getName() << ", rok: " << vozidla[i].getYear() << ", cena: " << vozidla[i].getPrice() << ", barva: " << vozidla[i].getColor() << "\n";
		}
	}

	cout << "Celkem modrych: " << blueCars << ", prumer ceny: " << double(bluePrice / blueCars) << endl;
	cout << "===================================================" << endl;

	for (int i = 0; i < index; i++)
	{
		if (vozidla[i].getColor() == "zelena") {
			greenCars++;
			greenPrice += vozidla[i].getPrice();
			//cout << "Nazev: " << vozidla[i].getName() << ", rok: " << vozidla[i].getYear() << ", cena: " << vozidla[i].getPrice() << ", barva: " << vozidla[i].getColor() << "\n";
		}
	}

	cout << "Celkem zelenych: " << greenCars << ", prumer ceny: " << double(greenPrice / greenCars) << endl;
	cout << "===================================================" << endl << endl;
	cout << "===================================================" << endl;
	cout << "Celkem aut: " << (greenCars + redCars + blueCars) << ", celkem prumer ceny: " << double((greenPrice + redPrice + bluePrice) / (greenCars + redCars + blueCars)) << endl;
	cout << "===================================================" << endl;

	system("pause");
	return 0;
}