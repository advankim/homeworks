//Mateusz RoŸdziñski

#include <iostream>

using namespace std;

int main()
{
	int i = 0;
	int j = 0;
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
	float wIloczyn[100] = {};

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


	for (i = 0; i < c1; i++)
		for (j = 0; j < c2; j++)
		{
			wIloczyn[i + j] += w1[i] * w2[j];
		}


	i = 0;
	m = (c1 - 1) + (c2 - 1);

	int d = m + 1;

	while (i < d)
	{
		if (m == 0 && wIloczyn[i] != 0) cout << wIloczyn[i];
		else if (m == 1 && wIloczyn[i] != 0) cout << wIloczyn[i] << "x";
		else if (wIloczyn[i] != 0) cout << wIloczyn[i] << "x^" << m;

		if (m > 0)
		{
			if (wIloczyn[i + 1] != 0) cout << " + ";
		}

		m--;

		i++;
	}

	cout << endl;

	return 0;
}
