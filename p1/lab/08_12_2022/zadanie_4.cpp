#include <iostream>
#include <cmath>

using namespace std;

double ResultPolynomial(double polynomial[], int length, int x) {
    double result;
	int i = 0;
    int power = length - 1;
    
    for (i = 0; i < length; i++) {
    	result = result + pow(x, power) * polynomial[i];
    	power--;
	}
	
	return result;
}

int main()
{
	double x = 0;
    int length = 0;
    double polynomial[100] = {};
    int i = 0;

    cin >> length;
    
    for (i = 0; i < length; i++) {
        cin >> polynomial[i];
    }

    cin >> x;
    
    cout << ResultPolynomial(polynomial, length, x) << endl;

    return 0;
}
