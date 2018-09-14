#include<iostream>

using namespace std;

void printArray(int arr[],int n)
{
   for(int i=0;i<n;i++)
   std::cout << arr[i];
   std::cout <<std::endl;
}
void Bubble(int arr[],int n)
{
   for(int i = 0;i < n;i++)
    {
       for(int j =0;j < n-i-1;j++)
	if(arr[j]> arr[j+1])
	{
	   int temp = arr[j+1];
	   arr[j+1]= arr[j];
	   arr[j] = temp;
	}
    }
}
int main()
{
   int arr[6] ={5,2,4,6,1,3};
   Bubble(arr,6);
   printArray(arr,6);
   return 0;
}
