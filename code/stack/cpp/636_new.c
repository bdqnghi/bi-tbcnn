#include <iostream>
#include "stack.h"

using namespace std;

struct StackElement
{
	char value;
	StackElement *next;
};

struct Stack
{
	StackElement *head;
};

Stack *create()
{
	Stack *stack = new Stack;
	stack->head = nullptr;
	return stack;
}

void addElement(Stack *stack, char value)
{
	StackElement *element = new StackElement;
	element->value = value;
	element->next = stack->head;
	stack->head = element;
}

void deleteElement(Stack *stack)
{
	StackElement *element = stack->head;
	stack->head = stack->head->next;
	delete element;
}

char returnHeadValue(Stack *stack)
{
	return stack->head->value;
}

bool isEmpty(Stack *stack)
{
	return (stack->head == nullptr);
}

void deleteStack(Stack *stack)
{
	while (stack->head != nullptr)
		deleteElement(stack);
	delete stack;
}




