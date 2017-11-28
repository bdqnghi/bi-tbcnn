#include <iostream>
#include <stdio.h>

using namespace std;

void Swap(double *a, double *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void Bubblesort(double *arr,int count)
{
    for(int i=0; i<count; ++i)
        for(int j=0; j<count-i-1; ++j)
        {
            if(arr[j]<arr[j+1])
                Swap(&arr[j],&arr[j+1]);
        }
}

void test()
{
    double arr[100];
    char tmp;
    cout<<"������һ�����飺";
    int count=0;
    do
    {
        scanf("%lf%c",&arr[count],&tmp);
        count++;
    }while(tmp!='\n');
    Bubblesort(arr, count);
    cout<<"�������������ǣ�";
    for(int i=0; i<count; ++i)
        cout<<arr[i]<<' ';
    cout<<endl;
}

int main()
{
    while(1)
        test();
    return 0;
}
