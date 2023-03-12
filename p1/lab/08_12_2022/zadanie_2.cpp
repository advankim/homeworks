#include<iostream>

using namespace std;

void Print(int length, double resultPolynomial[]) {
    cout << "W(x) = ";

    if (length <= 0) cout << "0\n";
    else {
    	int power = length - 1;
        int i = 0;
    	
    	while (true) {
    		if (resultPolynomial[i] != 0) {
    			if (power > 1) cout << resultPolynomial[i] << "x" << power << " ";
		        else if (power == 1) cout << resultPolynomial[i] << "x ";
		        else if (power == 0) cout << resultPolynomial[i];	
		        
		        power--;
		        i++;
		        break;
			}
			
			i++;
			power--;
			
			if (power < 0) {
				cout << 0 << endl;
				
				break;	
			}
		}
		
		int j = i;
		
        for (i = j; i < length; i++) {
            if (resultPolynomial[i] < 0) cout << "- " << resultPolynomial[i] * -1;
            else if (resultPolynomial[i] > 0) cout << "+ " << resultPolynomial[i];

            if (resultPolynomial[i] != 0) {
                if (power > 1) cout << "x" << power << " ";
                else if (power == 1) cout << "x ";
                else if (power == 0);
            }

            power--;
        }

        cout << endl;
    }
}

void ProductPolynomial(int firstLength, int secondLength, double firstPolynomial[], double secondPolymonial[]) {
	double resultPolynomial[100] = {};
    int i = 0;
    int j = 0;
    
    int length = firstLength + secondLength - 1;
    
    for (i = 0; i < firstLength; i++) {
    	for (j = 0; j < secondLength; j++) {
    		resultPolynomial[i + j] = resultPolynomial[i + j] + firstPolynomial[i] * secondPolymonial[j];
		}
	}

    Print(length, resultPolynomial);
}

int main()
{
    int firstLength = 0;
    int secondLength = 0;

    double firstPolynomial[100] = {};
    double secondPolymonial[100] = {};

    int i = 0;

    cin >> firstLength;
    
    for (i = 0; i < firstLength; i++) {
        cin >> firstPolynomial[i];
    }

    cin >> secondLength;

    for (i = 0; i < secondLength; i++) {
        cin >> secondPolymonial[i];
    }
    
    ProductPolynomial(firstLength, secondLength, firstPolynomial, secondPolymonial);

    return 0;
}
