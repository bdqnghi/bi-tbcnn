#include <iostream>
#include "heap.h"
using namespace std;

int main()
{
    class Heap heap(9);
    heap.Max_Heap_Insert(24);
    heap.show();
    cout <<endl;
    heap.Max_Heap_Insert(58);
    heap.show();
    cout <<endl;
    heap.Max_Heap_Insert(17);
    heap.show();
    cout <<endl;
    heap.Max_Heap_Insert(79);
    heap.show();
    cout <<endl;
    heap.Max_Heap_Insert(27);
    heap.show();
    cout <<endl;
    heap.Max_Heap_Insert(30);
    heap.show();
    cout <<endl;
    heap.Max_Heap_Insert(8);
    heap.show();
    cout <<endl;
    heap.Max_Heap_Insert(80);
    heap.show();
    cout <<endl;
    heap.Max_Heap_Insert(12);
    heap.show();
    cout <<endl;
    heap.Max_Heap_Insert(70);
    heap.show();
}
