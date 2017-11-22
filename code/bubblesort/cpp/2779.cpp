#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int arr[100],temp;
    int i,j,k,n,c=0;
    cout<<"Enter the no. of elements"<<endl;
    cin>>n;
cout<<"enter "<<n<<" elements"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

            }

        }
    }
cout<<endl<<"sorted array is "<<endl;
        for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

}
