#include<iostream>
using namespace std;

template<class T>
int partition (T* arr, int low, int high)
{
    T pivot = arr[high];  
 
    int i = low - 1;

    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;    
            swap(arr[i],arr[j]);           
        }
    }    
    swap(arr[i+1],arr[high]);
    return (i + 1);
}
template<class T>
void swap(T& a, T& b)
{
	T temp=a;
	a=b;
	b=temp;
}

template<class T>
void quickSort(T* arr, int low, int high)
{
	if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high); 
    }
}

template<class T>
void showArr(T* a, int size)
{
	for(int i=0; i<size; i++) {
		cout<<a[i];
		if(i<size-1) cout<<", ";
		else cout<<"."<<endl;
	}
}

int main()
{
	int size;	
	
	cout<<"\nLets play with Templates and Array Sorting....\n\nEnter size of your array: ";
	cin>>size;
	int* i=new int[size];	
	double* d=new double[size];
	
	cout<<"\nFor Integers, enter elements one by one:-"<<endl;
	for(int j=0;j<size;j++) cin>>i[j];	
	cout<<"\nYour array: "; showArr(i,size);
	quickSort(i,0,size-1);
	cout<<"\nYour sorted array: "; showArr(i,size);
	
	cout<<"\nNow for Doubles, enter elements one by one:-"<<endl;
	for(int j=0;j<size;j++) cin>>d[j];	
	cout<<"\nYour array: "; showArr(d,size);
	quickSort(d,0,size-1);
	cout<<"\nYour sorted array: "; showArr(d,size);
	
	return 0;
}
