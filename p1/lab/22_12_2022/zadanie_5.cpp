#include <iostream>

using namespace std;

void Display(short int a) {
	int i = 1;
	
	i <<= 15; 
	
	for (i = i; i > 0; i /= 2 ) {
		if ( a / i ) {
			cout << 1;
			a -= i;
		}
		else {
			cout << 0;
		}	
	}
	
	cout << endl;
}

void Add(short int& numberOne, short int numberTwo) {
	int carry = 0;
	
	Display(numberOne);
	Display(numberTwo);
	
	while (numberTwo != 0) {
    	carry = numberOne & numberTwo;
    	numberOne = numberOne ^ numberTwo;
    	numberTwo = carry << 1;
	}
	
	Display(numberOne);
	cout << numberOne << endl;
}

int main() {
	short int numberOne = 0;
	short int numberTwo = 0;
	int carry = 0;

	cin >> numberOne >> numberTwo;
	
	Display(numberOne);
	Display(numberTwo);
    
    while (numberTwo != 0) {
    	carry = numberOne & numberTwo;
    	numberOne = numberOne ^ numberTwo;
    	numberTwo = carry << 1;
	}
    
    cout << numberOne << endl;
    
	Display(numberOne);

	return 0;
}
