/*
ID: zzh8829
PROG: milk3
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
int A,B,C,n=0;
bool done[21][21]={false},ans[22]={false};
void dfs(int a, int b)
{
	if(done[a][b]) return;
	done[a][b]=true;
	if (a==0)
	ans[(C-a-b)]=true;
	if((C-a-b)<=B-b) dfs(a,b+(C-a-b));   //c-b
	else dfs(a,B);
	if((C-a-b)<=A-a) dfs(a+(C-a-b),b);  //c-a
	else dfs(A,b);
	if(a<=B-b) dfs(0,b+a); //a-b
	else dfs(a-(B-b),B);
	if(a<=C-(C-a-b)) dfs(0,b);  //a-c
	else dfs(a-(C-(C-a-b)),b);
	if(b<=A-a) dfs(a+b,0);  //b-a
	else dfs(A,b-(A-a));
	if(b<=(C-a-b)-(C-a-b)) dfs(a,0);   //b-c
	else dfs(a,b-((C-a-b)-(C-a-b)));
}

int main()
{
	ifstream cin("milk3.in");
	ofstream cout("milk3.out");
	cin>> A>>B>>C;
	dfs(0,0);
	bool f=true;
	for(int i=0;i!=22;i++)
	if(ans[i])
	{
		if(f!=true)
		cout << " ";
		cout << i;
		f=false;
	}
	cout << endl;
	return 0;
}
