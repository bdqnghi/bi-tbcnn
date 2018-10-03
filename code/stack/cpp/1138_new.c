#include <stdio.h>

typedef char ElementType;

struct StackElement
{
	ElementType value;
	StackElement * next;
};

struct Stack
{
	StackElement * head;
	int count;
};

Stack * createStack()
{
	Stack * result = new Stack;
	result->head = NULL;
	result->count = 0;
	return result;
}

ElementType pop(Stack * stack)
{
	
	ElementType result;
	if (stack->head == NULL)
		return 0;
	else
	{
		result = stack->head->value;
		StackElement * temp = stack->head;
		stack->head = stack->head->next;
		stack->count--;
		delete temp;
		return result;
	}
}

void push(Stack * stack, ElementType value)
{
	StackElement * first = new StackElement;
	first->value = value;
	first->next = stack->head;
	stack->head = first;
	stack->count++;
}

void deleteStack(Stack * stack)
{
	StackElement * temp = stack->head;
	while (temp != NULL)
	{
		stack->head = stack->head->next;
		delete temp;
		temp = stack->head;
	}
	delete stack;
}

StackElement * headS(Stack * stack)
{
	return stack->head;
}

ElementType valueS(Stack * stack, StackElement * element)
{
	return element->value;
}

int count(Stack * stack)
{
	return stack->count;
}