#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <list>

using namespace std;

struct Node {
	string key;
	int value;
};

bool ascending(Node& a, Node& b) {
	return (a.value < b.value);
}

bool descending(Node& a, Node& b) {
	return (a.value > b.value);
}

class Analyzator {
private:
	map<string, int> words;
	ifstream input;
	ofstream output;
	string word;
	list<Node> node;
public:
	Analyzator(string file){
		input.open(file);
		if (input.fail()) {
			cout << "File not found" << endl;
			system("pause");
			exit(1);
		}

		string chars = ".,;:!?-()[]/*{}\"\'%0123456789";

		while (input >> word) {
			while (word.find_first_of(chars) != string::npos) {
				word.erase(word.find_first_of(chars), 1);
			}
			for (int i = 0; i < word.length(); i++) {
				word[i] = tolower(word[i]);
			}
			if(!word.empty()){
				words[word]++;
			}
		}

		input.close();

	}

	void exportAZ() {
		output.open("outputAZ.txt");
		for (map<string, int>::iterator it = words.begin(); it != words.end(); it++) {
			output << it->first << " - " << it->second << "x" << endl;
		}
		output.close();
	}

	void exportZA() {
		output.open("outputZA.txt");
		for (map<string, int>::reverse_iterator it = words.rbegin(); it != words.rend(); it++) {
			output << it->first << " - " << it->second << "x" << endl;
		}
		output.close();
	}

	void Export1N() {
		Node pNode;
		for (map<string, int>::iterator it = words.begin(); it != words.end(); it++) {
			pNode.key = it->first;
			pNode.value = it->second;
			node.push_back(pNode);
		}
		node.sort(ascending);
		output.open("output1N.txt");
		for (list<Node>::iterator it = node.begin(); it != node.end(); it++) {
			output << it->value << "x - " << it->key << endl;
		}
		output.close();
	}

	void ExportN1() {
		Node pNode;
		for (map<string, int>::iterator it = words.begin(); it != words.end(); it++) {
			pNode.key = it->first;
			pNode.value = it->second;
			node.push_back(pNode);
		}
		node.sort(descending);
		output.open("outputN1.txt");
		for (list<Node>::iterator it = node.begin(); it != node.end(); it++) {
			output << it->value << "x - " << it->key << endl;
		}
		output.close();
	}

};

int main() {

	Analyzator analyzator("Text.txt");

	int volba;

	do {
		system("cls");
		cout << "\t\t\tAnalyzator textu" << endl << endl;
		cout << "\t1) Export A-Z do souboru" << endl;
		cout << "\t2) Export Z-A do souboru" << endl;
		cout << "\t3) Export od N - 1 do souboru" << endl;
		cout << "\t4) Export od 1 - N do souboru" << endl;
		cout << "\t5) Konec programu" << endl << endl;

		cout << "Zadejte volbu: ";
		cin >> volba;

		switch (volba) {
			case 1:
				analyzator.exportAZ();
				cout << "Export A-Z do souboru byl uspesny" << endl;
				system("pause");
				break;
			case 2:
				analyzator.exportZA();
				cout << "Export Z-A do souboru byl uspesny" << endl;
				system("pause");
				break;
			case 3:
				analyzator.Export1N();
				cout << "Export od N - 1 do souboru byl uspesny" << endl;
				system("pause");
				break;
			case 4:
				analyzator.ExportN1();
				cout << "Export od 1 - N do souboru byl uspesny" << endl;
				system("pause");
				break;
		}

	} while (volba != 5);

	return 0;
}