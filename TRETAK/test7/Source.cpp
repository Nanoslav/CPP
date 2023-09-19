#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Zakusky {
private:
	string jmeno;
	string pohlavi;
	string dortik;
public:
	Zakusky(){}
	Zakusky(string jmeno, string pohlavi, string dortik) {
		this->jmeno = jmeno;
		this->pohlavi = pohlavi;
		this->dortik = dortik;
	}
	string getName() { return this->jmeno; }
	string getGender() { return this->pohlavi; }
	string getDortik() { return this->dortik; }
};

struct Vyskyty {
	string dortik;
	int pocet;
	Vyskyty() {}
	Vyskyty(string dortik, int pocet) {
		this->dortik = dortik;
		this->pocet = pocet;
	}
};

int main() {

	vector<Zakusky> zakusky;
	string jmeno;
	string pohlavi;
	string dortik;

	ifstream file("data.txt");

	if (file.fail()) {
		cout << "problem s nacitanim" << endl;
		system("pause");
		exit(1);
	}

	while (file >> jmeno >> pohlavi >> dortik) {
		zakusky.push_back(Zakusky(jmeno, pohlavi, dortik));
	}

	file.close();

	vector<Vyskyty> vyskyty;
	string dort;
	bool found;

	for (int i = 0; i < zakusky.size(); i++)
	{
		dort = zakusky[i].getDortik();
		found = false;
		int index;
		for (int j = 0; j < vyskyty.size(); j++)
		{
			if (vyskyty[j].dortik == dort) {
				found = true;
				index = j;
				break;
			}
		}
		if (found) {
			vyskyty[index].pocet++;
		}
		else {
			vyskyty.push_back(Vyskyty(dort, 1));
		}
	}

	Vyskyty search;

	for (int i = 0; i < vyskyty.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (vyskyty[i].pocet > vyskyty[j].pocet) {
				search = vyskyty[i];
				vyskyty[i] = vyskyty[j];
				vyskyty[j] = search;
			}
		}
	}

	for (int i = 0; i < vyskyty.size(); i++)
	{
		cout << vyskyty[i].dortik << " - " << vyskyty[i].pocet << endl;
	}

	system("pause");
	return 0;
}