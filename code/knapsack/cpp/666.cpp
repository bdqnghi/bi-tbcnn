#include <iostream>
#include <conio.h>
using namespace std;
int max(int a,int b){
	if(a>b)return a;
	return b;
}
int main(){
	int W;
	cout<<"Enter total number of bags :";
	cin>>W;
	int a[W+1]={0},b[W+1]={0};
	cout<<"Enter weight of each bag\n";
	for(int i=1;i<=W;i++){
		cout<<"Bag "<<i+1<<" : ";
		cin>>a[i];
	}
	cout<<"\n\nEnter value of each bag\n";
	for(int i=1;i<=W;i++){
		cout<<"Bag "<<i+1<<" : ";
		cin>>b[i];
	}
	int val;
	cout<<"Enter required weight : ";
	cin>>val;

	int value[W+1][val+1];

	for(int i=0;i<=W;i++)
		for(int j=0;j<=val;j++)
			value[i][j]=0;

	for(int i=1;i<=W;i++){
		for(int j=1;j<=val;j++){
			if(a[i]<=j){
				value[i][j]=max(value[i-1][j],b[i]+value[i-1][j-a[i]]);
			}else{
				value[i][j]=value[i-1][j];
			}
		}
	}

	for(int i=0;i<=W;i++){
		for(int j=0;j<=val;j++){
			cout<<value[i][j]<<" ";
		}
		cout<<endl;
	}

	cout<<"\n"<<value[W][val];
	return 0;
}
