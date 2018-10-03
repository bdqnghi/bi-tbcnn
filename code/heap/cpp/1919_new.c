#include "Heap.h"

int Heap::size()
{
    return heap.size();
}

Heap::Heap()
{
}

Heap::~Heap()
{
}

void Heap::insert(int element, int position)
{
    //heap.push_back(element);
    heap.insert(heap.begin()+position,element);
    heapifyup(heap.size() - 1);
}

void Heap::insert(int element)
{
    heap.push_back(element);
    heapifyup(heap.size() - 1);
}

int Heap::deletemin()
{
    int min = heap.front();
    heap[0] = heap.at(heap.size() - 1);
    heap.pop_back();
    heapifydown(0);
    return min;
}

void Heap::print()
{
    vector<double>::iterator pos = heap.begin();
    cout << "Heap = ";
    while ( pos != heap.end() ) {
        cout << *pos << " ";
        ++pos;
    }
    cout << endl;
}

void Heap::heapifyup(int index)
{
    //cout << "index=" << index << endl;
    //cout << "parent(index)=" << parent(index) << endl;
    //cout << "heap[parent(index)]=" << heap[parent(index)] << endl;
    //cout << "heap[index]=" << heap[index] << endl;
    while ( ( index > 0 ) && ( parent(index) >= 0 ) &&
            ( heap[parent(index)] > heap[index] ) )
    {
        int tmp = heap[parent(index)];
        heap[parent(index)] = heap[index];
        heap[index] = tmp;
        index = parent(index);
    }
}

void Heap::heapifydown(int index)
{
//    cout << "index=" << index << endl;
//    cout << "left(index)=" << left(index) << endl;
//    cout << "right(index)=" << right(index) << endl;
//    int child = left(index);
//    if ( ( child > 0 ) && ( right(index) > 0 ) &&
//         ( heap[child] > heap[right(index)] ) )
//    {
//        child = right(index);
//    }
//    if ( child > 0 )
//    {
//        int tmp = heap[index];
//        heap[index] = heap[child];
//        heap[child] = tmp;
//        heapifyup(child);
//    }
    sort(heap.begin(),heap.end());
}

int Heap::left(int parent)
{
    int i = ( parent << 1 ) + 1; // 2 * parent + 1
    return ( i < heap.size() ) ? i : -1;
}

int Heap::right(int parent)
{
    int i = ( parent << 1 ) + 2; // 2 * parent + 2
    return ( i < heap.size() ) ? i : -1;
}

int Heap::parent(int child)
{
    if (child != 0)
    {
        int i = (child - 1) >> 1;
        return i;
    }
    return -1;
}
int Heap::getmin()
{
    return heap.front();
}

