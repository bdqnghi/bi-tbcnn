#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>

int* BubbleSort(int* unsorted, int size);
void printArray(int* array, int size);

void main(){
	int list[10]={5,4,1,4,5,4,3,6,10,9};
	int* list2;
	list2 = BubbleSort(list,10);
	printArray(list2,10);
   getche();
}

int* BubbleSort(int* unsorted, int size){
	//int* sorted = (int*)malloc(sizeof(int)* size);
   int tmp;
	for(int pos=0;pos<size;pos++){

		for(int i =0; i < size-pos; i++){
   		if(unsorted[i+1] < unsorted[i]){
      	   tmp = unsorted[i+1];
            unsorted[i+1]=unsorted[i];
            unsorted[i]=tmp;
         }
      }
	}
   return unsorted;
}




void printArray(int* array, int size){
	for(int i=0; i<size; i++){
   	printf("\n %d", array[i]);
   }


}

