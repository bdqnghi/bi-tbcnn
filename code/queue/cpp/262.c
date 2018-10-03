#include "Queue.h"
#include <list>
#include <assert.h>

Queue::Queue() {
  q = new std::list<int>;
}

Queue::~Queue(){
  delete q; 
}

void Queue::enqueue(int value) {
  q->list::push_back(value);
}

int Queue::dequeue() {
  assert(!q->empty());
  int temp;
  temp = q->list::front();
  q->list::pop_front();
  return temp;
}

int Queue::queueSize() {
  return q->list::size();
}

bool Queue::isEmpty() {
  return q->list::empty();
}
