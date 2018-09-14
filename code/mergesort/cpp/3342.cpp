#include <iostream>
#include <stdio.h>
using namespace std;
#define MAXN 100

int buf[MAXN];
//int a[MAXN];

int a[MAXN] = {1, 5, 9, 10, 39, 5, 45, 82, 92};
int n = 10;

void printArray(int *pArr, int n)
{
  for(int i = 0 ; i < n; i++)
    printf("%d ", pArr[i]);
  printf("\n");
}

int mergeSortedArrays(int b, int m , int e)
{
  int k = b;
  int i = b;
  int j = m;
  printf("YOLO\n");
  while(i < m && j < e)
    buf[k++] = a[i] > a[j] ? a[i++] : a[j++];

  printf("YOLO\n");

  while(i < b)
    buf[k++] = a[i++];

  while(j < e)
    buf[k++] = a[j++];


  // for(k = b; i < e; k++)
  //   a[k] = buf[k];
}

int main()
{
  mergeSortedArrays(0, (0 + n)/2, n);
  printArray(a, n);
  return 0;
}
