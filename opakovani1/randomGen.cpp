#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

int main() {
	cout << time(NULL) << endl;

	srand(time(NULL));
	//int number = rand() % 11; // 0 - 10
	int number = rand() % 6 + 5; // 5 - 10 vèetnì
	cout << number << endl;

	const int N = 20;
	int cisla[N];
	
	int OD, DO;

	cout << "Zadej hodnotu od:";
	cin >> OD;
	cout << "Zadej hodnotu do:";
	cin >> DO;

	for (int i = 0; i < N; i++)
	{
		cisla[i] = (rand() % ((DO - OD)+1)) + OD;
	}

	for (int i = 0; i < N; i++)
	{
		cout << cisla[i] << " ";
	}

	cout << endl;

	system("pause");
	return 0;
}