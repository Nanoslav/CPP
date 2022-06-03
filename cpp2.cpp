#include <iostream>
#include <string>

using namespace std;

int main()
{
  // string -> int
	string In1 = "12";
	int Res1 = stoi(In1);
	cout << Res1 << endl;
	
	// string -> double
	string In2 = "30.614";
	double Res2 = stod(In2);
	cout << Res2 << endl;
	
	//double -> int
	double In3 = 5.654;
	int Res3 = int (In3);
	cout << Res3 << endl;
	
	//int -> double
	int a{5},b{2},c{9};
  double Res4 = (double)a / (double)b + (double)c;
  cout << Res4 << endl;
    
  //string -> bool
  string In5 = "1";
  bool Res5 = (In5 == "1");
  cout << boolalpha << Res5 << endl;

  return 0;
}
