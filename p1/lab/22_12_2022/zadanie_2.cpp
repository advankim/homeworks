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

void Parity(short int number) {
	short int sum = 0;
	short int numberTwo = number;
	short int bit = 1;
	
	const int it = sizeof(number) * 8;
	
	//Display(numberTwo);
	
	for (int i = 0; i < it; i++) {
		if (number & bit) {
			sum++;
		}

		bit <<= 1;
	}
	
	if (sum % 2 != 0) {
		numberTwo ^= 1;
	}
	
	//Display(numberTwo);
}

int main() {
	short int number = 0b100000010000001;
	

	Parity(number);

	return 0;
}
