#include<iostream>
using namespace std;
/**
***归并排序
***输入:数组名,以及长度。
***输出:无
**/
void mergesort(int array[],int low,int high);
void merge(int array[],int low,int mid,int high);
int main()
{   
    int array[4]={4,2,3,1};
    mergesort(array,0,3);
    for(int i=0;i<4;i++)
    {
        cout<<array[i]<<endl;
    }   
    return 0;
}
void mergesort(int array[],int a_low,int a_high)
{

    if(a_low>=a_high)
    {
        return;
    }
   /* if((!array)||a_low>=a_high||a_low<0||a_high<0)
    {
        return;
    }*/
    int low=a_low;
    int high=a_high;
    int mid=(low+high)/2;
    /*分而治之*/
    mergesort(array,low,mid);
    mergesort(array,mid+1,high);
    merge(array,low,mid,high);
}
void merge(int array[],int m_low,int m_mid,int m_high)
{
    int low_start=m_low;
    int low_end=m_mid;
    int high_start=m_mid+1;
    int high_end=m_high;
    int temp[m_high-m_low+1];
    int index=0;//
    while(low_start<=low_end&&high_start<=high_end)
    {
        if(array[low_start]<=array[high_start])
            temp[index++]=array[low_start++];
        else
            temp[index++]=array[high_start++];
    }
    if(low_start>low_end)
    {
        while(high_start<=high_end)
        {
            temp[index++]=array[high_start++];
        }
    }
    else
    {
        while(low_start<=low_end)
            temp[index++]=array[low_start++];
    }
    for(int i=m_low;i<=m_high;i++)
    {
       array[i]= temp[i-m_low];
    }
}
        
