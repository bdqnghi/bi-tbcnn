/***
	*
	* @author victoraurelio.com
	* @since 18/10/16
	*
*/
#include <bits/stdc++.h>

using namespace std;

int weight[2001], value[2001], bag[2001][2001];
int s,n,current;

void pd(){	
	for(int i=0; i<s; i++){
		if(i<weight[0])bag[0][i] = 0;
		else bag[0][i] = value[0];
	}	
	for(int i=1; i<=n; i++){	
		current = i;
		for(int j=0; j<=s; j++){
			bag[i][j] = bag[i-1][j];
			if(weight[current] <= j){				
				if(bag[i-1][j] < value[current] + bag[i-1][j - weight[current]]){
					bag[i][j] = value[current] + bag[i-1][j - weight[current]];
				}			
			}
		}
	}
}


int main(){
	scanf(" %d%d", &s, &n);
	for(int i=0; i<n; i++) scanf(" %d%d", &weight[i], &value[i]);	
	pd();	
	printf("%d\n", bag[n-1][s]);
	return 0;
}