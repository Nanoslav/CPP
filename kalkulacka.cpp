#include <iostream>
#include <string>

using namespace std;

int n1;
string operation;
int n2;

int main()
{

	string again = "ano";

	while(again == "ano"){

		cout << "Vitej v kalkulacce!\nZadej prvni cislo: ";
		cin >> n1;
		cout << "\nZadej operaci (/ x + - $): ";
		cin >> operation;
		cout << "\nZadej druhe cislo: ";
		cin >> n2;

		if (operation == "/") {
			cout << "\nTvuj vysledek je: ";
			cout << n1 / n2;
		}
		else if (operation == "x") {
			cout << "\nTvuj vysledek je: ";
			cout << n1 * n2;
		}
		else if (operation == "+") {
			cout << "\nTvuj vysledek je: ";
			cout << n1 + n2;
		}
		else if (operation == "-") {
			cout << "\nTvuj vysledek je: ";
			cout << n1 - n2;
		}
		else if (operation == "$") {
			int f;
			for (int i = 0; i < n2; i++) {
				f = n1 * n2;
			}
			cout << "\nTvuj vysledek je: ";
			cout << f;
		}

		cout << "\nChces pouzit kalkulacku znovu? (ano/ne)\n";
		cin >> again;

	}

}
