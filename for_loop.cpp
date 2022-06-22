#include <iostream>
#include <string>

using namespace std;

int main()
{
    
	bool koudiRaged = false;
	string Odpoved;

	cout << "Mas prezuvky? (ano/ne)\n";
	cin >> Odpoved;
	
	if (Odpoved == "ano") {
		cout << "Mas prezuvky?\n";
	}
	else if (Odpoved == "ne") {
		koudiRaged = true;
	}
	else {
		cout << "Nauc se mluvit!\n";
		koudiRaged = true;
	}

	if (koudiRaged == true) {
		for (int i = 0; i < 10; i++) {
			cout << "Mas zapis!!!\n";
		}
		return 0;
	}
	else {
		cout << "Tak to ma byt, utikej do tridy!\n";
		return 0;
	}

}
