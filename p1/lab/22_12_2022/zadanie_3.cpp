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

void TurnRight(short int &number, short int shift) {
	int max = 1;
	
	max <<= 15;
	
	if (number < 0) {
		for (int i = 0; i < shift; i++) {
			if (number & 1) {
				number >>= 1;
			}
			else {
				number >>= 1;
				number ^= max;
			}
		}
	}
	else {
		for (int i = 0; i < shift; i++) {
			if (number & 1) {
				number >>= 1;
				number ^= max;
			}
			else {
				number >>= 1;
			}
		}
	}
}

int main() {
	short int number = 0b1011111000000101;
	short int shift = 3;
	
	//cin >> number >> shift;
	
	Display(number);
	
	TurnRight(number, shift);
	
	Display(number);
	
	return 0;
}
