//Mateusz RoŸdziñski

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;	

	cin >> a >> b >> c;

	d = b * b - (4 * a * c);

	if (d < 0) cout << 0 << " pierwiastkow" << endl;
	else if (d > 0)
	{
		float x1 = 0;
		float x2 = 0;
		
		
		d = sqrt(d);
		cout << 2 << " pierwiastki" << endl;
		
		x1 = (-1 * b - d) / (2 * a);
		x2 = (-1 * b + d) / (2 * a);

		cout << x1 << endl;
		cout << x2 << endl;
	}
	else
	{
		float x0 = 0;
		
		d = sqrt(d);
		cout << 1 << " pierwiastek" << endl;
		
		x0 = (-1 * b) / (2 * a);
		if (x0 == -0) x0 = 0;

		cout << x0 << endl;
	}
	
	return 0;
}
