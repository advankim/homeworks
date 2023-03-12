#include <iostream>

using namespace std;

int main()
{
	int c = 0;
	double l1, l2, l3, l4, l5;

	while (c < 1) 
	{
		cin >> c;
	}

	for (int i = 0; i < c; i++)
	{
		cin >> l1 >> l2 >> l3 >> l4 >> l5;

		double m = (l1 + l2 + l3 + l4 + l5) / 5;
		double max = l1, min = l1;

		if (l2 > max) max = l2;
		if (l3 > max) max = l3;
		if (l4 > max) max = l4;
		if (l5 > max) max = l5;

		if (l2 < min) min = l2;
		if (l3 < min) min = l3;
		if (l4 < min) min = l4;
		if (l5 < min) min = l5;

		if (min == -0) min = 0;

		cout << min << " " << max << " " << m << endl;
	}
	
	return 0;
}
