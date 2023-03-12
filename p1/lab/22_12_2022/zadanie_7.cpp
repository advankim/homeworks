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
	short int numberOne = 0;
	short int numberTwo = 0;
	int result = 0;
	string operations;
	
	cin >> operations;
    
    cout << endl;
    
    for (int i = 0; i < operations.size(); i++)
    {
    	cin >> numberOne >> numberTwo;
    	
        if (operations[i] == '~') {       	
        	Display(~numberOne);	
        	Display(~numberTwo);
        	
        	cout << endl;
		}
		else if (operations[i] == '&') {  	
        	Display(numberOne & numberTwo);
        	
        	cout << endl;
		}
		else if (operations[i] == '^') {  
        	Display(numberOne ^ numberTwo);
        	
        	cout << endl;
		}
		else if (operations[i] == '|') {      	
        	Display(numberOne | numberTwo);
        	
        	cout << endl;
		}
    }

	return 0;
}
