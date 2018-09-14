//I decided to create a quickSort that could work on a private, non-global array.
//You pass into the array and size of array
//it will return the pointer to the first element of a new array that's been sorted

#include <iostream>

using namespace std;


void outputlist(int thelist[], int thesize)
{
    for(int i = 0; i<thesize ; i++)
        {
        cout << thelist[i] << endl;
        }
}

int * quickSort(int n[], int thesize)
{
    int pivot = n[thesize/2]; //selects the pivot halfway through the list

    //creates 3 arrays, their max size for same is the full array, upper and lower can be as high as one less than initial
    int * lower;
    int * same;
    int * upper;
    lower = new int [thesize-1];
    int lowerp = 0;
    same = new int [thesize];
    int samep = 0;
    upper = new int [thesize-1];
    int upperp = 0;


    //sorts through the initial array and throws the correct values into the correct new array
    for(int i = 0; i<thesize ; i++)
        {
        if(n[i] > pivot)
            {
            upper[upperp] = n[i];
            upperp++;
            }
        else if(n[i] < pivot)
            {
            lower[lowerp] = n[i];
            lowerp++;
            }
        else
            {
            same[samep] = n[i];
            samep++;
            }
        }

    //recursive calls of quickSort on smaller arrays, only bothers if they have at least 2 values.
    if(lowerp > 1)
        {
        int *lloc = quickSort(lower, lowerp);
        for(int i = 0; i < lowerp ; i++)
            {
            lower[i] = *(lloc+i);
            }
        }
    if(upperp > 1)
        {
        int *uloc = quickSort(upper, upperp);
        for(int i = 0; i < upperp ; i++)
            {
            upper[i] = *(uloc+i);
            }
        }

    //updates the array with the new order
    for(int i = 0; i < lowerp; i++)
        n[i] = lower[i];
    for(int i = 0; i < samep; i++)
        n[i + lowerp] = same[i];
    for(int i = 0; i < upperp; i++)
        n[i+ lowerp + samep] = upper[i];

    //returns the pointer to the updates array's 0 value.
    int *resultloc = &n[0];
    return resultloc;
}

int main(void)
{
int num[15] = {11, 22, 33, 44, 33, 41, 44, 40, 11, 13, 14, 40, 40, 14, 59};
int thesize = (sizeof(num)/sizeof(*num));

int *loc = quickSort(num, thesize);
for(int i = 0; i<thesize ; i++)
    {
    num[i] = *(loc+i);
    }

outputlist(num,thesize);

return 0;
}
