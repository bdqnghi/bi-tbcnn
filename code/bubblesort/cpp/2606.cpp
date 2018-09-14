#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
void bubbleSort(vector<int> &arr) {
		int n =arr.size();
      bool swapped = true;
      int j = 0;
      // int tmp;
      while (swapped) {
            swapped = false;
            j++;
            for (int i = 0; i < n - j; i++) {
                  if (arr[i] > arr[i + 1]) {
                  		swap(arr[i], arr[i+1]);
                        swapped = true;
                  }
            }
      }
}
	
};


int main(){
	vector<int> nums={1,4,2,5,3,7,6,9};
	Solution ss;
	ss.bubbleSort(nums);
	for(auto it : nums){
		cout<<it<<" ";
	}
	cout<<endl;
	return 0;
}