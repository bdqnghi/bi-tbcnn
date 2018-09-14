#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[1000];
	int n,i,temp;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		
	}
	int pivot=a[0];
	
	for(i=0;i<n;i++)
	{
		if(pivot>a[i])
		{
			temp=a[i];
			a[i]=pivot;
			pivot=temp;
		}
	cout<<pivot<<endl;
	}
	for(i=0;i<n;i++)
	cout<<a[i];

return 0;
}



/* python
#!/bin/python
def partition(ar):    
    lesslist = [];
    morelist = [];
    for i in xrange(m-1):
        if ar[i+1] > ar[0]:
            morelist.append(ar[i+1])
        elif ar[i+1] <= ar[0]:
            lesslist.append(ar[i+1])
    return lesslist+[ar[0]]+morelist

m = input()
ar = [int(i) for i in raw_input().strip().split()]

print " ".join(map(str, partition(ar)))
*/
