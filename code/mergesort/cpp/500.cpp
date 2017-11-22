#include <stdio.h>
#include <stdlib.h>
int mergeSort(int r[],int left,int right,int *temp){
	if(left>=right) return 0;//base case
	int p=(left+right)/2;
	mergeSort(r,left,p,temp);
	mergeSort(r,p+1,right,temp);
	int i,t,j;
	i=left;
	j=p+1;
	t=0;
	while((i<=p)&&(j<=right)){
		if(r[i]<r[j]){
			temp[t]=r[i];
			t++;
			i++;
		}else{
			temp[t]=r[j];
			t++;
			j++;
		}
	}
	while(i<=p){
		temp[t]=r[i];
		i++;
		t++;
	}
	while(j<=right){
		temp[t]=r[j];
		j++;
		t++;
	}
	for(i=0;i<t;i++){
		r[left+i]=temp[i];
	}
	return 0;
}
int main(){
	int r[10];
	printf("\n{");
	for(int i=0;i<=9;i++){
		r[i]=rand()%100;
		printf(" %d ",r[i]);
	}
	printf("}\n");
	int temp[10];
	mergeSort(r,0,9,temp);
	printf("\n{");
	for(int i=0;i<=9;i++){
		printf(" %d ",r[i]);
	}
	printf("}\n");
}