#include <iostream>
#include <cstring>
#include <string>
#pragma warning(disable:4996)

using namespace std;
int dp[7][7];

int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

int main(void) {
	int itemnumber = 6;
	int MaX_WEITHT = 100;

	int val[7] = { 0,40,35 ,18 ,4,10,2 };
	int w[7] = { 0,100,50,45,20,10 ,5 };
	

	cout << endl;
	cout << "����\t" << "��ġ\t����" << endl;
	for (int i = 0; i < itemnumber + 1; i++) {
		cout << i << "��\t" << val[i] << "\t" << w[i] << endl;
	}

	cout << endl;
	for (int i = 0; i < MaX_WEITHT +1; i++) {	
		for (int j = 0; j < itemnumber + 1; j++){
			dp[i][j] = 0;
		}
	}

	for (int j = 1; j < itemnumber+1; j++){
		for (int i = 0; i < MaX_WEITHT+1; i++) {
			if (i < w[j])
				dp[i][j] = dp[i][j - 1];
			else
				dp[i][j] = max(dp[i][j - 1], dp[i - w[j]][j-1] + val[j]);
		}
	}

	cout <<"���� : " << dp[100][6];
	
	cin >> itemnumber;
	return 0;
}



