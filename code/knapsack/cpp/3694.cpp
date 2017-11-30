#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n,i;
    float W,amt=0,cap=0;
    cout<<"Enter the no of items and total capacity of bag\n";
    cin>>n>>W;
    vector<pair<float,int> > arr;
    float weight[n],price[n];
    float perc[n];
    pair<float,int> p;
    cout<<"Enter the weight of each items\n";
    for(i=0;i<n;i++)
    {
        cin>>weight[i];
    }
    cout<<"Enter the corresponding price of items\n";
    for(i=0;i<n;i++)
    {
        p.second=i;
        cin>>price[i];
        p.first=price[i]/weight[i];
        arr.push_back(p) ;
    }
    sort(arr.begin(),arr.begin() + n);
    for(i=n-1;i>=0;i--)
    {
        if(cap+weight[arr[i].second]<W)
        {
            amt+=price[arr[i].second];
            cap+=weight[arr[i].second];
            perc[arr[i].second]=100;
        }
        else if(cap+weight[arr[i].second]==W)
        {
                amt+=price[arr[i].second];
            cap+=weight[arr[i].second];
        }
        else
        {
            perc[arr[i].second]=(W-cap)/weight[arr[i].second]*100;
            amt+=(W-cap)/weight[arr[i].second]*price[arr[i].second];
            cap=W;
            break;
        }

    }
    cout.width(24);
    cout<<"Item no";
    for(i=1;i<=n;i++)
    {
        cout.width(7);
        cout<<i;
    }
    cout<<endl;
    cout.width(24);
    cout<<"Weight of each item";
    for(i=1;i<=n;i++)
    {
        cout.width(7);
        cout<<weight[i-1];
    }
    cout<<endl;
    cout.width(24);
    cout<<"Prince of each element";
    for(i=1;i<=n;i++)
    {
        cout.width(7);
        cout<<price[i-1];
    }
    cout<<endl;
    cout.width(24);
    cout<<"Percentage of item";
    for(i=1;i<=n;i++)
    {
        cout.width(7);
        cout<<perc[i-1];
    }
    cout<<endl;
    cout.width(24);
    cout<<"Total amount = "<<amt;
}
