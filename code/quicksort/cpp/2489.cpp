#include "quicksort.h"
#include<cstdlib>
#include<ctime>
#include<iostream>
using namespace std;
quicksort::quicksort(int data[],int length):sort(data,length)
{}

void quicksort::ordinarysort(int low,int high)
{
    if(low<high)
    {
      int privotkey=partition(low,high);
      ordinarysort(low,privotkey-1);
      ordinarysort(privotkey+1,high);
}
}

void quicksort::swap(int index1,int index2)
{
   if(index1!=index2)
    {
     returndata()[index1]=returndata()[index1]+returndata()[index2];
     returndata()[index2]=returndata()[index1]-returndata()[index2];
     returndata()[index1]=returndata()[index1]-returndata()[index2];
}
   // int temp=returndata()[index1];
   // returndata()[index1]=returndata()[index2];
   // returndata()[index2]=temp;
    
}
int quicksort::partition(int low,int high)
 {
        
  swap(low,randIndex(low,high));
   int privolet=returndata()[low];
   while(low<high)
    {
       while(low<high&&returndata()[high]>=privolet) --high;
             returndata()[low]=returndata()[high];        
      while(low<high&&returndata()[low]<=privolet) ++low;
             returndata()[high]=returndata()[low];        
}    
 returndata()[low]=privolet;    
   return low; 
}

int quicksort::randIndex(int low,int high)
{
  srand(time(NULL));
  return rand()%(high-low+1)+low;
}



void quicksort::improvsort(int low, int high,int k)
{
          
    qsort_improve(low,high,k);

   for(int i=low+1;i<=high;++i)
   {
         int j=i-1;
         int temp=returndata()[i];
    for(;returndata()[j]>temp&&j>=0;--j) returndata()[j+1]=returndata()[j];
    returndata()[j+1]=temp;
}

}



void quicksort::qsort_improve(int low,int high,int k)

{

   if(high-low>=k)

     {

      
      int privotkey=partition(low,high);
      qsort_improve(low,privotkey-1,k);
      qsort_improve(privotkey+1,high,k);     
}
}



