#include <iostream>
#include<vector>
#include<list>
using namespace std;

ll main()
{
    ll n,b,a;
    cin>>n;
    std::vector<std::list<ll> > v(n+1);
    ll level[n+1];
    bool vis[n+1];
    for(ll i=1;i<=n;i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
    }
    std::vector<std::list<ll> >::iterator i;
    ll c=0;
    for(std::vector<std::list<ll> >::iterator i=v.begin();i!=v.end();++i)
    {
        cout<<"Vertices connected to node "<<c<<"are: ";
        std::list<ll> li=*i;
        for(std::list<ll>::iterator iter=li.begin();iter!=li.end();++iter)
        {
            cout<<*iter<<" ";
        }
        cout<<endl;
        c++;
    }

    return 0;
}
