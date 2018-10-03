#include <iostream>
#include "stdafx.h"
#include "Stack.h"

size_t Stack::Size()
{
	return size;
}
//Chack in zero
//Takes a pointer to class Stack
//return 1 or 0 
inline int Stack::empty(Stack* stack)
{
	if (stack == NULL)
		return 1;
	return 0;
}
//clear stack
//Takes a pointer to class Stack
//return void
inline void Stack::ClearS(Stack* stack)
{
	stack->P = NULL;
	stack->last = NULL;
	stack->nom = 0;
}
//Write the stack to another pointer
//Takes a pointer to class Stack and a pointer to object
//return pointer to the new top stack
Stack* Stack::Push(Stack* stack, const type_n& push)
{
	Stack* new_stack;
	try
	{
		new_stack = new Stack();
	}
	catch(std::bad_alloc &e)
	{
		std::cout << "Unselected memry";
		delete new_stack;
		new_stack = NULL;
		return NULL;
	}
	new_stack->last = stack;
	new_stack->P = push;
	new_stack->nom = new_stack->size;
	stack = new_stack;
	new_stack = NULL;
	stack->size++;
	return stack;
}
//Extract the stack to another pointer
//Takes a pointer to class Stack and a pointer to object
//return pointer to a new height minus one stack
Stack* Stack::Pop(Stack* stack, type_n& pop)
{
	if (empty(stack))
	{
		std::cout << "Yuo can\'t delete an item as the stacj is empty";
		return NULL;
	}
	Stack* del_stack;
	del_stack = stack;
	pop = stack->P;
	stack = stack->last;
	ClearS(del_stack);
	delete del_stack;
	del_stack = NULL;
	stack->size--;
	return stack;
}
//Read item
//Takes a pointer to class Stack and item namber
//return a pointer to object
type_n Stack::ReadS(Stack* stack, size_t s)
{
	if (s > size)
	{
		std::cout<< "can�t read " << s << " element" << std::endl;
		return NULL;
	}
	for (int i = (int)size-(int)1 ; i > -1; i--)
	{
		if (s == stack->nom)
		{
			return stack->P;
		}
		stack = stack->last;
	}
}
//Clear all Stack
//Takes a pointer to class Stack
//return NULL
Stack* Stack::Clear(Stack * stack)
{
	if (empty(stack))
		return NULL;//���� ���� ��� ������ �������
	Stack* del_stack;
	while(1)
	{
		if (stack->last != NULL)//��������� �� �� ��������� ���� ����
		{
			del_stack=stack;//������ ������ ����� ��� ������� ��������
			stack=stack->last;//����� ��������� ��������� �� ��������� �������
			ClearS(del_stack);
			delete del_stack;
			del_stack = NULL;
		}
		else 
		{
			ClearS(stack);
			stack->size = 0;
			delete stack;
			return NULL;
		}
	}
}
