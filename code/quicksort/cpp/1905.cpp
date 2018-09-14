#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstring>
#include <cassert>
#include <ctime>
#include <stdbool.h>
using namespace std;
int A[10000];
int parti_tion(int A[],int p,int r)
{
    int x,i,j;
    x=A[r];
    i=p-1;
    for(j=p;j<=r-1;j++)
    {
        if(A[j]<=x)
        {
            i=i+1;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[j]);
    return i+1;
}
int quick_sort(int A[],int p,int r)
{
    int q;
    if(p<r)
    {
        q=parti_tion(A,p,r);
        quick_sort(A,p,q-1);
        quick_sort(A,q+1,r);
    }
    return 0;
}
int main()
{
    int p,r,i;
    cin>>r;
       for(i=1;i<=r;i++)
        cin>>A[i];
    quick_sort(A,1,r);
    for(i=1;i<=r;i++)
        cout<<A[i]<<" ";
    return 0;
}
