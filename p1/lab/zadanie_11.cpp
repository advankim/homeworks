//Mateusz RoŸdziñski

#include <iostream>

using namespace std;

int main()
{
	int i = 0;
	int j = 0;
	//zmienna do iteracji
	int c = 0;
	//zmienna pobierajaca, ktorego stopnia jest drugi wielomian
	int m = 0;
	//pomocnicza do potegi argumentu
	int s = 0;
	int d = 0;
	int st = 0;
	//stopien pochodnej

	float w[100] = {};
	//tablica przechowujaca wspolczynniki pierwszego wielomianu
	float wPochodny[100][100] = {};
	//tablica przechowujaca wielomian pochodny

	cin >> c;
	cin >> st;

	while (i < c + 1)
	{
		cin >> w[i];
		wPochodny[0][i] = w[i];
		i++;
	}

	d = c + 1;
	
	for (i = 1; i <= st; i++)
	{
		s = d - 1;
		for (j = 0; j < d; j++)
		{
			wPochodny[i][j] = wPochodny[i - 1][j] * s;
			s--;
		}
		d--;
	}

	d = c + 1;

	for (i = 1; i <= st; i++)
	{
		m = c - i;
		for (j = 0; j < d; j++)
		{
			if (m == 0 && wPochodny[i][j] != 0) cout << wPochodny[i][j];
			else if (m == 1 && wPochodny[i][j] != 0) cout << wPochodny[i][j] << "x";
			else if (wPochodny[i][j] != 0) cout << wPochodny[i][j] << "x^" << m;

			if (m > 0)
			{
				if (wPochodny[i][j + 1] != 0) cout << " + ";
			}

			m--;
		}
		cout << endl;
		d--;
	}

	cout << endl;

	return 0;
}
