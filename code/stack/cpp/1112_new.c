#include "stack.h"
#include <iostream>
using namespace std;

Stack *createStack()
{
	Stack *stack = new Stack;
	stack->head = NULL;
	return stack;
}

void destroy(Stack *stack)
{
	StackElement *tmp = stack->head;
	while (stack->head->next != NULL)
	{
		stack->head = stack->head->next;
		delete tmp;
	}
	delete stack->head;
}

bool isEmpty(Stack *stack)
{
	return stack->head == NULL;
}

void push(Stack *stack, int value)
{
	StackElement *temp = new StackElement;
	temp->value = value;
	temp->next = stack->head;
	stack->head = temp; 
}

int top(Stack *stack)
{
	return stack->head->value;
}

int pop(Stack *stack)
{
	int result = top(stack);
	StackElement *tmp = stack->head;
	stack->head = stack->head->next;
	delete tmp;
	return result;
}