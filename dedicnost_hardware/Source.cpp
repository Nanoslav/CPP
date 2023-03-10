#include <iostream>
#include <string>

using namespace std;

class Hardware {
private:
	int cena;
	string vyrobce;
public:
	Hardware(){}
	Hardware(int cena, string vyrobce) {
		this->cena = cena;
		this->vyrobce = vyrobce;
	}
	int dejCenu() { return this->cena; }
	string dejVyrobce() { return this->vyrobce; }
};

class Procesor : public Hardware {
private:
	int frekvence;
public:
	Procesor(){}
	Procesor(int cena, string vyrobce, int frekvence) : Hardware(cena, vyrobce) {
		this->frekvence = frekvence;
	}
	int dejFrekvenci() { return this->frekvence; }
};

class RAM : public Hardware {
private:
	int velikost;
public:
	RAM() {}
	RAM(int cena, string vyrobce, int velikost) : Hardware(cena, vyrobce) {
		this->velikost = velikost;
	}
	int dejVelikost() { return this->velikost; }
};

class HDD : public Hardware {
private:
	int velikost;
public:
	HDD() {}
	HDD(int cena, string vyrobce, int velikost) : Hardware(cena, vyrobce) {
		this->velikost = velikost;
	}
	int dejVelikost() { return this->velikost; }
};

class MB : public Hardware {
private:
	string velikost;
public:
	MB() {}
	MB(int cena, string vyrobce, string velikost) : Hardware(cena, vyrobce) {
		this->velikost = velikost;
	}
	string dejVelikost() { return this->velikost; }
};

class Zdroj : public Hardware {
private:
	int vykon;
public:
	Zdroj() {}
	Zdroj(int cena, string vyrobce, int vykon) : Hardware(cena, vyrobce) {
		this->vykon = vykon;
	}
	int dejVykon() { return this->vykon; }
};

class Case : public Hardware {
private:
	string typ;
public:
	Case() {}
	Case(int cena, string vyrobce, string typ) : Hardware(cena, vyrobce) {
		this->typ = typ;
	}
	string dejTyp() { return this->typ; }
};

class GPU : public Hardware {
private:
	int velikost;
public:
	GPU() {}
	GPU(int cena, string vyrobce, int velikost) : Hardware(cena, vyrobce) {
		this->velikost = velikost;
	}
	int dejVelikost() { return this->velikost; }
};

//Hardware - cena, vyrobce
//Procesor (frekvence)
//OP (velikost)
//HDD (velikost)
//MB (velikost)
//Zdroj (vykon)
//Case (typ)
//Graficka karta (velikost OP)

int main(){
	int suma = 0;
	int int_input;
	string str_input;
	int cena;
	string vyrobce;

	Procesor procesor; RAM ramka; HDD disk; MB deska; Zdroj zdroj; Case kejs; GPU grafika;

	string hw[7] = { "Procesor", "Operacni pameti", "Hard disk", "Zakladni deska", "Zdroj", "Case", "Graficka karta" };

	for (int i = 0; i < 7; i++)
	{
		cout << hw[i] << endl;
		cout << "===================" << endl;
		cout << "Zadej vyrobce: ";
		cin >> vyrobce;
		cout << "Zadej cenu: ";
		cin >> cena;
		switch (i) {
		case 0:
			cout << "Zadej frekvenci (MHz): ";
			cin >> int_input;
			procesor = Procesor(cena, vyrobce, int_input);
			break;
		case 1:
			cout << "Zadej velikost (GB): ";
			cin >> int_input;
			ramka = RAM(cena, vyrobce, int_input);
			break;
		case 2:
			cout << "Zadej velikost (GB): ";
			cin >> int_input;
			disk = HDD(cena, vyrobce, int_input);
			break;
		case 3:
			cout << "Zadej format desky (ATX, microATX): ";
			cin >> str_input;
			deska = MB(cena, vyrobce, str_input);
			break;
		case 4:
			cout << "Zadej vykon (W): ";
			cin >> int_input;
			zdroj = Zdroj(cena, vyrobce, int_input);
			break;
		case 5:
			cout << "Zadej typ: ";
			cin >> str_input;
			kejs = Case(cena, vyrobce, str_input);
			break;
		case 6:
			cout << "Zadej velikost RAM (GB): ";
			cin >> int_input;
			grafika = GPU(cena, vyrobce, int_input);
			break;
		}
		system("cls");
	};

	cout << "SESTAVA" << endl;
	cout << "=============================" << endl;

	for (int i = 0; i < 7; i++)
	{
		cout << hw[i] << ": ";
		switch(i){
		case 0:
			suma += procesor.dejCenu();
			cout << "vyrobce: " << procesor.dejVyrobce() << ", cena: " << procesor.dejCenu();
			cout << ", frekvence: " << procesor.dejFrekvenci() << " MHz" << endl;
			break;
		case 1:
			suma += ramka.dejCenu();
			cout << "vyrobce: " << ramka.dejVyrobce() << ", cena: " << ramka.dejCenu();
			cout << ", velikost: " << ramka.dejVelikost() << " GB" << endl;
			break;
		case 2:
			suma += disk.dejCenu();
			cout << "vyrobce: " << disk.dejVyrobce() << ", cena: " << disk.dejCenu();
			cout << ", velikost: " << disk.dejVelikost() << " GB" << endl;
			break;
		case 3:
			suma += deska.dejCenu();
			cout << "vyrobce: " << deska.dejVyrobce() << ", cena: " << deska.dejCenu();
			cout << ", velikost: " << deska.dejVelikost() << endl;
			break;
		case 4:
			suma += zdroj.dejCenu();
			cout << "vyrobce: " << zdroj.dejVyrobce() << ", cena: " << zdroj.dejCenu();
			cout << ", vykon: " << zdroj.dejVykon() << " W" << endl;
			break;
		case 5:
			suma += kejs.dejCenu();
			cout << "vyrobce: " << kejs.dejVyrobce() << ", cena: " << kejs.dejCenu();
			cout << ", typ: " << kejs.dejTyp() << endl;
			break;
		case 6:
			suma += grafika.dejCenu();
			cout << "vyrobce: " << grafika.dejVyrobce() << ", cena: " << grafika.dejCenu();
			cout << ", rychlost OP: " << grafika.dejVelikost() << " GB" << endl;
			break;
		}
	}

	cout << "========================" << endl;
	cout << "Celkova cena: " << suma << " Kc" << endl;
	cout << "========================" << endl;

	system("pause");
	return 0;
}