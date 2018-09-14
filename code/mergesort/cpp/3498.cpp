#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int ct;
int a[maxn];
int temp[maxn];
void merge(int a[],int l,int mid,int r){
	int i = l,j = mid + 1,k = 0;
	while(i <= mid&&j <= r){
		if(a[i] < a[j]) temp[k++] = a[i++];
		else {
			temp[k++] = a[j++];
			ct += mid - i + 1;
		}
	}
	while(i <= mid) temp[k++] = a[i++];
	while(j <= r) temp[k++] = a[j++];
	for(int i = l,k = 0;i <= r;i++,k++) a[i] = temp[k];
}
void mergesort(int a[],int l,int r){
	int mid;
	if(l < r){
		mid = (l + r)/2;
		mergesort(a,l,mid);
		mergesort(a,mid+1,r);
		merge(a,l,mid,r);
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin>>n){
		ct = 0;
		for(int i = 0;i < n;i++) cin>>a[i];
		mergesort(a,0,n-1);
		cout<<ct<<endl;
	}
	return 0;
}
