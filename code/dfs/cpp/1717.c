#include <iostream>

using namespace std;

int mass[1000][1000];
int n;
int m;
queue<int> q;
int p[1000];
int s;

bool used[1000];
int main()
{
cin >>n>>s;
int i;
for (i=0;i<n;i++)
{
	cin >>mass[i][0];
	for (int j=1;j<=mass[i][0];j++)
	cin >>mass[i][j];
}
used[s]=1;
q.push(s);
while (!q.empty())
{
	int v=q.front();
	q.pop();
	for (i=0;i<mass[v][0];i++)
	{
		if (!used[mass[v][i]])
		{
			used[mass[v][i]]=1;
			p[mass[v][i]]=v;
			q.push(mass[v][i]);
		}
	}
}










	return 0;
}

