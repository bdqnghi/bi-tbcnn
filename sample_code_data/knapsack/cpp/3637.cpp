#include<stdio.h>
#define SZ 1000


int mem[SZ][SZ], W;
int N, v[SZ], w[SZ];


int MAX(int a, int b){
	return (a>b)?a:b;
}

int dp(){
	int i, j;
	for(i=1; i<=N; i++){
		for(j=1; j<=W; j++){
			if( j<w[i] ){
				mem[i][j] = mem[i-1][j];
			}else if( j>=w[i] ){
				mem[i][j] = MAX(mem[i-1][j], mem[i-1][j-w[i]]+v[i]);
			}
		}
	}
	return mem[N][W];
}


int main(){
	int i, g;
	scanf("%d", &N);
	for(i=1; i<=N; i++)
		scanf("%d%d", &v[i], &w[i]);
	scanf("%d", &g);
	printf("%d\n", dp());
	return 0;
}