#include<iostream>
#include<cstdio>
#include<algorithm>
#define size 70
using namespace std;

class mergesort
{
    int a[size];
public:
    mergesort( int arr[])
    {
        for(int i=0;i<size;i++)
            a[i] = arr[i];
        int aux[size];
        sort ( a , aux , 0 , size-1 );
    }
    void merge( int a[], int aux[], int lo, int mid, int hi )
    {
        //cout<<"in merge...\t"<<lo<<" "<<mid<<" "<<hi<<endl;
        for(int i=lo;i<=hi;i++)
            aux[i] = a[i];
        int i = lo, j = mid+1;
        for(int k=lo; k<=hi; k++)
        {
            if      (i > mid)           a[k] = aux[j++];
            else if (j > hi)            a[k] = aux[i++];
            else if (aux[i] < aux[j])   a[k] = aux[i++];
            else if (aux[i] >= aux[j])  a[k] = aux[j++];
        }
    }
    void sort( int a[], int aux[], int lo, int hi )
    {
        //cout<<"begin: \tsort ( "<<lo<<" , "<<hi<<" )"<<endl;
        if (hi <= lo)   return;
        int mid = lo + (hi - lo) / 2;
        sort ( a , aux , lo , mid);
        sort ( a , aux , mid+1 , hi);
        merge (a , aux , lo , mid , hi );
        //cout<<"end: \tsort ( "<<lo<<" , "<<hi<<" )"<<endl;
    }
    void show ()
    {
        for(int i=0;i<size;i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }
};

int main ()
{
    int array[size],i,j,k;
    for(i=0;i<size;i++)
        array[i]=rand()%97;
    //for(i=0;i<size;i++)
      //  cout<<array[i]<<" ";
    //cout<<endl;
    mergesort m(array);
    m.show();
    return 0;
}
