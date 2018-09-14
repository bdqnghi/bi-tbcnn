/********
冒泡排序的算法
by AutuanLiu
********/
#include <iostream>
using namespace std;
void swap(int &a,int &b){
	int temp = a;
	a = b;
	b = temp;
}
 int main(){
 	int n; //(1<n<1000)
 	cin >> n;
 	int v[1000];
 	for (int i = 0; i < n; ++i)
		 cin >> v[i];
 	for (int i = 0; i < n; ++i)
 	{
 		bool bl=true;
 		for (int j = i; j < n; ++j)
 		{
 			if(v[j-1] > v[j])
 			{
 				swap(v[j-1],v[j]);
 				bl=false;
 			}
 		}
 		if(bl)
 			continue;
 	}
 	for (int i = 0; i < n; ++i)
 	{
 		cout << v[i]<<' ';
 	}
 	return 0;
 }