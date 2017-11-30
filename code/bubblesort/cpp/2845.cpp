// bubble sort
// hw3 of algorithmics
// 10/11/2016
#include<iostream>
using namespace std;

int swaptimes(int* arr, int &l) {
	int sum=0;
	for(int i=1; i<l; i++) {
		for(int j=i-1; j>=0; j--) {
			if(arr[j+1] < arr[j]){
				sum++;
				swap(arr[j+1], arr[j]);
			}
		}
	}
	return sum;
}

int main() {
	int data;
	cin>>data;
	
	int len[data],ans[data], arr[100];
	for(int i=0; i<data; i++) {
		cin>>len[i];
		for(int j=0; j<len[i]; j++) {
			cin>>arr[j];
		}
		ans[i] = swaptimes(arr, len[i]);
	}
	
	for(int i=0; i<data; i++) {
		cout<<"Optimal swapping takes "<<ans[i]<<" swaps."<<endl;
	}
}
