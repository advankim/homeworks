#include <iostream>

using namespace std;

void Display(short int a) {
	int i = 1;
	
	i <<= (sizeof(a) * 7); 
	
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

void TurnLeft(short int &number, short int shift) {
	int max = 1;
	
	max <<= sizeof(number) * 7;
	
	for (int i = 0; i < shift; i++) {
		if (number & max) {
			number = number << 1;
			number ^= 1;
		}
		else {
			number = number << 1;
		}
	}
	
	Display(number);
}

int main() {
	short int number = 0;
	short int shift = 0;
	
	cin >> number >> shift;
	
	Display(number);
	
	TurnLeft(number, shift);
	
	Display(number);
	
	return 0;
}
