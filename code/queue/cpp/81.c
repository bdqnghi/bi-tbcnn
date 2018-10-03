#include "Queue.h"

Node::Node(){
}
void Node::setNext(Node* n) {
  next = n;
}
void Node::setValue(int v){
  value = v;
}
int Node::getValue(){
  return value;
}
Node* Node::getNext(){
  return next;
}
Queue::Queue(){
  front = new Node();
  back = new Node();
  size = 0;
}
Queue::~Queue(){
  for(int i=0; i<size; ++i) {
    dequeue();
  }
  delete front;
}
void Queue::enqueue(int value) {
  Node* newNode = new Node();
  newNode->setValue(value);
  if(size==0){
    front->setNext(newNode);
  }
  back->setNext(newNode);
  newNode->setNext(back);
  size++;
}
int Queue::dequeue() {
  Node* temp = new Node();
  temp = front->getNext();
  int result = temp->getValue();
  front = temp->getNext();
  delete temp;
  size--;
  return result;
}
bool Queue::isEmpty(){
  if(size == 0){
    return true;
  }
  return false;
}
int Queue::queueSize() {
  return size;
}
