#include<bits/stdc++.h>
using namespace std;
int comparison=0;            //Global variable for calculating total no of comparisons to sort an array
void merge_array(double *ar, int n){          //procedure for merging two arrays

    double *temp;
    int k=n/2,j=0;
    temp = new double[n];                     //creating temporary array to store merged sorted array

    for(int i=0; i<n; i++){                //merging sorted arrays
    if ( j<n/2 && k<n){
        if (ar[j] < ar[k]){              //comparing smaller value and storing in temp[]
            temp[i] = ar[j];
            j++;
        }
        else{
            temp[i] = ar[k];
            k++;
        }
    }
    else if (j==n/2){
        temp[i] = ar[k];
        k++;
    }
    else{
        temp[i] = ar[j];
        j++;
    }
    comparison++;                        //incrementing comparison in each step
    }
    for (int i=0; i<n; i++)              //copying sorted merged array temp[] into original array arr[]
        ar[i] = temp[i];

    delete temp;
}
void merge_sort(double *ar, int n){       //procedure for sorting array by dividing and conquer
 if (n>1){
     merge_sort(ar,n/2);              //recursive procedure call on half of the array
     merge_sort(ar+ n/2, n - n/2);
     merge_array(ar,n);               //merge two half arrays
    }
 }

 int main(){
    clock_t begin=clock();
    int t;
    scanf("%d",&t);
    while(t--){
    comparison=0;
    int n;
    scanf("%d",&n);                   //size of array
    double arr[n];
    for(int i=0;i<n;i++){            //input array
        scanf("%lf",&arr[i]);
    }
    merge_sort(arr,n);               //sorting array
    /*for(int i=0;i<n;i++){
        printf("%lf ",arr[i]);        //displaying array
    }*/
    printf("%d\n",comparison);       //printing total no. of comparison required for sorting array
    }
	clock_t end=clock();
	double time= double(end - begin) / CLOCKS_PER_SEC;
	printf("%lf\n",time);
    return 0;

 }
