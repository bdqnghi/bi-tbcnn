#include<bits/stdc++.h>

using namespace std;

int wt[501],val[501],oW[2000001],sack[2000001];

int main()
{
	int i,j,n,K,next;
	cin>>K>>n;
	for(i=1;i<=n;i++)
    	cin>>val[i]>>wt[i];
	next=1;
	oW[next]=0;
	for(i=1;i<=n;i++)
	{
		sort(oW+1,oW+next+1);
		for(j=next;j>=1;j--)
		{
			if(oW[j]+wt[i]<=K)
			{
				if(sack[oW[j]+wt[i]]==0)
				{
					next++;
					oW[next]=oW[j]+wt[i];
				}
				sack[oW[j]+wt[i]]=max(sack[oW[j]+wt[i]],sack[oW[j]]+val[i]);
			}
		}
	}
	int ans=0;
	for(i=1;i<=K;i++)
		ans=max(ans,sack[i]);
	cout<<ans<<endl;
	return 0;
}
