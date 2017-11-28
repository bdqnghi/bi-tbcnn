#include <vector>
#include <iostream>
#include <assert.h>

using std::vector;
using std::cout;
using std::cin;

void bubblesort(vector<double>& array)
{
    if(array.empty())
	return;
    
    double temp;
    for(size_t i = 0; i < array.size() - 1; ++i)
	for(size_t j = i + 1; j < array.size(); j++)
	    if(array[i] > array[j])
	    {
		// swap the two elements
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	    }
}

int main()
{
    int number = 0;
    cout<<"Please Enter number of elements to sort:";
    cin>>number;
    
    if(number <= 0)
    {
	cout<<"No Elements to sort\n";
	return -1;
    }
    
    vector<double> array(number);
    for(size_t i = 0; i < array.size(); ++i)
    {
	cout<<"Enter number "<<(i + 1)<<" :";
	cin>>array[i];
    }

    cout<<"Calling BubbleSort...\n";
    bubblesort(array);
    cout<<"Sorted array is:";
    for(size_t i = 0; i < array.size(); ++i)
	cout<<array[i]<< " ";
    cout<<"\n";
}
