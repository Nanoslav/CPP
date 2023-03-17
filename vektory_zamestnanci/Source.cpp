#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>

using namespace std;

class Worker {
private:
	string name;
	int salary;
	string position;
public:
	Worker(){}
	Worker(string name, string position, int salary) {
		this->name = name;
		this->position = position;
		this->salary = salary;
	}
	string getName() {
		return name;
	}
	string getPosition() {
		return position;
	}
	int getSalary() {
		return salary;
	}
};

int main() {
	string name;
	int salary;
	string position;

	vector<Worker> workers;
	vector<string> positions;

	ifstream file("zamestnanci.txt");

	if (file.fail()) {
		cout << "Chyba pri otevirani souboru" << endl;
		system("pause");
		exit(1);
	}

	while (file >> name >> position >> salary) {
		workers.push_back(Worker(name, position, salary));
	}

	file.close();


	for (int i = 0; i < workers.size(); i++) {
		cout << i+1 << ". " << workers[i].getName() << ", pozice: " << workers[i].getSalary() << ", plat: " << workers[i].getPosition() << endl;
		bool isIn = false;
		for (int j = 0; j < positions.size(); j++)
		{
			if (workers[i].getPosition() == positions[j]) {
				isIn = true;
				break;
			}
		}

		if (!isIn) {
			positions.push_back(workers[i].getPosition());
		}
	}

	cout << "=======================" << endl;
	cout << "		POZICE" << endl;
	for (int i = 0; i < positions.size(); i++)
	{
		cout << positions[i] << endl;
	}

	cout << endl;

	system("pause");
	return 0;
}