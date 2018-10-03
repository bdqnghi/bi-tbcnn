#include <iostream>

using namespace std;

struct StackElement
{
	char value;
	StackElement *next = nullptr;
};

struct Stack
{
	StackElement *head = nullptr;
};

Stack* createStack()
{
	return new Stack();
}

void push(Stack *stack, char number)
{
	StackElement *stackElement = new StackElement();
	stackElement->value = number;
	stackElement->next = stack->head;
	stack->head = stackElement;
}

char pop(Stack *stack)
{
	if (stack->head == nullptr)
	{
		return '!';
	}
	StackElement *temp = stack->head;
	char value = temp->value;
	stack->head = temp->next;
	delete temp;
	return value;
}

void deleteStack(Stack *stack)
{
	while (stack->head != nullptr)
	{
		StackElement *temp = stack->head;
		stack->head = stack->head->next;
		delete temp;
	}
	delete stack;
	cout << "Stack deleted" << endl;
}

bool empty(Stack *stack)
{
	return stack->head == nullptr;
}