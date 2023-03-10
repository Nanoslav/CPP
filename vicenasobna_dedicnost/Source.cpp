#include <string>
#include <iostream>

using namespace std;

class Father {
private:
	string name;
public:
	Father() {}
	Father(string name) {
		this->name = name;
	}
	string getName() { return name; }
	string fatherSpeaks() {
		return "No nevim nevim";
	}
};

class Mother {
private:
	string name;
public:
	Mother() {}
	Mother(string name) {
		this->name = name;
	}
	string getName() { return name; }
	string motherSpeaks() {
		return "Malej Kubiiik";
	}
};

class Child : public Father, public Mother {
private:
	string name;
public:
	Child() {}
	Child(string name, string Fname, string Mname) : Father(Fname), Mother(Mname){
		this->name = name;
	}
	string getName() { return name; }
};

/*
*Father: private -> protected
*Mother: private -> protected

class Child : public Father, public Matka {
private:
	string name;
public:
	Child(){}
	Child(string name, string Fname, string Mname){
		this->name = name;
		this->Father::name = Fname;
		this->Mother::name = Mname;
	}
	string getName() { return name; }
};

*/

int main() {
	Child child = Child("Jezecek", "Kubiik", "Fofrniik");

	cout << "Child name: " << child.getName() << endl;
	cout << "Mother name: " << child.Mother::getName() << endl;
	cout << "Father name: " << child.Father::getName() << endl;

	cout << "=========================================" << endl;

	cout << child.Mother::getName() << ": " << child.motherSpeaks() << endl;
	cout << child.Father::getName() << ": " << child.fatherSpeaks() << endl;

	system("pause");
	return 0;
}