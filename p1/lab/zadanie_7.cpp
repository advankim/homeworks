//Mateusz RoŸdziñski

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int i = 0;
	int c = 0;
	int m = 0;

	float w[100] = {};
	float x = 0;
	float r = 0;

	cin >> c;

	c++;

	while (i < c)
	{
		cin >> w[i];

		i++;
	}

	cin >> x;

	i--;

	while (i >= 0)
	{
		r += w[i] * pow(x, m);
		
		m++;
		i--;
	}

	cout << r << endl;

	return 0;
}
