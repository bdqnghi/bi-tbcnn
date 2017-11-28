#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;



void merge(vector<int> &a,vector<int> &b){

          int i = 0,j = 0;
          vector<int> final;
          while(i < a.size() && j < b.size()){
                    if(a[i] <= b[j]){
                        final.push_back(a[i]);
                        i++;
                    }
                    else{
                        final.push_back(b[j]);
                        j++;
                    }

          }

          if(i == a.size()){
                while(j < b.size()){
                      final.push_back(b[j]);
                      j++;
                }
          }
          if(j == b.size()){
                while(i < a.size()){
                      final.push_back(a[i]);
                      i++;
                }
          }
}

void mergesort(vector<int> &arr){

            int m = arr.size()/2;

            if(m != 0){
                  vector<int>l (arr.begin(),arr.begin() + m-1);
                  vector<int>r (arr.begin() + m,arr.end());

                  mergesort(l);
                  mergesort(r);
                  merge(l,r);

            }

            for(int i = 0;i < arr.size();i++){
                         cout<<arr[i]<<" ";
            }
            cout<<endl;
}


int main(){
      cout<<"Enter vector size :: "<<endl;
      int n;
      cin>>n;

      vector<int> arr(n);

      for(int i = 0;i < n;i++){
                   cin>>arr[i];
      }

      mergesort(arr);

      return 0;

}
