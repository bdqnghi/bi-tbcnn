#include<stack>
#include<iostream>
using namespace std;

stack<int> sortOrder(stack<int> myStack);

stack<int> sortOrder(stack<int> myStack)
{
	stack<int> sortStack;
	while(!myStack.empty())
	{
		int tmp = myStack.top();
		myStack.pop();
		while(!sortStack.empty() && sortStack.top()>tmp)
		{
			myStack.push(sortStack.top());
			sortStack.pop();
		}
		sortStack.push(tmp);
	}
	return sortStack;
}

int main()
{
	stack<int> myStack, sortStack;
	myStack.push(4);
	myStack.push(6);
	myStack.push(2);
	myStack.push(9);
	myStack.push(1);
	myStack.push(5);
	myStack.push(0);
	sortStack = sortOrder(myStack);
	while(!sortStack.empty())
	{
		cout<<sortStack.top()<<" ";
		sortStack.pop();
	}
	cout<<endl;
}
