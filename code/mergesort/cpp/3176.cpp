#include <iostream>
using namespace std;

int main()
{
	int A[]={1,2,3,4,5,6,7};
	int B[]={2,4,5,8,9};
	int C[10];
	int i(0), j(0);

	for(int k=0; k<10; k++)
	{
		if(i>6||j>4)
		{
			if(i>6&&j<=4)
			{
				C[k]=B[j];
				j++;
				continue;
			}

			else if(j>4&&i<=6)
			{
				C[k]=A[i];
				i++;
				continue;
			}

			else
			{
				break;
			}

		}
		
		else if(A[i]<B[j]) 
		{
			C[k]=A[i];
			i++;
		}

		else 
		{
			C[k]=B[j];
			j++;
		}
	}

	for(int k=0; k<10; k++)
	{
		cout<<C[k]<<endl;
	}

	return 0;
}