#include <iostream>

using namespace std;

int main()
{
	int i = 4;
	
	
loop:
	i++;
	cout << "Inkrementacja!" << endl;
	if (i < 4) goto loop;

	cout << endl << "i wynosi: " << i << endl;
	
	
	return 0;
}
