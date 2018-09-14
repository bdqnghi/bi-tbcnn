//
//Bubble Sort Example
//Worst case O(n^2)
//Best Case O(n)
//Average Case O(n^2)
//
//

#include <iostream>
#include <algorithm>


int main(){
  int array[] = {4,2,8,1,6,5,9,3,7};
  bool swapped;

  do{
    swapped = false;
    for(int i=1;i<sizeof(array)/sizeof(array[0]);i++){
      if(array[i-1] > array[i]){
        swapped = true;
        std::swap(array[i-1], array[i]);
      }
    }
  }while(swapped);
      

  for(int i=0;i<sizeof(array)/sizeof(array[0]);i++){
    std::cout << array[i];
  }
  std::cout << std::endl;
  return 0;
}
