#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main() {
    ifstream cteni;
    cteni.open("Text.txt");
    if (cteni.fail()) {
        cout << "chyba..." << endl;
        system("pause");
        exit(1);
    }

    string jmeno;
    int vek;
    char pohlavi;

    while (cteni >> jmeno >> vek >> pohlavi) {
        cout << "jmeno: " << jmeno << ", vek: " << vek << ", pohlavi: ";
        if (pohlavi == 'm') {
            cout << "muz" << endl;
        }
        else {
            cout << "zena" << endl;
        }
    }

    cteni.clear();
    cteni.seekg(0);

    int pocetOsob, pocetMuzu, pocetZen, veky;
    pocetOsob = pocetMuzu = pocetZen = veky = 0;


    while (cteni >> jmeno >> vek >> pohlavi) {
        pocetOsob++;
        if (pohlavi == 'm') {
            pocetMuzu++;
        }
        else {
            pocetZen++;
        }
        veky += vek;


    }

    cout << "pocet vsech osob je: " << pocetOsob << endl;
    cout << "pocet muzu je: " << pocetMuzu << endl;
    cout << "pocet zen je: " << pocetZen << endl;
    //cout << "prumerny vek vsech osob je: " << (double)veky / pocetOsob << endl;
    //cout << "prumerny vek vsech osob je: " << veky / pocetOsob << endl;
    cout << "prumerny vek vsech osob je: " <<  veky / (pocetOsob * 1.0 )<< endl;
    


    cteni.close();

    system("pause");
    return 0;
}
