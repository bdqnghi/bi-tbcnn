#define MAXN 2000
#define MAXK 1000

int matrix[MAXN][MAXK+1];
int cost[MAXN];
int profit[MAXN];

int knapsack(int n,int k) {
    int c;
    REP(i,n) memset(matrix[i],0,sizeof(matrix[i]));
    for(int i=cost[0]; i<=k; i++)
        matrix[0][i] = profit[0];
    for(int i=1;i<n;i++)
        REP(j,k+1){
            if(j-cost[i] >= 0) 
                c = matrix[i-1][j-cost[i]]+profit[i];
            else	
                c = 0;
            if(c < matrix[i-1][j]) 
                c = matrix[i-1][j];
            matrix[i][j] = c;
        }
    return matrix[n-1][k];		
}
