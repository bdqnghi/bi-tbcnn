#include "stack.h"
#include <iostream>

using namespace std;

struct ListElement
{
	ElementTypeStack value;
	ListElement *next;
};

struct Stack
{
    ListElement *head;
};

Stack *createStack()
{
	Stack *stack = new Stack;
	stack->head = nullptr;
	return stack;
}
 
void push(Stack* &stack, ElementTypeStack value)
{
	ListElement *temp = new ListElement;     
	temp->value = value;  
	temp->next = stack->head;      
	stack->head = temp; 	              
}

ElementTypeStack pop(Stack* &stack)
{  
	ElementTypeStack thisValue = stack->head->value;    
	ListElement *temp = stack->head;      
	stack->head = stack->head->next;     
    delete temp;              
    return thisValue;           
}

bool empty(Stack* &stack)
{
	if (stack->head == nullptr)
	{
		return true;
	}
}

void clearStack(Stack* &stack)
{
	while (stack->head != nullptr)
	{
		pop(stack);
	}
	delete stack;
}