#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
    int n,a[20],i,j,temp;
    cout<< "Enter the no. of elements"<<endl;
    cin>>n;
    cout<< "Enter the elemnts "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n-1;i++)                          //Ascending Order
    {
        for(j=0;j<n;j++)
        {
           if (a[j]>a[j+1])
           {
               temp=a[j];
               a[j]=a[j+1];
               a[j+1]=temp;
           }
        }
    }

    cout<< "Sorted array"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<a[i];
    }




    return 0;
}
