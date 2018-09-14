#include<stdio.h>
#include<algorithm>
using namespace std;
struct MyDate
{
    int enterNumber;
    long long timeAfter;
};
int const MAXN = 1000;
int n = 16;
//long long mas[MAXN] = {1,19,4,7,5,8,3,9,4};
long long mas [MAXN] = {16, 2, 77, 40,120 ,1 ,2 ,11 ,65 ,43 ,83 ,56 ,89 ,23 ,76 ,54};


void printMas()
{
    for(int i = 0; i <= n - 1; i++)
    {
        printf("%lld ", mas[i]);
    }
    printf("\n");
}

int my_partition(int e, int b)
{
    printf("b = %d, e = %d ", b, e);
    long long pivot = mas[e];
    int i = b;
    int j = e;
    int x;
    while(i < j)
    {

        while(mas[i] <= pivot) i++;
        while(mas[j] >= pivot) j--;
        if(i < j)
        {
            swap(mas[i], mas[j]);
        }

    }
    scanf("%d", &x);
    //printf("pivot = %d, i = %d, j = %d\n", pivot, i ,j);
    printf("Intervals: [%d, %d) [%d %d) ", b,j,j,e);
    printMas();
    printf("\n");
    return j;
}

int my_partition2(int b, int e)
{
    long long pivot = mas[e];
    printf("pivot = %d, b = %d,  e = %d\n", pivot, b ,e);
    int j = b;
    for(int i = b; i <= e - 1; i++)
        if(mas[i] <= pivot)
        {
            swap(mas[i], mas[j]);
            j++;
        }
    swap(mas[e], mas[j]);
    printMas();
    return j;
}
void quickSort(int b, int e)
{
    if(b < e)
    {
        int p = my_partition2(e, b);
        quickSort(b, p);
        quickSort(p - 1 , e);
    }
}

int main()
{
   quickSort(0, n - 1);

    printf("%d", my_partition2(0, n - 1));
    /* scanf("%d", &n);
     for(int i = 0; i <= n; i++)
     {
         int hour, minutes, seconds, day, month, year;
         scanf("%d:%d:%d %d.%d.%d", &hour, &minutes, &seconds, &day, &month, &year);
     }
     */

}
