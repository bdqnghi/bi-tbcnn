#include "bubblesort.h"

void BubbleSort::sort(vector<int> &v){
  for (int i=0; i<v.size(); ++i){
    bool swap = false;
    for (int j=0;j<v.size()-i-1;++j){
      if (v[j]>v[j+1]){
        int tmp=v[j];
        v[j]=v[j+1];
        v[j+1]=tmp;
        swap = true;
      }
    }
    if (!swap) return;
  }
}

