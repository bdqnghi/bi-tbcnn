#include "stack.h"
#include <limits.h>
#include <iostream>

using namespace std;

class MinStack : public Stack {
 public:
  MinStack(int size);
  ~MinStack();
  Stack * minStack;
  void push(StackElementT element);
  StackElementT pop();
  StackElementT min();
};

MinStack::MinStack(int size) : Stack(size) {
  minStack = new Stack(size);
}

MinStack::~MinStack() {
  delete minStack;
}

StackElementT MinStack::min() {
  if (!isEmpty()) {
    return minStack->top();
  }
  else {
    return INT_MAX;
  }
}


void MinStack::push(StackElementT element) {
  if (element < min()) {
    minStack->push(element);
  }
  Stack::push(element);
}

StackElementT MinStack::pop() {
  if (!isEmpty()) {
    StackElementT element = Stack::pop();
    if (element == minStack->top()) {
      minStack->pop();
    }
  }
}

int main() {
  MinStack *stack = new MinStack(10);
  stack->push(5);
  cout<<stack->min()<<endl;
  stack->push(4);
  cout<<stack->min()<<endl;
  stack->push(9);
  cout<<stack->min()<<endl;
  stack->pop();
  cout<<stack->min()<<endl;
  stack->pop();
  cout<<stack->min()<<endl;
  delete stack;
}
