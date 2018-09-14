#include <iostream>
#include <fstream>

using namespace std;

const int maxn = 1005;

int n, v[maxn];

int main() {
    ifstream fin("date.in");
    ofstream fout("date.out");

    cout << 2000000000 + 1999999999 << '\n';

    fin >> n;
    for(int i = 0; i < n; ++ i)
        fin >> v[i];

    bool change = 1;
    while(change) {
        change = 0;
        for(int i = 0 ; i + 1 < n;  ++ i) {
            if(v[i] > v[i + 1]) {
                swap(v[i], v[i + 1]);
                change = 1;
            }
        }
    }
    for(int i = 0; i < n; ++ i)
        fout << v[i] << ' ';
    return 0;
}
