#include "stack.h"

void push(Stack *&stack, char value)
{
	// ���� ������� ������ ���������, ��������� ������ �������
	if (stack == NULL)
	{
		stack = new Stack;
		stack->value = value;
		stack->next = NULL;
		return;
	}
	Stack *newHead = new Stack;
	newHead->value = value;
	newHead->next = stack;
	stack = newHead;
}
char pop(Stack *&stack)
{
	char sign = stack->value;
	Stack *temp = stack->next;
	delete stack;
	stack = temp;
	return sign;
}
char getValue(Stack *stack)
{
	if (stack == NULL)
	{
		return '\0';
	}
	return stack->value;
}
void cleanStack(Stack *&stack)
{
	while (stack != NULL)
	{
		Stack *tmp = stack;
		stack = stack->next;
		delete tmp;
	}
}
bool isEmpty(Stack *stack)
{
	return (stack == NULL);
}