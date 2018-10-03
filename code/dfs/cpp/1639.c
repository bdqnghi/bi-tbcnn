#include<iostream>
#include<vector>
using namespace std;

int const M = 1000;
int a, b, c, d, visited[M];
vector<int> krawedz[M];

void Wczytaj(){
	cin >> a >>b;
	for(int i=0; i<b; i++){
		cin >> c >>d;
		krawedz[c].push_back(d);
	}
	for(int i=0; i<=a; i++){
		visited[i]=0;
	}
}

void Wypisz_krawedz(int i){
	cout << "[" << i <<"] ";
	for(int j=0; j<krawedz[i].size(); j++){
		cout << krawedz[i][j] <<" ";
	}
	cout <<"\n";
}
	
void Wypisz(int a){
	for(int i=1; i<a+1; i++){
		Wypisz_krawedz(i);
	}
}

void DFS(int a){
	visited[a] = 1;
	cout << a <<" ";
	for(int j=0; j<krawedz[a].size(); j++){
		if(visited[krawedz[a][j]]!=1){
		DFS(krawedz[a][j]);
		}
	}
}

int main(){
	Wczytaj();
	int c;
	cin >> c;
	DFS(c);
return 0;
}
