#include <stdio.h>
//2750
int main(){ 
    int n, temp, arr[1000];
    scanf("%d",&n);
    for(int i = 0 ; i<n;i++) scanf("%d", &arr[i]);
    for(int j = 1 ; j<=n; j++){
        for(int i = 0; i<n-j;i++){
            if(arr[i] > arr[i+1]){
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
    for(int i = 0; i < n; i++){
        printf("%d",arr[i]);
        if(i != n-1) printf("\n");
    }
}