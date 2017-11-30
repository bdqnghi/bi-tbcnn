/*------------Algorithm: Merge Sort Algorithm------------------*/
/*------------Author: Bharath Thiruveedula-------------------*/

#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int> &a , int low, int mid, int high) {
		int l = low, h = high, m = mid+1, i=low;
		int temp[a.size()];
		while(l<= mid && m<= high) {
			if(a[l]<=a[m]) {
				temp[i] = a[l];
				l++;
			}
			else {
				temp[i] = a[m];
				m++;
			}
			i++;
		}

		if(m<=high) {
			for(int j=m; j<=high; j++) {
				temp[i] = a[j];
				i++;
			}
		}

		if(l<=mid) {
			for(int j=l; j<=mid; j++) {
				temp[i] = a[j];
				i++;
			}	
		}
		for(int j=low;j<=high;j++) {
			a[j] = temp[j];
		}
}

void partition(vector<int> &a, int low, int high) {
	int mid;
	if(low < high){
		mid = (low + high)/2;
		partition(a, low, mid);
		partition(a, mid+1, high);
		merge(a, low, mid, high);
	}
}

int main(){
	vector<int> a;
	for(int i=10;i>0;i--) {
		a.push_back(i);
	}
	cout<<"Before Sorting: "<<endl;
	for(int i=0;i<a.size();i++) {
		cout<<a[i]<<" ";
	}
	cout<<endl;
	partition(a,0,a.size()-1);
	cout<<"After Sorting: "<<endl;
	for(int i=0;i<a.size();i++) {
		cout<<a[i]<<" ";
	}
	return 0;
}
