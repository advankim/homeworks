#include <iostream>

using namespace std;

int main()
{
	int l = 0;
	int p = -1;
	int d = 0;

	cin >> l;


	while (p < 0)
	{
		cin >> p;
	}

	for (int i = 0; i < p; i++)
	{
		cin >> d;
		while (d == 0)
		{
			cin >> d;
		}
		if (l % d == 0) cout << "TAK\n";
		else cout << "NIE\n";
	}

	return 0;
}
