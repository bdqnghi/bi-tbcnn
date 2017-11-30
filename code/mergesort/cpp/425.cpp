#include "mergesort.h"

MergeSort::MergeSort()
{

}

void MergeSort::merge_sort(int low, int high, int* p){
    int pivot;
    static int i(1);
    if (high>low)
    {
        i++;
        pivot = low + ((high - low)/2);
        cout << pivot << endl;
        merge_sort(low, pivot, p);
        merge_sort(pivot+1, high, p);
        merge(low, pivot, high, p);

    }
}
void MergeSort::merge(int l, int pi, int h,int* arr)
{
            int start = l;
        int mid = pi+1;
        while((start<=pi)&&(mid <=h)){
            if (arr[start] > arr[mid])
            {
                int temp = arr[mid];
                arr[mid] = arr[start];
                arr[start] = temp;
                mid++;
             }
            else
                start++;
    }
}

///
void MergeSort::merge2(int* input, int p, int r)
{
    int mid = floor((p + r) / 2);
    int i1 = 0;
    int i2 = p;
    int i3 = mid + 1;

    // Temp array
    int temp[r-p+1];

    // Merge in sorted form the 2 arrays
    while ( i2 <= mid && i3 <= r )
        if ( input[i2] < input[i3] )
            temp[i1++] = input[i2++];
        else
            temp[i1++] = input[i3++];

    // Merge the remaining elements in left array
    while ( i2 <= mid )
        temp[i1++] = input[i2++];

    // Merge the remaining elements in right array
    while ( i3 <= r )
        temp[i1++] = input[i3++];

    // Move from temp array to master array
    for ( int i = p; i <= r; i++ )
        input[i] = temp[i-p];
}

void MergeSort::merge_sort2(int* input, int p, int r)
{
    if ( p < r )
    {
        int mid = floor((p + r) / 2);
        merge_sort2(input, p, mid);
        merge_sort2(input, mid + 1, r);
        merge2(input, p, r);
    }
}

