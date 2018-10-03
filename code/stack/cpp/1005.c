#include "stack.h"

static void print(int& i)
{
	cout << i << " ";
}

void test_stack()
{
	Stack<int, 5> stack;
	cout << "push 1" << endl; stack.push(1);
	cout << "push 2" << endl; stack.push(2);
	cout << "push 3" << endl; stack.push(3);
	cout << "push 4" << endl; stack.push(4);
	stack.traverse(print); cout << endl;
	cout << "pop "<< stack.top() << endl;
	stack.pop();
	cout << "pop "<< stack.top() << endl;
	stack.pop();
	cout << "pop "<< stack.top() << endl;
	stack.pop();
	cout << "pop "<< stack.top() << endl;
	stack.pop();
	stack.traverse(print); cout << endl;
	
	cout << "push 1" << endl; stack.push(1);
	cout << "push 2" << endl; stack.push(2);
	cout << "push 3" << endl; stack.push(3);
	cout << "push 4" << endl; stack.push(4);
	cout << "push 5" << endl; stack.push(5);
	stack.traverse(print); cout << endl;
	cout << "push 6" << endl; stack.push(6);
	stack.traverse(print); cout << endl;
}
