#include<iostream>
using namespace std;
class Stack{
  int stackSize;
  int* buffer;
  int* stackTop;
public:
  Stack(int); 
  void push(int, int);
  int pop(int);
};
Stack::Stack(int size){
  stackSize=size;
  buffer=new int[3*stackSize];
  stackTop= new int[3];
  for(int i=0;i<3;i++){ 
    stackTop[i]=-1;
  }
}

void Stack::push(int num, int stack){
  int index=stack*stackSize+stackTop[stack]+1;
  stackTop[stack]++;
  buffer[index]=num;
}
int Stack::pop(int stackNum){
  if(stackTop[stackNum]==-1){
    cout<<"empty stack"; 
   return -1;
  }
  int val=  buffer[stackNum*stackSize + stackTop[stackNum]];
  stackTop[stackNum--];
  return val;
}
int main(){
  Stack s(10);
  for(int i=0;i<3;i++){
    s.push(i,i);
  }
  for(int i=0;i<3;i++){
    cout<<s.pop(i);
  }
}
