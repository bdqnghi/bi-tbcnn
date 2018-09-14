#include<iostream>

using namespace std;
int c[2024];
int w[2024];
int dyn[2024][2024]; // N x S
int main() {
    int s, n;

    cin >> s >> n;

    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> c[i];
    }

    for (int k = 0; k <= n; k++) {
        dyn[k][0] = 0;
    }

    for (int j = 0; j <= s; j++) {
        dyn[0][j] = 0;
    }

    for (int k = 1; k <= n; k++) {
        for (int j = 1; j <= s; j++) {
            if (j < w[k]) {
                dyn[k][j] = dyn[k - 1][j];
            } else {
                dyn[k][j] = max(dyn[k - 1][j], dyn[k-1][j - w[k]] + c[k]);
            }
        }
    }

    cout << dyn[n][s] << endl;

    return 0;
}