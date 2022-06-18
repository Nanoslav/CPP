#include <iostream>
#include <string>

using namespace std;

bool nakoupeno = false;
bool vejce = false;
bool mleko = false;
bool mouka = false;

void nakup(string polozka);
int postup(int ingredience);
void first_stage_ask ();
void menu_enter();

void obchod(){
    string input;
    cin >> input;

    nakup(input);
}

void vareni(){
    int input;
    cin >> input;

    postup(input);
}

// Spravny postup 2 / 4 / 3 / 1
int postup(int ingredience){
    if(ingredience == 2){
        cout << "Rozmixoval jsi hladkou mouku se spetkou soli, mlekem a dvema vejci. Co dal?\n";
        cin >> ingredience;
        if(ingredience == 4){
            cout << "Na rozpanelou panev jsi vlil malou naberacku smesi.\n";
            cin >> ingredience;
            if(ingredience == 3){
                cout << "Smazis obe strany palacinky dozlatova.\n";
                cin >> ingredience;
                if(ingredience == 1){
                    cout << "Namazal jsi lahodne palacinky marmeladou a podavas je.\n\nKoudy doporucuje 11/10\n\nThe End\n\n\n";
                    return 0;
                }else{
                    cout << "Ale ne, zvolil jsi spatny postup. Zacni znovu.\n";
                    vareni();
                }
            }else{
                cout << "Ale ne, zvolil jsi spatny postup. Zacni znovu.\n";
                vareni();
            }
        }else{
            cout << "Ale ne, zvolil jsi spatny postup. Zacni znovu.\n";
            vareni();
        }
    }else{
        cout << "Ale ne, zvolil jsi spatny postup. Zacni znovu.\n";
        vareni();
    }
}

void nakup(string polozka){
    if(mouka == false && polozka == "mouka"){
        mouka = true;
        cout << "Prodavac Koudy: Zde je hladka mouka. Bude to jeste neco?\n";
        obchod();
    }else if(mleko == false && polozka == "mleko"){
        mleko = true;
        cout << "Prodavac Koudy: Zde je mleko. Mate jeste nejake prani?\n";
        obchod();
    }else if(vejce == false && polozka == "vejce"){
        vejce = true;
        cout << "Prodavac Koudy: Zde jsou vejce. Co dal?\n";
        obchod();
    }else if((polozka == "mleko" && mleko == true) || (polozka == "mouka" && mouka == true) || (polozka == "vejce" && vejce == true)){
        cout << "Prodavac Koudy: Polozku s nazvem " + polozka + " jsem vam jiz prodal.\n";
        obchod();
    }else if(polozka == "odejit" && (mleko == false || mouka == false || vejce == false)){
        cout << "Prodavac Koudy: Tak toto by neslo, chybi vam nejake ingredience. (mouka/vejce/mleko)\n";
        obchod();
    }else if(polozka == "odejit" && mleko == true && mouka == true && vejce == true){
        nakoupeno = true;
        cout << "Ja: Je to vse.\nProdavac Koudy: Dekuji za nakup a prijdte zas.\n*opustil jsi obchod*\n";
        menu_enter();
    }else{
        cout << "Prodavac Koudy: Polozku " + polozka + " tu neprodavam.\n";
        obchod();
    }
}

void vareni_enter(){
    cout << "\nNapoveda:\nSestav recept podle cisel tak, jak ma byt. (Kazde cislo odesilej zvlast.)\n\nMoznosti:\n1 - Namazeme marmeladou a podavame.\n2 - Hladkou mouku rozmixujeme se spetkou soli, mlekem a dvema vejci.\n3 - Smazime obe strany dozlatova.\n4 - Na rozpanelou panev vlijeme malou naberacku smesi.\n";
    vareni();
}

void obchod_enter(){
    cout << "\n*vesel jsi do obchodu*\nProdavac Koudy: Co to dnes bude? (mouka/vejce/mleko/odejit)\n";
    obchod();
}

void first_stage (string polozka) {

    if(polozka == "obchod" && nakoupeno == false){
        obchod_enter();
    }else if(polozka == "obchod" && nakoupeno == true){
        cout << "V obchodu jsi vse potrebne nakoupil.\n";
        first_stage_ask();
    }else if(polozka == "varit" && (mouka == false || mleko == false || vejce == false)){
        cout << "Nemas zadne ingredience, zkus jit prvne do obchodu. (obchod)\n";
        first_stage_ask();
    }else if(polozka == "varit" && mouka == true && mleko == true && vejce == true){
        cout << "Muzeme zacit varit.\n";
        vareni_enter();
    }else{
        cout << "Dostupne moznosti: obchod/varit\n";
        first_stage_ask();
    }

}

void first_stage_ask (){
    string input;
    cin >> input;

    first_stage(input);
}

void menu_enter(){
    cout << "\nMENU: Nabidka moznosti: obchod/varit\n";
    first_stage_ask();
}

int main (){
    cout << "Simulator vareni palacinky\nBy Nano AKA Fanda\nOtestoval Dery\n";
    menu_enter();
}
