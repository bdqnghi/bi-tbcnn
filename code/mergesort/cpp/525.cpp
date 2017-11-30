#include<stdio.h>
#include<stdlib.h>
#define MAX 1000000
void mergearray(int a[], int first, int mid, int last, int temp[])  
{  
    int i = first, j = mid + 1;  
    int m = mid,   n = last;  
    int k = 0;  
      
    while (i <= m && j <= n)  
    {  
        if (a[i] <= a[j])  
            temp[k++] = a[i++];  
        else  
            temp[k++] = a[j++];  
    }  
      
    while (i <= m)  
        temp[k++] = a[i++];  
      
    while (j <= n)  
        temp[k++] = a[j++];  
      
    for (i = 0; i < k; i++)  
        a[first + i] = temp[i];  
}  
void mergesort(int a[], int first, int last, int temp[])  
{  
    if (first < last)  
    {  
        int mid = (first + last) / 2;  
        mergesort(a, first, mid, temp);   
        mergesort(a, mid + 1, last, temp);  
        mergearray(a, first, mid, last, temp);  
    }  
} 
int main(){
	int n,i;
	int *array=(int *)malloc(MAX*sizeof(int));
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",array+i);
	}
	int *p;
	p=(int *)malloc((n+1)*sizeof(int));
	mergesort(array,0,n-1,p);
	for(i=0;i<n;i++){
		printf("%d",*(array+i));
		if(i!=n-1) printf(" ");
	}
	free(p);
	return 0;	 
}
