#include <stdio.h>
#define MAX 2000

int ans[MAX][MAX];
int p[MAX];
int w[MAX];

int max_profit(int W, int n){
	int aux1, aux2;
	if(n<0 || W<=0)	return 0;
	if(ans[W][n] != -1)	return ans[W][n];
	if(W>=w[n])	aux1 = max_profit(W-w[n], n-1) + p[n];
	else aux1 = 0;
	aux2 = max_profit(W, n-1);
	if(aux1>aux2){
		ans[W][n] = aux1;
		return aux1;
	}
	ans[W][n] = aux2;
	return aux2;	
}

int main(){
	p[0] = 1; p[1] = 2; p[2] = 1; p[3] = 3; p[4] = 5; p[5] = 7; p[6] = 3;
	w[0] = 1; w[1] = 2; w[2] = 4; w[3] = 6; w[4] = 10; w[5] = 2; w[6] = 3;
	int weight=5, n = 2;
	int i, j;
	for(i=0; i<=weight; i++){
		for(j=0; j<=n; j++){
			ans[i][j] = -1;
		}
	}
	printf("%d\n", max_profit(weight, n));	
}
