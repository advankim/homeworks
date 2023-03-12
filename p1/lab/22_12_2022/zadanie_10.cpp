#include <iostream>

using namespace std;

int main() {
	short int numberOne = 0;
	short int numberTwo = 0;
	short int avarage = 0;
	short int carry = 0;
	
	cin >> numberOne >> numberTwo;
    
	avarage = (numberOne & numberTwo);
	numberOne = ((numberOne ^ numberTwo) >> 1);
	numberTwo = avarage;
	
	while (numberTwo != 0) {
    	carry = numberOne & numberTwo;
    	numberOne = numberOne ^ numberTwo;
    	numberTwo = carry << 1;
	}
	
	cout << numberOne << endl;

	return 0;
}
