#include "massivestack.h"

struct Stack
{
    int i;
    int val[10] = {0};
};

Stack *createStack()
{
    Stack *result = new Stack;
    result->i = -1;
    return result;
}

void push(Stack *stack, int val )
{
    stack->i++;
    stack->val[stack->i] = val;
}

int pop(Stack *stack)
{
    int val=stack->val[stack->i];
    stack->val[stack->i] = 0;
    stack->i--;
    return val;
}

void deleteStack(Stack *stack)
{
    delete stack;
}


int emptyStack(Stack *stack)
{
    if (stack->i == -1)
        return 1;
    return 0;
}

