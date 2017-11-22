#include "bubblesort.h"

void BubbleSort::sort(int array[], int size)
{
    for (int j = 0; j < size - 1; j++)
     {
         int f = 0;
         int min = j;
         for (int i = j; i < (size - j - 1); i++)
         {
             if (array[i] > array[i + 1])
             {
                 int temp = array[i];
                 array[i] = array[i + 1];
                 array[i + 1] = temp;
                 f = 1;
             }
             if (array[i] < array[min])
             min = i;
         }

         if (f == 0)
             break;

         if (min != j)
         {
             int temp = array[j];
             array[j] = array[min];
             array[min] = temp;
         }
     }
}
