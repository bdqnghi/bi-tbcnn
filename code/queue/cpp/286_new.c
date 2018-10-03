#include "Queue.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
  Queue* queue = new Queue();
 
  cout << queue->size() << endl;
  cout << queue->isEmpty() << endl;
  //cout << queue->peek() << endl;

  queue->enqueue(5);
  queue->enqueue(10);
  queue->enqueue(15);
  queue->enqueue(20);
  queue->enqueue(25);

  cout << queue->peek() << endl;
  cout << queue->size() << endl;
  cout << queue->isEmpty() << endl;

  cout << queue->dequeue() << endl;
  cout << queue->dequeue() << endl;
  cout << queue->dequeue() << endl;
  cout << queue->dequeue() << endl;
  cout << queue->dequeue() << endl;
  cout << queue->dequeue() << endl;

  delete queue;

  return 0;
}
