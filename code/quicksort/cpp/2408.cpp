#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int s[111];
int n;

void input(){
	scanf("%d",&n);
	
	for (int i=0;i<n;i++)
		scanf("%d",&s[i]);
}

void quicksort(int left,int right){
	if ( left >= right )
		return;
	int mid = (left+right)/2;
	int x = s[mid];
	int i = left;
	int j = right;
	
	do{
		while ( i < n && s[i] < x )
			i++;
		while ( j >= 0 && s[j] > x )
			j--;
		
		if ( i <= j ){
			swap(s[i],s[j]);
			i++;
			j--;	
		}
	}while (i <= j );
	
	if ( left < j )
		quicksort(left,j);
	if ( i < right )
		quicksort(i,right); 
}

void solve(){
	quicksort(0,n-1);
}

void output(){
	for (int i=0;i<n;i++)
		printf("%d ",s[i]);
	printf("\n");
}

int main()
{
	freopen("quicksort.inp","r",stdin);
	
	input();
	solve();
	output();
	
	return 0;
}


