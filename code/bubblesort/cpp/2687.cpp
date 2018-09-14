// C program for implementation of Bubble sort
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <time.h>

using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
int bubbleSort(int arr[], int n)
{
   int i, j, compare=0;
   for (i = 0; i < n-1; i++)
   {
      compare++;
       // Last i elements are already in place
       for (j = 0; j < n-i-1; j++)
       {
        compare++;
           if (arr[j] > arr[j+1])
           {
              compare ++;
              swap(&arr[j], &arr[j+1]);
           }
        }
    }
  return compare;
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
  ofstream file("bubble_analysis.csv",ios::out|ios::app);

    int s;
        for(int j=0; j<100 ;j++)
        {
            //generating random size of array between 30-1000
            do{
                s = rand()%1000;
               }while(s<30);


            int arr[s];
            //seeding random
            srand((unsigned)time(NULL));
            //generating random inputs of random sized array
            for(int i=0 ; i<s ; i++)
                arr[i] = rand()%100000 + 1;

            file << s << ',' << bubbleSort(arr, s) << endl;
        }

    file.close();
    return 0;
}
