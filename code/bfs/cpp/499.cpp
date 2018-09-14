#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> v[10];
bool vis[10];
void dfs(int s)
{
	vis[s]=true;
	cout<<s<<"->";
	for(int i=0;i<v[s].size();i++)
	{
		if(vis[v[s][i]]==false)
			dfs(v[s][i]);
	}
}
int main(int args,char *argv[])
{	int k,ch,p;
	cout<<"\n No of nodes..";
	cin>>p;
	vector<int> v[10];
	bool vis[10];
	queue<int> q;
	int n,x,y,dist=1,g[10];
	//bool a=false;
	cout<<"\nNo. of edges..";
	cin>>n;
	cout<<"Two vertices and Weight of each edge.."; 
	for(int i=0;i<n;i++)
	{
		cout<<"\nEdge "<<i+1<<": ";
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	cout<<"\n1.BFS\n2.DFS\n";
	cin>>ch;
	switch(ch)
	{
		case 1:
			q.push(x);
			//a=x;
			vis[x]=true;
			cout<<x<<"->";
			while(!q.empty())
			{
				k=q.front();
				//cout<<k;
				q.pop();
				for(int i=0;i<v[k].size();i++)
				{
					if(vis[v[k][i]]==false)
					{		
						//a=true;
						q.push(v[k][i]);
						vis[v[k][i]]=true;
						cout<<v[k][i]<<"->";
						//g[v[k][i]]=dist;
					}
				}
				/*if(a)
				{
					a=false;
					dist++;
				}*/
			}
			break;
		case 2:
			cout<<"\nEnter the starting node..";
			cin>>x;
			dfs(x);
			break;
		default:
			cout<<"\nGood try pal..";
	}
	/*cout<<"\nDistance from "<<x<<"is ..\n";
	for(int i=1;i<=p;i++)
		cout<<i<<"->"<<g[i]<<endl;*/
	cout<<"\n";
	return 0;
}
