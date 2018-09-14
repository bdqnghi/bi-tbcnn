//冒泡排序递归实习
#include <iostream>
#include <algorithm>

void bubbleSort(int A[],int lo,int hi)
{
    if(lo == hi)
        return;
    int last = lo; //记录一次循环后,比较后交换最大的元素的index

    for(int i = 0;i < hi -1;i++) //经过n-1比较
    {
        if(A[i+1] < A[i])
        {
            swap(A[i+1],A[i]);
            last = i+1; //最后交换两个元素中较大的下标
        }

    }


    bubbleSort(A,lo,last);
}

//冒泡排序2个for循环实现

void bubbleSort1(int A[],int lo,int hi)
{
    int last = hi;
    while(lo < last)        //while可以用for实现for(int i = lo;i < last;i++)
    {
        int n = last;
        last = lo;
        for(int i = 0;i < n -1;i++)
        {
            if(A[i] > A[i+1])
            {
                swap(A[i],A[i+1]);
                last = i+1;
            }
        }
    }
}

int main()
{
    int data[] = {0,8,4,3,5,9,4,19};
    vector<int> vi(begin(data),end(data));
    cout << "数组未排序前: \n";
    for_each(vi.begin(),vi.end(),[](const int& val){cout << val << " ";});
    cout << endl << endl;


    bubbleSort1(data,0,vi.size());
    cout << "数组排序后: " << endl;
    for(int i = 0;i < (int)vi.size();i++)
        cout << data[i] << " ";
    cout << endl;

    bubbleSort(data,0,vi.size());

    for(int i = 0;i < (int)vi.size();i++)
        cout << data[i] << " ";

    cout << endl;

}
