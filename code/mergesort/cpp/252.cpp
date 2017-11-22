// Merge Sort

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <new>

using namespace std;

vector<int> a;

void merge(int,int,int);

void merge_sort(int low,int high) {
  int mid;
  if (low < high) {
    mid = (low + high) / 2;
    merge_sort(low, mid);
    merge_sort(mid+1, high);
    merge(low, mid, high);
  }
}

void merge(int low,int mid,int high)
{
  int h,i,j,k;
  int * const b = new int[a.size()];
  h=low;
  i=low;
  j=mid+1;

  while((h <= mid) && (j <= high)) {
    if(a[h]<=a[j]) {
      b[i]=a[h];
      h++;
    }
    else {
      b[i]=a[j];
      j++;
    }
    i++;
  }
  if(h > mid){
    for(k = j; k <= high; k++) {
      b[i]=a[k];
      i++;
    }
  }
  else {
    for(k=h;k<=mid;k++) {
      b[i]=a[k];
      i++;
    }
  }
  for(k=low;k<=high;k++) 
    a[k]=b[k];

  delete[] b;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    cout << "Enter the filename with the unsorted numbers\n";
    return 1;
  }

  ifstream file;
  file.open(argv[1]);
  int i;
  while (file >> i) a.push_back(i);
  file.close();

  merge_sort(0, a.size()-1);
  cout<<endl;
/*  cout<<"So, the sorted list (using MERGE SORT) will be :"<<endl;

  for(i=0;i<a.size();i++)
    cout<<a[i]<<" ";
*/
  
  return 0;
}

