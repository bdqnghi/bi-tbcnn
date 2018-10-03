#include "stack.h"
#include <stdio.h>

struct StackElement
{
	StackElement *prev;
	char value;
};

struct Stack
{
	StackElement *top;
	int count;
};

void push(StackElementType value, Stack *stack)
{
	StackElement *element = new StackElement;
	element->value = value;
	element->prev = stack->top;
	stack->top = element;
	stack->count++;
}

void pop(Stack *stack)
{
	StackElement *memory = stack->top;
	stack->top = stack->top->prev;
	delete memory;
	stack->count--;
}

Stack *createStack()
{
	Stack *newStack = new Stack;
	push('\0', newStack);
	newStack->count = 0;
	return newStack;
}

StackElementType stackTop(Stack *stack)
{
	return stack->top->value;
	
}

StackElement *createStackElement()
{
	StackElement *element = new StackElement;
	element->prev = NULL;
	return element;
}

void deleteStack(Stack *stack)
{
	while (stack->count > 0)
	{
		pop(stack);
		stack->count--;
	}
	delete stack;
}