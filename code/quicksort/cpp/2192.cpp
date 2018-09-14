#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void quicksort(int a[], int i, int j)
{
	//cout<<"sorting "<<endl;
	int pt1=i+1,pt2=j;
	//cout<<i<<" "<<j<<endl;
		if((a[i]>a[j])&&(j==i+1))
		{
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}

	else if(j>i+1)
	{
		int random=(rand()%(j-i+1)+1+i);
		int tempo=a[i];
		a[i]=a[random];
		a[random]=tempo;
		int val=a[i];
	//	cout<<"in the else part "<<endl;
		while(pt1<=j)
		{
			if(pt1>pt2)	
				break;

			while(a[pt1]<=val)
				pt1++;

			while(a[pt2]>val)
				pt2--;

			if((pt1>pt2)||(pt1>j)||(pt2<i))
				break;

			int piv=a[pt1];
			a[pt1]=a[pt2];
			a[pt2]=piv;
			
			pt1++;
			pt2--;

		//	cout<<pt1<<" "<<pt2<<endl;

		}
	//	cout<<"performing the other quick "<<endl;
		int temp=a[pt2];
		a[pt2]=a[i];
		a[i]=temp;

		quicksort(a,i,pt2-1);
		quicksort(a,pt1,j);
	}
		

	int val=a[i];


}

int main()
{
	int i=0,size;
	ifstream f;
	int a[1000];
	f.open("input.txt");
	f>>size;
	while(i<size)
	{
		f>>a[i++];
		//cout<<"the size is "<<i<<" the value read is "<<a[i-1]<<endl;
	}
	
	quicksort(a,0,size-1);

	ofstream f1;
	f1.open("output.txt");

	i=0;
//	cout<<"The size is "<<size<<endl;
	while(i<size)
	{
		f1<<a[i]<<endl;
		i++;
	}
	f1.close();
	f.close();


	return 0;

}