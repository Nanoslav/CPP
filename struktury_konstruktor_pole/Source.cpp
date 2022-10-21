#include <string>
#include <iostream>
#include<fstream>

using namespace std;

const int X = 5;
const string predmety[X] = { "Cj", "Mat", "Aj", "Tv", "Nj" };

struct Student {
	string jmeno;
	int znamky[X];
	Student(){}
	Student(string jmeno, int pole[]) {
		this->jmeno = jmeno;
		for (int i = 0; i < X; i++)
		{
			znamky[i] = pole[i];
		}
	}
};

int main() {
	const int N = 100;
	Student studenti[N];
	ifstream file("studenti.txt");

	string jmeno;
	int znamky[X];
	int index = 0;

	while (file >> jmeno) {
		for (int i = 0; i < X; i++)
		{
			file >> znamky[i];
		}
		studenti[index] = Student(jmeno, znamky);
		index++;
	}

	for (int i = 0; i < index; i++)
	{
		cout << "Jmeno: " << studenti[i].jmeno << ": ";
		for (int y = 0; y < X; y++) {
			cout << predmety[y] << " - " << studenti[i].znamky[y] << ", ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}