/*
 * Problem 3_6: sort a stack into ascending order using additional stack
 * Solution: iteratively compare the elements in two stacks
 * Author: Stanley Lee
 * Date: 2013/3/5
 */

#include <iostream>
#include <stack>
using namespace std;
 
template<typename T>
void printStack(stack<T> myStack){
  while(!myStack.empty()){
    cout<<myStack.top()<<" ";
    myStack.pop();
  }
  cout<<endl;
}

template<typename T>
void sortStack(stack<T>& myStack){
  stack<T> tempStack;
  T tempValue;
  while(!myStack.empty()){
    tempValue = myStack.top();
    myStack.pop();
    if(tempStack.empty() || tempValue<=tempStack.top())
      tempStack.push(tempValue);
    else{
      while(!tempStack.empty()&&tempValue>tempStack.top()){
        myStack.push(tempStack.top());
	tempStack.pop();
      }
      tempStack.push(tempValue);
    }
  }
  while(!tempStack.empty()){
    myStack.push(tempStack.top());
    tempStack.pop();
  }
}

int main(){
  stack<float> myStack;
  myStack.push(1.2);
  myStack.push(0.3);
  myStack.push(5.8);
  myStack.push(4.3);
  myStack.push(2.4);
  printStack(myStack);
  sortStack(myStack);
  printStack(myStack);
  return 0;
}
