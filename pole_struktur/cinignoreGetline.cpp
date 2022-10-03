#include <iostream>
#include <string>

using namespace std;

int main(){
	string jmeno;
	cout << "Zadej jmeno: ";
	cin >> jmeno;
	cout << "Zadane jmeno: " << jmeno << endl;
	cin.ignore(2);
	string neco;
	cout << "Zadej neco: ";
	getline(cin, neco);
	cout << "neco: " << neco << endl;
}