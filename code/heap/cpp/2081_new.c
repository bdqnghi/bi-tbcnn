#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct HeapNode
{
    friend bool operator < (HeapNode a,HeapNode b)
    {
        if (a.f == b.f)
            return a.step < b.step;
        return a.f < b.f;
    }
    int p[4][2],step,curmin,f;
};

struct Heap
{
    HeapNode heap[2000010];
    int hs;
    void init()
    {
        hs = 0;
    }
    void sink(int p)
    {
        HeapNode a = heap[p];
        for (int q = p<<1; q <= hs; p = q, q <<= 1)
        {
            if (q < hs && heap[q+1] < heap[q]) ++q;
            if (!(heap[q] < a)) break;
            heap[p] = heap[q];
        }
        heap[p] = a;
    }
    HeapNode del()
    {
        HeapNode r = heap[1];
        heap[1] = heap[hs--];
        sink(1);
        return r;
    }
    void swim(int p)
    {
        HeapNode a = heap[p];
        for (int q = p>>1; q && a < heap[q]; p = q, q >>= 1)
            heap[p] = heap[q];
        heap[p] = a;
    }
    void ins(HeapNode a)
    {
        heap[++hs] = a;
        swim(hs);
    }
};

int main()
{
}
