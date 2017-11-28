#include <iostream>
#include <cstdlib>

using namespace std;

#define MAX 100

int W, n; 
int v[MAX];
int w[MAX];
int c[MAX][MAX];

int main(){
    cin >> W >> n;
    
    for(int i = 1;i<=n;i++){
            cin >> v[i] >> w[i];
    }
    for(int i = 1;i<=n;i++){
            for(int j = 1;j<=W;j++){
                 if(i == 0 || j == 0) c[i][j] = 0;
                 if(w[i] <= j) c[i][j] = max((v[i]+c[i-1][j-w[i]]), c[i-1][j]);   
                 else c[i][j] = c[i-1][j];
                 
            }
    }
    for(int i = 0;i<=n;i++){
            for(int j = 0;j<=W;j++){
                    cout << c[i][j] << " ";
            }
            cout << endl;
    }
    system("pause");
    return 0;
} 
