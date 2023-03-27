#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<ctime>
using namespace std;

class Spojeni {
private:
	string telefon;
	string misto;
public:
	Spojeni() {}
	Spojeni(string telefon, string misto) {
		this->telefon = telefon;
		this->misto = misto;
	}
	string dejTelefon() { return telefon; }
	string dejMisto() { return misto; }
};

struct VyskytTel {
	string telefon;
	int pocet;
	VyskytTel(){}
	VyskytTel(string t, int p){
		telefon = t;
		pocet = p;
	}
};

struct VyskytMista {
	string misto;
	int pocet;
	VyskytMista() {}
	VyskytMista(string m, int p) {
		misto = m;
		pocet = p;
	}
};
int main() {
	vector<Spojeni> komunikace;
	ifstream cteni("komunikace2.txt");
	
	if (cteni.fail()) {
		cout << "chyba cteni..." << endl;
		system("pause");
		exit(1);
	}

	
	string volajici, volany, misto, neco1, neco2;
	
	string telefon;
	cteni >> telefon;
	

	

	while (cteni >> volajici >> volany >> neco1 >> neco2 >> misto) {
		if (telefon != volajici) {
			komunikace.push_back(Spojeni(volajici, misto));
		}
		else {
			komunikace.push_back(Spojeni(volany, misto));
		}
	}
	cteni.close();
	//-------------------------------------------------------------------------
	
	vector<VyskytTel> vyskyty;	
	bool nalezeno;

	for (int i = 0; i < komunikace.size(); i++) {		
		nalezeno = false;
		int index;
		for (int x = 0; x < vyskyty.size(); x++) {
			if (komunikace[i].dejTelefon() == vyskyty[x].telefon) {
				nalezeno = true;
				index = x;
				break;
			}
		}
		if (nalezeno) {
			vyskyty[index].pocet++;
		}
		else {
			vyskyty.push_back(VyskytTel(komunikace[i].dejTelefon(), 1));
		}
	}

	VyskytTel pomocna;

	for (int a = 0; a < vyskyty.size(); a++) {
		for (int b = 0; b < a; b++) {
			if (vyskyty[a].pocet > vyskyty[b].pocet) {
				pomocna = vyskyty[a];
				vyskyty[a] = vyskyty[b];
				vyskyty[b] = pomocna;
			}
		}
	}

	cout << "Vypis cetnosti telefonu:" << endl;
	
	for (int i = 0; i < vyskyty.size(); i++) {
		cout << vyskyty[i].telefon << "-" << vyskyty[i].pocet << "x" << endl;
	}
	//===========================================================================

	cout << "Mista komunikace telefonu s cislem (" << vyskyty[0].telefon << "):" << endl;
	vector<VyskytMista> mista;	
	
	for (int i = 0; i < komunikace.size(); i++) {
		nalezeno = false;
		int index;
		if (vyskyty[0].telefon == komunikace[i].dejTelefon()) {
			for (int x = 0; x < mista.size(); x++) {
				if (komunikace[i].dejMisto() == mista[x].misto) {
					nalezeno = true;
					index = x;
					break;
				}
			}
			if (nalezeno) {
				mista[index].pocet++;
			}
			else {
				mista.push_back(VyskytMista(komunikace[i].dejMisto(), 1));
			}
		}
	}

	for (int i = 0; i < mista.size(); i++) {
		cout << mista[i].misto << " - " << mista[i].pocet << "x" << endl;
	}
	system("pause");
	return 0;
}