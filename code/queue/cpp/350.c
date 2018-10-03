#include "Queue.h"

Queue::Queue() {
  theQueue = new int[10];
  size = 0;
  capacity = 10;
  front = 0;
  back = 0;
}

Queue::~Queue(){
  delete[] theQueue;
}

void Queue::resize(){
  if(size == capacity) {
    int* newQueue = new int[capacity*2];
    for(int i=0; i<size; ++i){
      newQueue[i] = theQueue[front];
      front = (front+1)%capacity;
    }
    delete theQueue;
    theQueue=newQueue;
    front = 0;
    back = size;
    capacity = capacity*2;
  }
  if(size<(capacity/4) && capacity > 10) {
    int* newQueue = new int[capacity/2];
    for(int i=0; i<size; ++i){
      newQueue[i] = theQueue[front];
      front = (front+1)%capacity;
    }
    delete theQueue;
    theQueue=newQueue;
    front = 0;
    back = size;
    capacity = capacity/2;
  }
}
void Queue::enqueue(int value) {
  if(size==capacity){resize();}
  theQueue[back] = value;
  back = (back+1)%capacity;
  size++;
}
int Queue::dequeue() {
  int temp = theQueue[front];
  front = (front+1)%capacity;
  size--;
  return temp;
}
int Queue::queueSize(){
  return size;
}
bool Queue::isEmpty(){
  if(size==0){
    return true;
  }
  return false;
}
