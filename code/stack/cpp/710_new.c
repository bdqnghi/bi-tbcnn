#include "stack.h"

struct stackElement
{
    int val;
    stackElement *next;
};

struct Stack
{
    stackElement *head;
};


Stack *createStack()
{
    Stack *result = new Stack;
    result->head = nullptr;
    return result;
}

void push(Stack *stack, int val )
{
    stackElement *newStackelement = new stackElement;
    newStackelement->val = val;
    newStackelement->next = stack->head;
    stack->head = newStackelement;
}

int pop(Stack *stack)
{
    stackElement *temp = stack->head;
    stack->head = stack->head->next;
    int val=temp->val;
    delete temp;
    return val;
}

void deleteStack(Stack *stack)
{
    while (stack->head != nullptr)
        pop(stack);
    delete stack;
}


int emptyStack(Stack *stack)
{
    if (stack->head == nullptr)
        return 1;
    return 0;
}
