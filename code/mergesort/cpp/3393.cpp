/*************************************************************************
    > File Name: mergesort.cpp
    > Author: jeff zhu
    > Mail: 908190355@qq.com 
    > Created Time: 2016年10月22日 星期六 22时47分14秒
 ************************************************************************/

#include <iostream>

using namespace std;

void merge (int *a , int start , int mid , int end) {
    int count = 0;
    int b[end-start];
    int i = start;
    int j = mid;

    while (i != mid && j != end) {
        if (a[i] < a[j]) {
            b[count++] = a[i];
            i++;
        }else {
            b[count++] = a[j];
            j++;
        }
    }
    if (i == mid) {
        for (int k = j ; k < end ; k++)
            b[count++] = a[k];
    }else {
        for (int k = i ; k < mid ; k++)
            b[count++] = a[k];
    }
    for (int i = 0 ; i < end-start ; i++)
        a[i+start] = b[i];
}

void mergesort (int start , int end , int *a) {
    if (end-start > 1) {
        int mid = (start + end) / 2;
        mergesort (start , mid , a);
        mergesort (mid , end , a);
        merge (a , start , mid , end);
    }
}

bool bin_search (int *a , int start , int end , int value) {
    if (end-start < 1)
        return false;
    int mid = (start+end)/2;

    if (a[mid] == value)
        return true;
    else if (a[mid] < value)
        return bin_search (a , mid+1 , end , value);
    else
        return bin_search (a , start , mid , value);
}

int main () {
    int a[30];

    for (int i = 0 ; i < 30 ; i++)
        a[i] = 29-i;
    mergesort (0 , 30 , a);

    for (int i = 0 ; i < 30 ; i++)
        cout << a[i] << " ";
    cout << endl;

    if (bin_search (a, 0 , 30 , 15))
        cout << "15 ok" << endl;
    else
        cout << "15 no" << endl;
}
