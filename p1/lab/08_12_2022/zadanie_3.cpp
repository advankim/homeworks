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

void DerivativePolynomial(double polynomial[], int length, int d) {
    int i = 0;
    int j = 0;
    int power = 0;
    
    for (i = 0; i < d; i++) {
    	power = length - i - 1;
    	for (j = 0; j < length - i; j++) {
    		if (j != length - i - 1) 
			{
				polynomial[j] = polynomial[j] * power;
				power--;
			}
    		else polynomial[j] = 0;
		}
	}
	
    Print(length - d, polynomial);
}

int main()
{
    double d = 0;
    int length = 0;
    double polynomial[100] = {};
    int i = 0;

    cin >> length;
    
    for (i = 0; i < length; i++) {
        cin >> polynomial[i];
    }

    cin >> d;
    
    DerivativePolynomial(polynomial, length, d);

    return 0;
}
