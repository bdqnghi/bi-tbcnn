#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;
priority_queue<int, vector<int>, greater<int> > q;

int n;

int main()
{
    scanf("%d", &n);
    int x;
    for (int i=1; i<=n; ++i)
    {
        scanf("%d", &x);
        q.push(x);
    }
    int ans=0,tmp;
    while (q.size()>1)
    {
        tmp=q.top();

        q.pop();
        tmp+=q.top();
        q.pop();
        ans+=tmp;
        q.push(tmp);
    }
    printf("%d\n",ans);
    return 0;
}

