#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <fstream>

using namespace std;

// Very similar to the coin change problem, we want to know if we can build a number or not
int main() {
	freopen("./sample.txt", "r", stdin);
	int T, n, k; // k = expected sum
	cin>>T;
	while(T > 0) {
		cin>>n>>k;
		vector<int> a(n); // a = integers we have
		int *table = new int[k+1]; // table = integers we can make
		for(int i = 0; i < n; i++) {
			cin>>a[i];
		}
		memset(table, 0, sizeof(int)*(k+1));
		table[0] = 1; // Don't use any integers to build zero
		bool corner_case = 0;
		// Optimization 1: If k is a multiple of any of our integers, or if we have a 1, we can trivially build k
		for(int i = 0; i < n; i++) {
			if(a[i] == 0 || k%a[i] == 0) {
				cout<<k<<"\n";
				corner_case = 1;
				break;
			}
		}
		if(corner_case) {
			T--;
			continue;
		}
		// Optimization 2: We use a standard DP approach, except we break after each loop if we've found a way to form k
		for(int i = 0; i < n; i++) {
			for(int j = 0; j + a[i] <= k; j++) {
				if(table[j]) {
					table[j + a[i]] = 1;
				}
			}
			if(table[k]) {
				break;
			}
		}
		for(int i = k; i >= 0; i--) {
			if(table[i]) {
				// We can build i, which the closest we can get to k
				cout<<i<<"\n";
				break;
			}
		}
		T--;
	}
  return 0;
}

