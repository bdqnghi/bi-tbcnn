#define THRESHOLD 5

using namespace std;
#include <iostream>
#include <stdint.h>
#include <string>
#include <fstream>
#include <algorithm>

//prototypes
unsigned int find_pivot(int *arr, const unsigned int size);
unsigned int find_pivotLastElement(int *arr, const unsigned int size);
unsigned int find_pivotFirstElement(int *arr, const unsigned int size);
unsigned int find_pivotMedianElement(int *arr, const unsigned int size);
unsigned int partition(int *arr, const unsigned int size);
void quickSort(int *arr, const unsigned int size);
void swap(int *arr, const unsigned int a, const unsigned int b);
void printArr(int *arr, const unsigned int size);
template <typename Iterator>
double median(Iterator begin, Iterator end);


long numComparisons = 0;

int main()
{
    
  int numbers[10];
    
  string line;
  ifstream myfile ("/Users/tjordan/Desktop/aaa/test/test/10.txt");
  if (myfile.is_open()) {
    int position = 0;
    while ( myfile.good() ) {
      getline (myfile,line);
      numbers[position] = atoi(line.c_str());
      position++;
    }
    myfile.close();
  }
    
  else cout << "Unable to open file" << endl;;
    
  //int arr[] = {3,9,8,4,6,10};
    int size;
    size = sizeof(numbers)/sizeof(int);
    
    printArr(numbers, size);
    quickSort(numbers, size);

    printArr(numbers,size);
    cout << numComparisons << endl;;
}

void printArr(int *arr, const unsigned int size)
{
    int i;
    
    for(i=0;i<size;i++)
        cout << arr[i] << " " ;
    cout << "\n";
}

void quickSort(int *arr, const unsigned int n)
{
    unsigned int p;
    
    if(n > 1) {
        p = find_pivotLastElement(arr , n);
        swap(arr,p, n-1);
        p = partition(arr, n);
        swap(arr, p, n-1);
        quickSort(arr,p);
        quickSort(&arr[p+1], n-p-1);
    }
}

void swap(int *arr, const unsigned int a, const unsigned int b)
{
    int c;
    c = arr[a];
    arr[a] = arr[b];
    arr[b] = c;
}

unsigned int find_pivotLastElement(int *arr, const unsigned int n)
{
    return n-1;
}

unsigned int find_pivotFirstElement(int *arr, const unsigned int n)
{
    return 0;
}

unsigned int find_pivotMedianElement(int *arr, const unsigned int n) {
  int a = arr[0];
    int b = arr[n - 1];
    int c = arr[(n - 1) / 2];
    
    int median = max(min(a,b), min(max(a,b),c));
    if(median == a) {
        return 0;
    } else if(median == b) {
        return n - 1;
    } else {
        return (n - 1) / 2;
    }
}

unsigned int find_pivot(int *arr, const unsigned int n) {
    
    if(arr[0] > arr[n/2]) {
        if(arr[n-1] > arr[0]) {
            return 0;
        }
        if(arr[n/2] > arr[n-1]) {
            return n/2;
        }
        return n-1;
    }
    
    if(arr[n-1] > arr[0]) {
        if(arr[n-1] > arr[n/2]) {
            return n/2;
        }
        return n-1;
    }
    return 0;
}

unsigned int partition(int *arr, const unsigned int n) {
    unsigned int l = 0;
    unsigned int r;
      cout << "n  is " << n << " added " << n -1 << endl;
    
    if(n > 1) {
        r = n - 2;
        while(l < r) {
            while(arr[l] < arr[n - 1]) {
                l++;
            }
            for(; (r > 0) && (arr[r] >= arr[n - 1]); r--) {
                ;
            }
            if(l < r) {
                swap(arr, l++, r--);
            }
        }
        numComparisons += n - 1;
    }
    if(l == r && arr[l] < arr[n - 1]) {
        l++;
    }
    return l;
}