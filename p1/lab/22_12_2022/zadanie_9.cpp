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

int main() {
	short int xorResult = 0;
	short int numberOne = 0;
	short int numberTwo = 7;
	int bit = 1;
	
	cin >> numberOne >> numberTwo;
	
	Display(numberOne);
    Display(numberTwo);
    
	for (int i = 0; i < sizeof(numberOne) * 8; i++) {
	   	if ((numberOne & bit) && (~numberTwo & bit) || ((~numberOne) & bit) && ((numberTwo) & bit)) {
	   		xorResult |= bit;
		}
		
		bit = bit << 1;
	}
   
   Display(xorResult);
   cout << xorResult << endl;

	return 0;
}
