#include <iostream>
using namespace std;
int main()
{
	int n, l=0, k, tind, max, temp;
	cout << "How many numbers do you want to enter? " << endl;
	cin >> n;
	int heap[n];
	for (int i = 0; i < n; i++){
		cin >> heap[i];
	}
	k = n - 1;
	for (int i = 1; i < n; i++)
	{
		temp = heap[k];
		heap[k] = heap[0];
		heap[0] = temp;
		l = 0;
        k -= 1;
		while (2*l + 1 <= k)
		{
			if (2*l + 2 <= k)
			{
				if (heap[2*l + 2] > heap[2*l + 1])
				{	
					max = heap[2*l + 2];
					tind = 2*l + 2;
				}
				else
				{
					max = heap[2*l + 1];
					tind = 2*l + 1;
				}
				if (heap[l] < max)
				{
					temp = heap[l];
					heap[l] = heap[tind];
					heap[tind] = temp;
					l = tind;
				}
				else
					break;
			}
			else
			{
				if (heap[l] < heap[2*l + 1])
				{
					temp = heap[l];
					heap[l] = heap[2*l + 1];
					heap[2*l + 1] = temp;
				}
				break;
			}
		}
	}
	for (int i = 0; i < n; i++){
		cout << heap[i] << endl;
	}
	return 0;
}
