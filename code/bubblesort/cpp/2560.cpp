//Bubble sort
 
#include<iostream>
using namespace std;

void bubble_sort(int ar[], int size){
	bool flag = 1;
	int temp;
	for(int i = 0; i < size, flag == 1; i++){
		flag = 0;
		for(int j = 0; j < size-1; j++){
			if(ar[j] > ar[j+1]){
				temp = ar[j];
				ar[j] = ar[j+1];
				ar[j+1] = temp;
				flag=1;
			}
		}				
	}
}

void display(int ar[], int size){
	for(int i=0; i<size; i++)
		cout<<ar[i]<<" ";
	cout<<endl;
}
int main(){
	int a[] = {10,8,9,6,7,2,4,5,1,3};
	int size = 10;
	display(a,size);
	bubble_sort(a,size);
	display(a,size);
}
