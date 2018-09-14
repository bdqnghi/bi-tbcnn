//This implements a mergesort for integers
#include <iostream>
using namespace std;

void merge(int data[], int n1, int n2){
  //create local variable to count how many are merged
  int count = 0;
  int count1 = 0;
  int count2 = 0;

  //initialize temp array
  int *temp;
  temp = new int[n1+n2];

  while(count1 < n1 && count2 < n2){
    if(data[count1] <= (data + n1)[count2]){
	temp[count++] = data[count1++];
    } else {
	temp[count++] = (data+n1)[count2++];
    }
  }
  
  //now copy the remaining elements of half arrays
  while(count1 < n1)
	temp[count++] = data[count1++];
  while(count2 < n2)
	temp[count++] = (data+n1)[count2++];


  //copy temp into data
  for(int i=0; i<n1+n2; i++)
    data[i] = temp[i];

  delete [] temp;
}

void mergesort(int data[], int n){
  //check for base case
  if(n > 1){
    
    //find new middle
    int n1 = n/2;
    int n2 = n - n1;

    //recursive calls
    mergesort(data,n1);
    mergesort(data+n1,n2);
    merge(data, n1, n2);
  }
}
  
int main(int argc, char **argv){

  int data[10] = {3, 4, 5, 2, 1, 7, 8, 9, 6, 0};
  int n = 10;
  mergesort(data, n);

  for(int i=0; i<n; i++)
    cout << data[i] << ", ";
  cout << endl;
}
  
