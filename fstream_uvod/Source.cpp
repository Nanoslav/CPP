#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
	cout << "loading \"data\"\n";

	//Relative path: "test.txt"
	//Absolute path: "C:\\Users\\ps.kriz.fra\\source\\repos\\fstream_uvod\\fstream_uvod\\test.txt"

	//Writing
	/*
	ofstream file;
	file.open("test.txt", ios::app);
	file << "first line\nsecond line\nthird line\n";

	for (int i = 0; i < 10; i++) {
		file << i << endl;
	}
	file.close();*/

	//Reading sentences
	/*ifstream file;
	string name1 = "sentences.txt";
	file.open(name1);

	if (file.fail()) {
		cout << "Error loading while loading file - " << name1 << endl;
		system("pause");
		exit(1);
	}

	string sentences;
	while (file >> sentences) {
		cout << "Sentence you wrote: " << sentences << endl;
	}

	file.close();*/

	//Reading numbers
	ifstream file;
	string name = "numbers.txt";
	file.open(name);

	if (file.fail()) {
		cout << "Error loading while loading file - " << name << endl;
		system("pause");
		exit(1);
	}

	int numbers;
	int sum = 0;
	int length = 0;

	while (file >> numbers) {
		sum += numbers;
		length++;
	}
	cout << "sum: " << sum << endl;
	cout << "length: " << length << endl;

	file.close();

	system("pause");
	return 0;
}
