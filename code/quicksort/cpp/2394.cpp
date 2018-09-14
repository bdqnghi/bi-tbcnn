#include <string>
#include <vector>
#include <iostream>

using namespace std;

void quickSort(vector<int>& arr, int left, int right) {
      int i = left, j = right; // 0 4
      int tmp;
      int pivot = arr[(left + right)/2]; // 2
      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };
//      for (int k=0; k<arr.size();k++) {
//            cout << arr[k] << " ";
 //     }
  //    cout << endl; 
      /* recursion */
   //   cout << "left recursion" << endl; 
      if (left < j)
            quickSort(arr, left, j);
   //   cout << "right recursion" << endl;
      if (i < right)
            quickSort(arr, i, right);
     // for (int k=0; k<arr.size();k++) {
     //       cout << arr[k] << " ";
     // }
     // cout << endl;
}

int main(){
      int n;
      cin >> n;
      vector<int> a(n);
      for(int a_i = 0;a_i < n;a_i++){
            cin >> a[a_i];
      }
      quickSort(a, 0, n-1);
      cout << "DONE" << endl;
      for (int k=0; k<a.size();k++) {
            cout << a[k] << " ";
      }
      cout << endl;
      return 0;
}