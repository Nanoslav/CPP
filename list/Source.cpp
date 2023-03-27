#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {
	list<int> numbers = { 10, 20, 30 };

	numbers.push_back(40);
	numbers.push_back(50);

	numbers.push_front(0);
	numbers.push_front(-10);

	list<int>::iterator it;
	it = numbers.begin();

	cout << "Hodnota 1. prvku je: " << *it << endl;

	cout << "Hodnota 2. prvku je: " << *(++it) << endl;

	cout << "Hodnota 3. prvku je: " << *(++it) << endl;

	for (list<int>::iterator it = numbers.begin(); it != numbers.end(); it++){
		cout << *it << endl;
	}

	system("pause");
	return 0;
}