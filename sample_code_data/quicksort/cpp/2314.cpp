
#include <iostream>
#include <vector>

#include "utils.h"

using namespace std;

void helper(vector<int>& nums, int start, int end){
    
    if(start >= end) return;

    int pivot = nums[end];
    int idx = start - 1;
    
    for(int i = start; i <= end; i++){
        if(nums[i] <= pivot){
            int temp = nums[i];
            nums[i] = nums[++idx];
            nums[idx] = temp;
        }
    }
    helper(nums, start, idx-1);
    helper(nums, idx+1, end);
}

void quicksort(vector<int>& nums){
    helper(nums, 0, nums.size()-1);
}

int main(){

    vector<int> nums = randomIntVector(20);

    cout << "Unsorted: \n";
    printNums(nums);

    quicksort(nums);   
    cout << "\nSorted: \n";
    printNums(nums);
    
    return 0;
}
