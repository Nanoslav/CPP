#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

int main() {
	int number = 25;
	vector<int> numbers;
	int* pole = new int[number];

	/*numbers.push_back(5);
	numbers.push_back(10);
	numbers.push_back(15);
	numbers.push_back(20);
	numbers.push_back(25);
	numbers.push_back(30);
	numbers.push_back(35);*/
	

	/*cout << "Pocet prvku vektoru: " << numbers.size() << endl;
	cout << "Kapacita vektoru: " << numbers.capacity() << endl;
	cout << "Maximalni pocet prvku vektoru: " << numbers.max_size() << endl;*/

	/*
	numbers.clear();
	*/

	int from;
	int to;
	int num;

	cout << "Od: ";
	cin >> from;
	cout << "Do: ";
	cin >> to;	
	cout << "Kolik: ";
	cin >> num;

	srand(time(NULL));
	for (int i = 0; i < num; i++) {
		numbers.push_back(rand() % (to - from + 1) + from);
	}

	for (int i = 0; i < numbers.size(); i++) {
		cout << numbers[i] << " ";
	}
	cout << endl;

	cout << "Pocet prvku vektoru: " << numbers.size() << endl;
	cout << "Kapacita vektoru: " << numbers.capacity() << endl;
	cout << "Maximalni pocet prvku vektoru: " << numbers.max_size() << endl;

	system("pause");
	return 0;
}