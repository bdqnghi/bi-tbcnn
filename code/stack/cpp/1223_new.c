#include "stacks2.h"
#include <stdlib.h>
#include <limits.h>
#include <iostream>
using namespace std;
Stack* createStack()
{
	Stack* stack = new Stack ;
	stack->head = NULL ;
	return stack ;
}
bool isEmpty(Stack* stack)
{
	return (stack->head == NULL) ;
}

char top(Stack* stack)
{
	if (!isEmpty(stack))
		return stack->head->value ;
	else
		return 'z';
}

void push(Stack* stack,char c)
{
		StackElement* temp = new StackElement ;
		temp->value = c ;
		temp->next = stack->head ;
		stack->head = temp ;
}

char pop(Stack* stack)
{
	if (isEmpty(stack))
	{
		return 'z';
	}
	else
	{
		char result = top(stack);
		StackElement *tmp = stack->head;
		stack->head = stack->head->next;
		delete tmp;
		return result;
	}
}
 
void printStack(Stack* stack)
{
	if (!isEmpty(stack))
	{
		printf("%c ",stack->head->value) ;
		StackElement* tmp = stack->head ;
		while (tmp->next != NULL)
		{
			tmp = tmp->next ;
			printf("%c",tmp->value);

		}
	}
	else
		printf("An empty stack ") ;
}


void destroy(Stack* stack)
{
	StackElement* tmp = stack->head ;
	if (stack->head != NULL)
	{
		while (tmp->next != NULL)
		{
		StackElement* tmp2 = tmp ;
		tmp = tmp->next ;
		delete tmp2;
		}
		delete tmp ;
		delete stack ;
	}
	else
		delete stack ;
}