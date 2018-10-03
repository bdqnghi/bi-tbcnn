#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int const M = 1000;
int a, b, c, d, visited[M];
vector<int> krawedz[M], lista1, lista2;

void visited_clear(){
	for(int i=0; i<M; i++){
		visited[i]=0;
	}
}

void Wczytaj(){
	cin >> a >>b;
	for(int i=0; i<b; i++){
		cin >> c >>d;
		krawedz[c].push_back(d);
	}
}

void Wypisz_krawedz(vector<int> x){
	for(int j=0; j<x.size(); j++){
		cout << x[j] <<" ";
	}
	cout <<"\n";
}
	
void Wypisz(int a){
	for(int i=1; i<a+1; i++){
		cout << "[" << i <<"] ";
		Wypisz_krawedz(krawedz[i]);
	}
}

void DFS(int a){
	visited[a] = 1;
	lista1.push_back(a);
	for(int j=0; j<krawedz[a].size(); j++){
		if(visited[krawedz[a][j]]!=1){
		DFS(krawedz[a][j]);
		}
	}
}

void przeszukuj(int a){
	visited_clear();
	DFS(a);
	Wypisz_krawedz(lista1);
}

void topos(int a){
	visited[a] = 1;
	for(int j=0; j<krawedz[a].size(); j++){
		if(visited[krawedz[a][j]]!=1){
		topos(krawedz[a][j]);
		}
	}
	lista2.push_back(a);
}

void sortuj(int a){
	visited_clear();
	topos(a);
	for(int j=lista2.size()-1; j>=0; j--){
		cout << lista2[j] <<" ";
	}
	cout <<"\n";
}

int main(){
	Wczytaj();
int c;
cin >> c;
przeszukuj(c);
sortuj(c);
return 0;
}
