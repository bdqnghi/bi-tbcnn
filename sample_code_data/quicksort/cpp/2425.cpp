#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int n = 10;
	int tab[n];
	// fill array with any number between 0 and 100
	for (int i = 0; i < 10; i++)
	{
		tab[i] = int((double (rand())/RAND_MAX)*100);
		cout << tab[i] << "\n";
	}

	return 0;
}
