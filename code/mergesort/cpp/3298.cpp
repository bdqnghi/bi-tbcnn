#include <iostream>
using namespace std;

void merge(int a[],int l,int m,int h)
{
    int n1,n2,i,j,k;
    n1=(m-l+1);
    n2=(h-m);
    int ar1[n1],ar2[n2];
    for(i=0;i<n1;i++)
        ar1[i]=a[l+i];
    for(i=0;i<n2;i++)
        ar2[i]=a[m+1+i];
    i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(ar1[i]<=ar2[j])
            a[k++]=ar1[i++];
        else
            a[k++]=ar2[j++];
    }
    while(i<n1)
        a[k++]=ar1[i++];
    while(j<n2)
        a[k++]=ar2[j++];
        
}
void mergesort(int a[],int l,int h)
{
    if(l<h)
    {
        int m=l+(h-l)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,h);
        merge(a,l,m,h);
    }
}
int main() {
	int n,i;
	cin>>n;
	int* a=new int[n];
	for(i=0;i<n;i++)
	    cin>>a[i];
	mergesort(a,0,n-1);
	for(i=0;i<n;i++)
	    cout<<a[i]<<" ";
	delete []a;   
	return 0;
}
