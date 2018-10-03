#include "gtest/gtest.h"
#include "data_structures/queue.h"

TEST(QUEUE, Basic)
{
    Queue queue = Queue();
    EXPECT_TRUE(queue.empty());

    queue.enqueue(5);

    EXPECT_FALSE(queue.empty());

    queue.enqueue(10);
    queue.enqueue(12);
    queue.enqueue(13);

    EXPECT_EQ(5, queue.dequeue());
    EXPECT_EQ(10, queue.dequeue());
    EXPECT_EQ(12, queue.dequeue());
    EXPECT_EQ(13, queue.dequeue());
    EXPECT_TRUE(queue.empty());

    queue.enqueue(10);
    queue.enqueue(12);
    queue.enqueue(13);

    queue.clear();
    EXPECT_TRUE(queue.empty());

    queue.enqueue(10);
    queue.enqueue(12);
    queue.enqueue(13);
}