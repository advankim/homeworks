//Mateusz RoŸdziñski

#include <iostream>

using namespace std;

int main()
{
	int i = 0;
	//zmienna do iteracji
	int c1 = 0;
	//zmienna pobierajaca, ktorego stopnia jest pierwszy wielomian
	int c2 = 0;
	//zmienna pobierajaca, ktorego stopnia jest drugi wielomian
	int m = 0;
	//pomocnicza do potegi argumentu

	float w1[100] = {};
	//tablica przechowujaca wspolczynniki pierwszego wielomianu
	float w2[100] = {};
	//tablica przechowujaca wspolczynniki drugiego wielomianu
	float wSuma[100] = {};

	cin >> c1;

	c1++;

	while (i < c1)
	{
		cin >> w1[i];

		i++;
	}

	i = 0;

	cin >> c2;

	c2++;

	while (i < c2)
	{
		cin >> w2[i];

		i++;
	}


	if (c1 >= c2)
	{
		i = 0;
		m = c1 - 1;

		while (i < (c1 - c2))
		{
			wSuma[i] = w1[i];
			
			i++;
		}

		i = 0;

		while (i < c2)
		{
			wSuma[i + (c1 - c2)] = w1[i + (c1 - c2)] + w2[i];

			i++;
		}
	}
	else
	{
		i = 0;
		m = c2 - 1;

		while (i < (c2 - c1))
		{
			wSuma[i] = w1[i];

			i++;
		}

		i = 0;

		while (i < c1)
		{
			wSuma[i + (c2 - c1)] = w2[i + (c2 - c1)] += w1[i];

			i++;
		}
	}


	i = 0;

	while (i < m + 1)
	{
		if (m == 0 && wSuma[i] != 0) cout << wSuma[i];
		else if (m == 1 && wSuma[i] != 0) cout << wSuma[i] << "x";
		else if (wSuma[i] != 0) cout << wSuma[i] << "x^" << m;

		if (m > 0)
		{
			if (wSuma[i + 1] != 0) cout << " + ";
		}

		m--;

		i++;
	}

	cout << endl;

	return 0;
}
