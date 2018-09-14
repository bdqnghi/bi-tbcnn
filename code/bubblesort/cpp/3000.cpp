#include<iostream>

void swap(int &a,int &b){
  int temp = a;
  a = b;
  b = temp;
}

void bubbleSort(int A[], int n){
  bool sorted = false;
  while (!sorted){
    sorted = true;
    for (int i = 1; i < n; i++){
      if (A[i-1]>A[i]){
	swap(A[i-1],A[i]);
	sorted = false;
      }
   }
    n--;
  }
}
int main(void){
  int a[10]={1,3,4,6,2,4,2,5,6,5};
  bubbleSort(a,10);
  for (int c : a){
    std::cout<<c;
  }

}
