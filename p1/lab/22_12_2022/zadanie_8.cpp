#include <iostream>
#include <string>

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
	int multi = 0;
	short int numberOne = 0;
	short int numberTwo = 7;

	cin >> numberOne;
	
	Display(numberOne);
    
    numberOne = numberOne >> 1;
    
    while (numberTwo > 0) {
		if (numberTwo & 1) {
			multi += numberOne;
		}
		
		numberOne = numberOne << 1;
		numberTwo = numberTwo >> 1;
   }
   
   Display(multi);
   cout << multi << endl;

	return 0;
}
