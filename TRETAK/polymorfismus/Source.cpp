#include <iostream>
#include <string>

using namespace std;

class Animal {
private:
	int age;
public:
	Animal(){}
	Animal(int age) {
		this->age = age;
	}
	int getAge() { return age; }
	virtual void doSound() {
		cout << "zvire mluvi..." << endl;
	}
};

class Dog : public Animal {
private:
	string name;
public:
	Dog(){}
	Dog(string name, int age) : Animal(age){
		this->name = name;
	}
	string getName() { return this->name; }
	void doSound() {
		cout << "pes steka..." << endl;
	}
};

class Cat : public Animal {
private:
	string name;
public:
	Cat() {}
	Cat(string name, int age) : Animal(age) {
		this->name = name;
	}
	string getName() { return this->name; }
	void doSound() {
		cout << "kocka mnouka..." << endl;
	}
};

class Snake : public Animal {
private:
	string name;
public:
	Snake() {}
	Snake(string name, int age) : Animal(age) {
		this->name = name;
	}
	string getName() { return this->name; }
	void doSound() {
		cout << "had syci..." << endl;
	}
};

class Horse : public Animal {
private:
	string name;
public:
	Horse() {}
	Horse(string name, int age) : Animal(age) {
		this->name = name;
	}
	string getName() { return this->name; }
	void doSound() {
		cout << "kun rehta..." << endl;
	}
};

int main() {
	Animal animal = Dog("Rex", 5);
	//Dog dog = Animal(5); // nelze

	cout << "Vek zvirete: " << animal.getAge() << endl;
	animal.doSound();

	Animal* pole[5] = {
		new Dog("Rex", 5),
		new Cat("Micka", 3),
		new Snake("Juan", 1),
		new Horse("Antonio", 10),
		new Animal(6)
	};

	for (int i = 0; i < 5; i++)
	{
		pole[i]->doSound();
	}

	system("pause");
	return 0;
}