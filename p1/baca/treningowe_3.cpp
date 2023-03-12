#include <iostream>

using namespace std;

int main()
{
	int c = -1;
	int in, cw, bc;
	string oc1[6] = { "niedostateczny", "dostateczny", "dostateczny plus", "dobry", "dobry plus", "bardzo dobry" };
	string oc2[6] = { "2.0", "3.0", "3.5", "4.0", "4.5", "5.0" };


	while (c < 0)
	{
		cin >> c;
	}
	

	for (int i = 0; i < c; i++)
	{
		while (true)
		{
			cin >> in >> cw >> bc;
			if (in >= 1000 && cw >= 0 && cw <= 50 && bc >= 0 && bc <= 50) break;
		}
		
		
		cout << in << " " << cw + bc << "%" << " ";
		
		int pr = 90;
		int h = 5;
		
		while (pr >= 50)
		{
			if ((cw + bc) < pr)
			{
				h--;
				pr -= 10;
			}
			else break;
		}
		
		cout << oc1[h] << " " << "(" << oc2[h] << ")\n";
	}

	return 0;
}
