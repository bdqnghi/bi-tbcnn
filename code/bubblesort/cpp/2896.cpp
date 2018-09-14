#include <cstdio>
#define MOD 10000007

long long merge (int arr[], int temp[], int left, int mid, int right) {
    long long inv_count = 0;
    int i, j, k;
    
    i = k = left;
    j = mid;
    while ((i <= mid-1) && (j <= right))
    {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid-i);
        }
    }
    
    while (i <= mid-1) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    for (i = left; i <= right; i++) arr[i] = temp[i];
    return inv_count;
}

long long merge_sort (int *arr, int *temp, int left, int right) {
    long long inv_count = 0;
    int mid;
    
    if (right > left) {
        mid = (right + left) / 2;
        inv_count = merge_sort (arr, temp, left, mid);
        inv_count += merge_sort (arr, temp, mid+1, right);
        inv_count += merge (arr, temp, left, mid+1, right);
    }
    return inv_count;
}

int main (int argv, char** args)
{
    int tc, n;
    scanf ("%d", &tc);
    
    for (int t = 1; t <= tc; t++) {
        scanf ("%d", &n);
        int numbs[n], temp[n];
        for (int i = 0; i < n; i++) scanf ("%d", &numbs[i]);
        printf ("Case %d: %lld\n", t, merge_sort (numbs, temp, 0, n-1) % MOD);
    }
    return 0;
}