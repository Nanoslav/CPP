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
	int count;
	Presence(){}
	Presence(string phone, int count) {
		this->phone = phone;
		this->count = count;
	}
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
	bool found;

	for (int i = 0; i < comms.size(); i++)
	{
		if (comms[i].getCaller() == phone) { //caller volajici, called volany
			ph1 = comms[i].getCalled();
		}
		else{
			ph1 = comms[i].getCaller();
		}

		found = false;
		int index;
		for (int j = 0; j < presence.size(); j++)
		{
			if (presence[j].phone == ph1) {
				found = true;
				index = j;
				break;
			}
		}

		if (found) {
			presence[index].count++;
		}
		else {
			presence.push_back(Presence(ph1, 1));
		}
		
	}

	Presence search;

	for (int i = 0; i < presence.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (presence[i].count > presence[j].count) {
				search = presence[i];
				presence[i] = presence[j];
				presence[j] = search;
			}
		}
	}

	int countData = 0;

	for (int i = 0; i < presence.size(); i++)
	{
		cout << presence[i].phone << " " << presence[i].count << endl;
		countData += presence[i].count;
	}

	cout << "Celkem: " << countData << endl;

	system("pause");
	return 0;
}