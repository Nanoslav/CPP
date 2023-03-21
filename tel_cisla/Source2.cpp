#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Comms {
private:
	string caller;
	string called;
	string type;
	int number;
public:
	Comms(){}
	Comms(string caller, string called, string type, int number) {
		this->caller = caller;
		this->called = called;
		this->type = type;
		this->number = number;
	}
	string getCaller() {
		return caller;
	}
	string getCalled() {
		return called;
	}
	string getType() {
		return type;
	}
	int getNumber() {
		return number;
	}
};

struct Presence {
	string phone;
	int number;
};

int main() {
	vector<Comms> comms;
	string caller;
	string called;
	string type;
	int number;

	ifstream file("komunikace.txt");

	if (file.fail()) {
		cout << "error with loading a file..." << endl;
		system("pause");
		exit(1);
	}

	string phone;
	file >> phone;

	while (file >> caller >> called >> type >> number) {
		comms.push_back(Comms(caller, called, type, number));
	}

	file.close();

	vector<Presence> presence;
	string ph1;

	for (int i = 0; i < comms.size(); i++)
	{
		if (comms[i].getCaller() == phone) {
			//druhe se prida getCalled
			ph1 = comms[i].getCalled();
		}
		else{
			ph1 = comms[i].getCaller();
		}
		
	}

	system("pause");
	return 0;
}