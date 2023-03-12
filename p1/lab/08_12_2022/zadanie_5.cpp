#include <iostream>

using namespace std;

void Conversion(char convertedNumber[], int number, int system, int length) {
	char rest;
	int i = 0;
	int temp = 0;
	
	if (system <= 10 && system >= 2) {
		while (number != 0) {
	        rest = number % system;
	
	    	convertedNumber[length - i - 1] = rest + 48;
	
	        number = number / system;
	        
	        i++;
    	}
	}
	else {
		while (number != 0) {
	        rest = number % system;
	
	        if (rest < 10) {
	            convertedNumber[length - i - 1] = rest + 48;
	        }
	        else {
	            temp = rest % 10;
	            
	            convertedNumber[length - i - 1] = temp + 65;
	        }
	
	        number = number / system;
	        
	        i++;
    	}
	}
}

int LengthOfConvertedNumber(int number, int system) {
	
	int i = 0;
	
	while (number != 0) {
	        number = number / system;
	        
	        i++;
    	}
    	
    return i;
}

int main()
{
    int number = 0;
    int system = 0;
    
    cin >> number >> system;
    
    if (number == 0) {
    	cout << number;
	}
    else if (number > 0) {
    	char convertedNumber[100];
    	
    	int length = LengthOfConvertedNumber(number, system);
    	
		Conversion(convertedNumber, number, system, length);
		
		for (int i = 0; i <= length; i++) {
        	cout << convertedNumber[i];
    	}
	}
	else {
		cout << "error" << endl;
	}

    cout << endl;

    return 0;
}
