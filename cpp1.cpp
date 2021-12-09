#include "pch.h"
#include <iostream>

using namespace std;

int main()
{

	for (int i = 0; i <= 120; i++) {
		int operation = i % 2;
		if (operation == 0) {
			cout << i << " Hello World!\n";
		}else {
			cout << "Hello World!\n";
		}
	}

}
