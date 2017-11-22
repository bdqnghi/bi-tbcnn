
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int dynamic_knapsack(vector<int> v, vector<int> w, int n, int W, int c)
{
	for (int k =0; k < W+1; k++)
	{
		c[0][k] = 0;
	}
	for (int i = 1; i < n+1; i++)
	{
		c[i][0] = 0;
		for (int j= 1; j < W+1; j++)
		{
			if (w[i] <= w[j])
			{
				if (v[i] + c[i-1][w[j]-w[i]] > c[i-1][j])
				{
					c[i][j] = v[i] + c[i-1][w[j]-w[i]];
				}
				else 
				{
					c[i][j] = c[i-1][j];
				}
			}
		}
	}

}

int main()
{	
	int W;
	int n;
	vector<int> v;
	vecotor<int> w;
	stringstream ss(str);
	cout << "Maximum Weight: " << endl;
	cin >> W;
	cout << "Number of items: " << endl;
	cin >> n;
	cout << "Sequence 1: " << endl;
	cin >> v;

	while (ss >> int i)
	{
	    v.push_back(i);

	    if (ss.peek() == ',')
	        ss.ignore();
	}

	cout << "Sequence 2: " << endl;
	cin >> w;

	while (ss >> int i)
	{
	    w.push_back(i);

	    if (ss.peek() == ',')
	        ss.ignore();
	}

	int lol = int dynamic_knapsack();
	cout << lol << endl;
	return 0;
}

