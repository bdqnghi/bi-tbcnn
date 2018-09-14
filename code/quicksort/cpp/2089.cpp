#include <bits/stdc++.h>


using namespace std;


ifstream fin("sdo.in");
ofstream fout("sdo.out");

const int NMAX = 3000002;

int k; int n;

int v[NMAX];

int quick(int st, int dr) {

	if(st >= dr)
		return v[k];;

	int p = st + rand() % (dr - st + 1);

	swap(v[dr], v[p]);

	int index = st - 1;

	//intre st si index elemente mai mici decat pivotul v[dr] inclusiv
	//intre index + 1 si dr elemente mai mare sau egale ca pivotul

	for(int i = st; i < dr ; ++i)
		if(v[i] < v[dr]) {
			index++;
			swap(v[i], v[index]);
		}



	swap(v[dr], v[index + 1]);


	if(index  + 1 == k)
		return v[index + 1];

	if( k <= index)
		return quick(st, index);
	if( k >= index + 2)
		return quick(index + 2, dr);

}


int main() {

	srand(time(NULL));
	
	fin >> n >> k;
	for(int i = 1 ; i <= n ; ++i)
		fin >> v[i];
	fout << quick(1, n);

	return 0;
}