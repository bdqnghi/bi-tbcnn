#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ar[100];
    int n,temp;
    cin>>n;
    for(int i=0;i<n;i++)
    cin>>ar[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(ar[j]>ar[j+1])
            {
                temp=ar[j+1];
                ar[j+1]=ar[j];
                ar[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
        cout<<ar[i]<<" ";

}
