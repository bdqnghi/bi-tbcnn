
#include<iostream>
#include<string.h>

using namespace std;

struct Stack{
    int top1;
    int top2;
    unsigned capacity;
    int* array;
};

struct Stack* createStack(unsigned Capacity){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack*));
    stack->top1 = -1;
    stack->capacity = Capacity;
    stack->top2 = stack->capacity;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
    }

void push1(struct Stack* stack,int item){
    stack->array[++stack->top1] = item;
    }

int pop1(struct Stack* stack){
    return stack->array[stack->top1--];
    }

int top1(struct Stack* stack){
    return stack->array[stack->top1];
    }

void push2(struct Stack* stack,int item){
    stack->array[--stack->top2] = item;
    }

int pop2(struct Stack* stack){
    return stack->array[stack->top2++];
    }

int top2(struct Stack* stack){
    return stack->array[stack->top2];
    }

int main(){

    struct Stack* stack = createStack(5);
    push2(stack,10);
    push2(stack,15);
    push1(stack,11);
    push2(stack,7);
    cout << "Popped element from stack1 is " << pop1(stack);
    push2(stack,40);
    cout << "\nPopped element from stack2 is " << pop2(stack);

    }
