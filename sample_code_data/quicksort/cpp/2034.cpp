#include <iostream>

void quick_sort( int* array, int left, int right )
{
  if( left >= right ) return;
  int l = left-1;
  int r = right;
  while( true ) {
    while( array[++l] < array[right] ) if( l >= r ) break;
    while( array[--r] > array[right] ) if( l >= r ) break;
    if( l >= r ) break;
    int temp = array[l];
    array[l] = array[r];
    array[r] = temp;
  }
  int temp = array[l];
  array[l] = array[right];
  array[right] = temp;
  quick_sort( array, left, l-1 );
  quick_sort( array, l+1, right );
}

int main() {
  int intarray[] = {77, 22, 1, 44, 22, -12, -1, 1, 13, 105, 12, 0, -4};

  quick_sort(intarray, 0, 12);

  for (int i = 0; i < 13; i++) {
    std::cout << intarray[i] << " ";
  }
  std::cout << std::endl;
}
