#include "gtest/gtest.h"
#include "../src/LLQueue/Queue.h"

TEST(QueueTest, enqueue) {
  Queue* q = new Queue();
  q->enqueue(7);

  EXPECT_EQ(7, q->dequeue());
  delete q;
}

TEST(QueueTest, dequeue) {
  Queue* q = new Queue();
  q->enqueue(5);
  q->enqueue(10);
  q->enqueue(15);
  
  EXPECT_EQ(5, q->dequeue()); 
  delete q;
}

TEST(QueueTest, size) {
  Queue* q = new Queue();
  q->enqueue(10);
  q->enqueue(5); 
  q->enqueue(5);
  q->enqueue(5);
  q->enqueue(5);
  q->enqueue(5);
  q->enqueue(5);
  q->enqueue(5);
  q->enqueue(5);
  q->enqueue(5);
  q->enqueue(5);
  EXPECT_EQ(11, q->queueSize());
  delete q;
  
}

TEST(QueueTest, isEmpty) {
  Queue* q = new Queue();
  q->enqueue(1);
  q->dequeue();

  EXPECT_EQ(true, q->isEmpty());
  delete q;
}
