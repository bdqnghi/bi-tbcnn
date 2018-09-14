#include<iostream>
#include<cstdio>
#define N 10
#define swap(a,b) a^=b^=a^=b
using namespace std;

int partition(int a[],int p,int r)
{
    int x = a[r],i = p,temp;
    for(int j=p;j<r;j++)
    {
            if(a[j]<=x)
            {
                temp = a[i]; a[i] = a[j]; a[j] = temp;
                i++;
            }
    }
    temp = a[i]; a[i] = a[r]; a[r] = temp;
    return (i);
   
}

void qsort(int a[],int p,int r)
{
    int q;
    if(p<r)
    {
       q = partition(a,p,r);
       qsort(a,p,q-1);
       qsort(a,q+1,r);
    }
}

int main()
{
    int a[N];
       
    for(int i=0;i<N;i++)
       scanf("%d",&a[i]);
    qsort(a,0,N);
    cout<<endl;
    for(int i=0;i<N;i++)
       printf("%d ",a[i]);
    system("pause");
    return 0;
}
