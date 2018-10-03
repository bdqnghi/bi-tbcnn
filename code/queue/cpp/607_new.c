#include <iostream>
#include <iomanip>
using namespace std;
#define MAXIMUM 99999999

int i=1,n,m,a,b,x,y,z[10000000],queue[10000000],zzz;

void out(){
    for(int i=1;i<=n;i++)
        if(z[i]==MAXIMUM)cout<<setw(3)<<"-1";
        else cout<<setw(3)<<z[i];
    cout<<endl;
    }

int main(){
freopen("game.in","r",stdin);
freopen("game.out","w",stdout);

    cin>>n>>m>>a>>b>>x>>y;
    for(int j=1;j<=n;j++)z[j]=MAXIMUM;
    z[x]=0;
    queue[0]=1;
    queue[1]=x;


    do
    {
        if(z[queue[i]]==MAXIMUM)continue;
        if(queue[i]+a>0&&queue[i]+a<=n){
            if(z[queue[i]]+1<z[queue[i]+a]){z[queue[i]+a]=z[queue[i]]+1;queue[0]++;queue[queue[0]]=queue[i]+a;}
            }
        if(queue[i]-a>0&&queue[i]-a<=n){
            if(z[queue[i]]+1<z[queue[i]-a]){z[queue[i]-a]=z[queue[i]]+1;queue[0]++;queue[queue[0]]=queue[i]-a;}
            }
        if(queue[i]+b>0&&queue[i]+b<=n){
            if(z[queue[i]]+1<z[queue[i]+b]){z[queue[i]+b]=z[queue[i]]+1;queue[0]++;queue[queue[0]]=queue[i]+b;}
            }
        if(queue[i]-b>0&&queue[i]-b<=n){
            if(z[queue[i]]+1<z[queue[i]-b]){z[queue[i]-b]=z[queue[i]]+1;queue[0]++;queue[queue[0]]=queue[i]-b;}
                }
    ++i;

        //out();
    }
    while(i<=queue[0]);


    if(z[y]<=m)cout<<z[y];
    else cout<<"-1";

//cout<<endl;for(int j=1;j<=queue[0];j++)cout<<queue[j]<<" ";

    return 0;
}

