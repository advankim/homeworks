#include <iostream>

using namespace std;

int main() {
	short int numberOne = 0;
	short int numberTwo = 0;
	
	cin >> numberOne >> numberTwo;
    
	numberOne ^= numberTwo;
	numberTwo ^= numberOne;
	numberOne ^= numberTwo;
	
	cout << numberOne << " " << numberTwo << endl;
	
	return 0;
}
