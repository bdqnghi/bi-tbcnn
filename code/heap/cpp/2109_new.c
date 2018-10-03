#include<stdio.h>
int heap[]= {1,2,3,4,6,5,7,8},rear=8;
void print_r(int *arr,int n)
{
    int i;
    printf("Array:[ ");
    for(i=0; i<n; i++)
        printf("%d ",arr[i]);
    printf("]\n");
}
void addHeap(int in)
{
    int c=rear,tmp;
    heap[rear]=in;
    rear++;
    while(c>0)
    {
        if(heap[(c-1)/2]>heap[c])
            break;
        tmp=heap[(c-1)/2];
        heap[(c-1)/2]=heap[c];
        heap[c]=tmp;
        c=(c-1)/2;
    }
}
void buildHeap()
{
    int i,c,tmp;
    for(i=rear-1; i>=0; i--)
    {
        c=i;
        while(c>0)
        {
            if(heap[(c-1)/2]>heap[c])
                break;
            tmp=heap[(c-1)/2];
            heap[(c-1)/2]=heap[c];
            heap[c]=tmp;
            c=(c-1)/2;
        }
    }
}
int popHeap()
{
    int ans=heap[0];
    heap[0]=heap[rear-1];
    rear--;
    buildHeap();
    return ans;
}
int sortHeap()
{
    int tmp;
    while(rear>0)
    {
        tmp=heap[0];
        heap[0]=heap[rear-1];
        heap[rear-1]=tmp;
        rear--;
        buildHeap();
    }
}
void sortHeap2()
{
    int i,pos,tmp,c;
    for(i=rear-1; i>=0; i--)
    {
        tmp=heap[0];
        heap[0]=heap[rear-1];
        heap[rear-1]=tmp;
        rear--;
        c=0;
        while(2*c+1<rear)
        {
            pos=2*c+1;
            if(pos+1<rear)
            {
                if(heap[pos]<heap[pos+1])pos++;
            }
            if(heap[pos]>heap[c])
            {
                tmp=heap[pos];
                heap[pos]=heap[c];
                heap[c]=tmp;
                c=pos;
            }
            else break;
        }
    }
}
int main()
{

    buildHeap();
    sortHeap2();
    print_r(heap,8);

    return 0;
}
