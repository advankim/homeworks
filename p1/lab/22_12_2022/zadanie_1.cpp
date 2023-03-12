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

int CountBit(int number) {
	short int sum = 0;
	const int it = sizeof(number) * 8;
	
	for (int i = 0; i < it; i++) {
		if (number & 1) {
			sum++;
		}

		number >>= 1;
	}
	
	return sum;
}

int main() {
	short int sum = 0;
	short int number = 0;
	
	cin >> number;
	
	sum = CountBit(number);

	cout << sum << endl;
	
	Display(number);

	return 0;
}
