#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void print(vector<int>& arr)
{
    for(vector<int>::iterator iter = arr.begin(); iter != arr.end(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

int partition(vector<int>& arr, int start, int end)
{
    int p = start, l = start, r = end;
    int pvalue = arr[p];
    while(l < r)
    {
        while(l < r && arr[r] >= pvalue) --r;
        arr[p] = arr[r];
        p = r;
        while(l < r && arr[l] <= pvalue) ++l;
        arr[p] = arr[l];
        p = l;
    }
    arr[p] = pvalue;
    return p;
}

int median(vector<int>& arr, int mid = -1)
{
    if (mid < 0) mid = arr.size() / 2;
    int l = 0, r = arr.size() - 1;
    while(l < r)
    {
        int p = partition(arr, l, r);
        if (p > mid) r = p - 1;
        else if (p < mid) l = p + 1;
        else return arr[mid];
    }
    return arr[mid];
}

int quicksort(vector<int>& arr, int start, int end)
{
    if(start >= end) return 0;
    int p = partition(arr, start, end);
    quicksort(arr, start, p - 1);
    quicksort(arr, p + 1, end);
    return 0;
}

int main()
{
    int nums[] = {4,1,4,3,4,3,3,2,0,2};
    vector<int> arr;
    for (int i = 0; i < 10; ++i)
        arr.push_back(nums[i]);

    // srand((unsigned int)time(NULL));
    // vector<int> arr;
    // for(int i = 0; i < 100; ++i)
    //     arr.push_back(rand() % 500);
    vector<int> arr2(arr);

    print(arr);
    quicksort(arr, 0, arr.size() - 1);
    print(arr);
    cout << median(arr2) << endl;

    return 0;

}