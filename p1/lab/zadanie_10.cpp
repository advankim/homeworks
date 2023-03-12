//Mateusz RoŸdziñski

#include <iostream>

using namespace std;

int main()
{
	int i = 0;
	//zmienna do iteracji
	int c = 0;
	//zmienna pobierajaca, ktorego stopnia jest drugi wielomian
	int m = 0;
	//pomocnicza do potegi argumentu
	int s = 0;
	int d = 0;

	float w[100] = {};
	//tablica przechowujaca wspolczynniki pierwszego wielomianu
	float wPochodny[100] = {};
	//tablica przechowujaca wielomian pochodny

	cin >> c;

	while (i < c + 1)
	{
		cin >> w[i];

		i++;
	}

	i = 0;
	s = c;
	d = c;
	m = c - 1;
	
	while (i < d)
	{
		wPochodny[i] = w[i] * s;

		s--;
		i++;
	}

	i = 0;

	while (i < d)
	{
		if (m == 0 && wPochodny[i] != 0) cout << wPochodny[i];
		else if (m == 1 && wPochodny[i] != 0) cout << wPochodny[i] << "x";
		else if (wPochodny[i] != 0) cout << wPochodny[i] << "x^" << m;

		if (m > 0)
		{
			if (wPochodny[i + 1] != 0) cout << " + ";
		}

		m--;

		i++;
	}

	cout << endl;

	return 0;
}
