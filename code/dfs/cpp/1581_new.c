/*
ID: CHN
PROG: milk3
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <cmath> 
#include <algorithm>
using namespace std;

int a, b, c;
bool z[21][21][21];
bool ans[21];

int dfs(int p, int q, int r) {
    if (z[p][q][r]) return 0;
    z[p][q][r] = true;
    if (p == 0) ans[r] = true;
    // 1 -> 2
    if (q < b) {
        if (p + q < b) 
            dfs(0, q + p, r);
        else
            dfs(p - (b - q), b, r);
    }
    // 1 -> 3
    if (r < c) {
        if (p + r < c) 
            dfs(0, q, r + p);
        else
            dfs(p - (c - r), q, c);
    }
    // 2 -> 1
    if (p < a) {
        if (p + q < a) 
            dfs(p + q, 0, r);
        else
            dfs(a, q - (a - p), r);
    }
    // 2 -> 3
    if (r < c) {
        if (q + r < c) 
            dfs(p, 0, q + r);
        else
            dfs(p, q - (c - r), c);
    }
    // 3 -> 1
    if (p < a) {
        if (p + r < a) 
            dfs(p + r, q, 0);
        else 
            dfs(a, q, r - (a - p));
    }
    // 3 -> 2
    if (q < b) {
        if (q + r < b) 
            dfs(p, q + r, 0);
        else
            dfs(p, b, r - (b - q));
    }
}

int main() {
    freopen("milk3.in", "r", stdin);
    freopen("milk3.out", "w", stdout);
    
    cin >> a >> b >> c;
    
    dfs(0, 0, c);
    
    bool space = false;
    for (int i = 0; i <= c; ++i) 
     if (ans[i]) {
         if (space) cout << " ";
         space = true;
         cout << i;
     }
    cout << endl;
    
    return 0;
}
