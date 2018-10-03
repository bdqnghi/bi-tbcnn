#include "heap.h"

Heap::Heap(int c)
{
    myHeap.resize(c);
    size = 1;
    qty = 0;
}

Heap::~Heap()
{

}

Heap::Heap(Heap &other)
{
    copy(other);
}

Heap& Heap::operator=(Heap &other)
{
    if(this != &other)
        copy(other);
    return *this;
}

void Heap::copy(Heap &other)
{
    for(int i = 0; i < other.size; i++)
        myHeap[i] = other.myHeap[i];
    size = other.size;
    qty = other.qty;
}

void Heap::insert(string x, int p, int l)
{
    myHeap[qty].data = x;
    myHeap[qty].par = p;
    myHeap[qty].line = l;
    int i = qty;
    while(myHeap[i] < myHeap[parent(i)])
    {
        swap(myHeap[i], myHeap[parent(i)]);
        i = parent(i);
    }
    qty++;
    if(qty == size)
        resizeUp();
}

void Heap::swap(Node &a, Node &b)
{
    Node temp = a;
    a = b;
    b = temp;
}

Node Heap::removeMin()
{
    Node min = myHeap[0];
    if(qty > 0)
    {
        myHeap[0] = myHeap[qty-1];
        myHeap[qty-1].data = "\0";
        qty--;
        int i = 0;
        int smallerChild = indexOfMin(leftChild(i), rightChild(i));
        while(myHeap[i] > myHeap[smallerChild] && smallerChild < qty)
        {
            swap(myHeap[i], myHeap[smallerChild]);
            i = smallerChild;
            if(rightChild(i) < qty)
                smallerChild = indexOfMin(leftChild(i), rightChild(i));
            else
                smallerChild = qty;
        }

        if(qty == size/2-1)
            resizeDown();
    }
    return min;
}

int Heap::indexOfMin(int x, int y)
{
    if(myHeap[y].data == "\0")  //if y >= qty
        return x;
    return (myHeap[x] < myHeap[y]) ? x : y;
}

int Heap::leftChild(int i)
{
    return 2*i+1;
}

int Heap::rightChild(int i)
{
    return 2*i+2;
}

int Heap::parent(int i)
{
    return (i-1)/2;
}

int Heap::numOfElements()
{
    return qty;
}

void Heap::resizeUp()
{
    size = size*2;
    myHeap.resize(size);
}

void Heap::resizeDown()
{
    size = size/2;
    myHeap.resize(size);
}

ostream& operator<<(ostream &out, Heap &t)
{
    for(int i = 0; i < t.myHeap.size(); i++)
        out << setw(3) << i << setw(4) << t.myHeap[i].par << " " << t.myHeap[i].line << " "<< t.myHeap[i].data << endl;
    return out;
}

