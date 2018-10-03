#include <iostream>
using namespace std;

template <class Elem>
class BinaryHeap
{
public:
	BinaryHeap(int MaxSize = 50);
	BinaryHeap(const BinaryHeap<Elem> &rhs);
	BinaryHeap(Elem *Array, int ElemNum, int MaxSize);
	~BinaryHeap(void);

	Elem *Sort(void);              //堆排序
	bool Add(const Elem &Item);    //添加元素
	Elem Remove(void);             //移除（堆顶）元素

	inline int GetSize(void);      //获取当前堆大小

protected:
	Elem *Data;                    
	int CurrentNum;
	const int MAX_SIZE;

	void HeapifyUp(int Node);            //向上调整堆  
	void HeapifyDown(int Node);          //向下调整堆

	inline int ParentOf(int Node);       //得到节点的父节点位置
	inline int LeftChildOf(int Node);    //得到节点的左儿子位置
};

//constructor function
template <class Elem>
BinaryHeap<Elem>::BinaryHeap(int MaxSize) :MAX_SIZE(MaxSize)
{
	Data = new Elem[MAX_SIZE];
	CurrentNum = 0;
}

//copy constructor function
template <class Elem>
BinaryHeap<Elem>::BinaryHeap(const BinaryHeap<Elem> &rhs) :MAX_SIZE(rhs.MAX_SIZE), CurrentNum(rhs.CurrentNum)
{
	Data = new Elem[MAX_SIZE];
	strcpy(Data, rhs.Data);
}

//array constructor
//将数组元素构建成最大堆
template <class Elem>
BinaryHeap<Elem>::BinaryHeap(Elem *Array, int ElemNum, int MaxSize) :MAX_SIZE(MaxSize)
{
	Data = new Elem[MAX_SIZE];
	CurrentNum = ElemNum;

	for (int i = 0; i < ElemNum; ++i)
		Data[i] = Array[i];

	for (int i = ParentOf(CurrentNum - 1); i >= 0; --i)   //单步向前，数组从后往前，树从上到下调整
		HeapifyDown(i);
}

template <class Elem>
BinaryHeap<Elem>::~BinaryHeap(void)
{
	if (Data)
		delete[] Data;
}

//最大堆调整
template <class Elem>
int BinaryHeap<Elem>::ParentOf(int Node)
{
	//assert(Node > 0);
	return (Node - 1) / 2;
}

template <class Elem>
int BinaryHeap<Elem>::LeftChildOf(int Node)
{
	return (Node * 2) + 1;
}

//最大堆调整：从Node位置向上调整（数组向前，Node后不管）
template <class Elem>
void BinaryHeap<Elem>::HeapifyUp(int Node)
{
	int Current = Node;
	int Parent = ParentOf(Node);
	Elem Item = Data[Current];

	while (Current > 0)
	{
		if (Item > Data[Parent])
		{
			Data[Current] = Data[Parent];
			Current = Parent;
			Parent = ParentOf(Current);
		}
		else
			break;
	}
	Data[Current] = Item;
}

//最大堆调整：从Node位置向下调整（数组向后，Node前不管）
template <class Elem>
void BinaryHeap<Elem>::HeapifyDown(int Node)
{
	int Current = Node;
	int Child = LeftChildOf(Node);
	Elem Item = Data[Current];

	while (Child < CurrentNum)
	{
		if (Child < (CurrentNum - 1))
		{
			if (Data[Child] < Data[Child + 1])
				++Child;
		}

		if (Item < Data[Child])
		{
			Data[Current] = Data[Child];
			Current = Child;
			Child = LeftChildOf(Current);
		}
		else
			break;
	}
	Data[Current] = Item;
}

//添加元素
template <class Elem>
bool BinaryHeap<Elem>::Add(const Elem &Item)
{
	if (CurrentNum >= MAX_SIZE)
		return false;

	Data[CurrentNum] = Item;
	HeapifyUp(CurrentNum++);
	return true;
}

//移除元素
template <class Elem>
Elem BinaryHeap<Elem>::Remove(void)
{
	assert(CurrentNum > 0);

	Elem Temp = Data[0];
	Data[0] = Data[--CurrentNum];  //此处是用数组最后一个填补
	HeapifyDown(0);                //从上往下调整
	return Temp;

	//或选择键值大的儿子填补空位，重复该步骤直到最后一个元素填补了空位 	
}

template <class Elem>
inline int BinaryHeap<Elem>::GetSize(void)
{
	return CurrentNum;
}

//堆排序
template <class Elem>
Elem* BinaryHeap<Elem>::Sort(void)
{
	Elem *NewArray = new Elem[CurrentNum];

	//升序
	for (int ElemNum = CurrentNum - 1; ElemNum >= 0; --ElemNum)
		NewArray[ElemNum] = Remove();

	/*降序
	int ElemNum = CurrentNum;
	for (int i = 0; i < ElemNum; ++i)
		NewArray[i] = Remove();
	*/

	return NewArray;
}
