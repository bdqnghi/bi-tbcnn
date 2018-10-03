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
	while (stack->head != NULL)
	{
		StackElement *tmp = stack->head->next;
		delete stack->head;
		stack->head = tmp;
	}
}

bool isEmpty(Stack *stack)
{
	return stack->head == NULL;
}

void push(Stack *stack, char value)
{
	StackElement *temp = new StackElement;
	temp->value = value;
	temp->next = stack->head;
	stack->head = temp; 
}

char top(Stack *stack)
{
	return stack->head->value;
}

char pop(Stack *stack)
{
	char result = top(stack);
	StackElement *tmp = stack->head;
	stack->head = stack->head->next;
	delete tmp;
	return result;
}