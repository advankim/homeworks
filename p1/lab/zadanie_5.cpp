#include <iostream>

using namespace std;

int main()
{
	int i = 2;

loop:
	if (i < 4) 
	{
		i++;
		cout << "Inkrementacja!" << endl;
		goto loop;
	}

	cout << endl << "i wynosi: " << i << endl;
	
	
	return 0;
}
