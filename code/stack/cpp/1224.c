#ifdef STACK
#include <iostream>
#include <vector>

using namespace std;

class Stack_Vector
{
public:
	Stack_Vector();
	int Peek();
	void Pop();
	void Push(int);

private:
	vector< int > vData;
	int nTop;
};

Stack_Vector::Stack_Vector()
{
	nTop = -1;
}

int Stack_Vector::Peek()
{
	return vData.at(nTop);
}

void Stack_Vector::Pop()
{
	vData.pop_back();
	--nTop;
}

void Stack_Vector::Push(int data)
{
	vData.push_back(data);
	++nTop;
}

template< typename T >
struct Node
{
	Node*	pNext;
	T		data;
};

template< typename T >
class Stack_List
{
public:
	Stack_List();
	T Peek();
	void Pop();
	void Push(T);

private:
	Node< T >* pTop;
};

template< typename T >
Stack_List< T >::Stack_List()
{
	pTop = new Node< T >();
	pTop->pNext = nullptr;
}

template< typename T>
T Stack_List< T >::Peek()
{
	return pTop->data;
}

template< typename T>
void Stack_List< T >::Pop()
{
	Node< T >* pTmp = pTop;
	pTop = pTop->pNext;

	delete pTmp;
}


template< typename T>
void Stack_List< T >::Push(T data)
{
	Node< T >* pNewNode = new Node< T >();
	pNewNode->data = data;
	pNewNode->pNext = pTop;

	pTop = pNewNode;
}


int main()
{
	/*
	Stack_Vector		oStack;

	oStack.Push(1);
	oStack.Push(2);
	oStack.Push(3);
	oStack.Push(4);
	oStack.Push(5);

	cout << oStack.Peek() << endl;

	oStack.Pop();
	oStack.Pop();
	oStack.Pop();

	cout << oStack.Peek() << endl;
	*/

	Stack_List< double >	oStack_List;

	oStack_List.Push(1.1);
	oStack_List.Push(2.2);
	oStack_List.Push(3.3);
	oStack_List.Push(4.4);
	oStack_List.Push(5.5);

	cout << oStack_List.Peek() << endl;

	oStack_List.Pop();
	oStack_List.Pop();
	oStack_List.Pop();

	cout << oStack_List.Peek() << endl;

	return 0;
}

#endif