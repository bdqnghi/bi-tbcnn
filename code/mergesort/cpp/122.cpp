#include<iostream>

void mergesort(int a[],int i, int j );
void merge(int a[], int i1, int j1, int i2, int j2);



 int main(int argc, char const *argv[])
{
int a[10]={23,34,45,32,65,767,97,33,1,9};

	/* code */
mergesort(a,0,9);
int i=0;
for(i=0;i<10;i++)
	std::cout << a[i] << " " ;
	return 0;
}

void mergesort(int a[],int i,int j)
{
    int mid;
        
    if(i<j)
    {
        mid=(i+j)/2;
        std::cout << "\nmid is " << mid;
        mergesort(a,i,mid);        //left recursion
        mergesort(a,mid+1,j);    //right recursion
        merge(a,i,mid,mid+1,j);    //merging of two sorted sub-arrays
    }
}

void merge(int a[], int i1, int i2, int j1, int j2){
	int temp [50];//array to store intermediate results
	int i , j,k;
	i=i1;//begining of array
	j=i2 ; //begining of 2nd array
 k=0;
//loop till we finish all items in both the arrays and kepp inserting them into the temp 
	//in the end transfer back from temp;

while(i<=j1 && j<=j2){
	if(a[i]<a[j])
		temp[k++]=a[i++];
	else
		temp[k++]=a[j++];
}
//one list get over -- now 
 while(i<=j1)    //copy remaining elements of the first list
        temp[k++]=a[i++];
        
    while(j<=j2)    //copy remaining elements of the second list
        temp[k++]=a[j++];
        
    //Transfer elements from temp[] back to a[]
    for(i=i1,j=0;i<=j2;i++,j++)
        a[i]=temp[j];

}