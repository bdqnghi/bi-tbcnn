#include "Stack.h"

using namespace Stacks;

bool Stacks::isEmpty(Stack *stack) {
    return !(stack->size);
}

Stack* Stacks::create(){
    StackElement *firstElem = new StackElement {nullptr, 0};
    return new Stack{firstElem, 0};
}

void Stacks::push(Stack *stack, char value)
{
    StackElement *newElement = new StackElement{stack->head, value};
    stack->head = newElement;
    stack->size++;
}
char Stacks::pop(Stack *stack)
{
    if (isEmpty(stack))
        return -1;
    char result = stack->head->value;
    StackElement* newElem = stack->head;
    stack->head = newElem->next;
    delete newElem;
    stack->size--;
    return result;
}
char Stacks::front(Stack *stack){
    return stack->head->value;
}

void Stacks::deleteStack(Stack *stack){
    while (!isEmpty(stack))
        pop(stack);
    delete stack->head;
    delete stack;//((
}
