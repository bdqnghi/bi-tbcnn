#include "gtest/gtest.h"
#include "max_queue.h"


TEST(MaxQueueTestCase, Normal)
{
    MaxQueue queue;
    EXPECT_EQ(0, queue.max());

    queue.push(1);
    EXPECT_EQ(1, queue.max());

    queue.push(5);
    EXPECT_EQ(5, queue.max());

    queue.push(3);
    EXPECT_EQ(5, queue.max());

    queue.push(8);
    EXPECT_EQ(8, queue.max());

    queue.push(2);
    EXPECT_EQ(8, queue.max());

    queue.push(10);
    EXPECT_EQ(10, queue.max());

    queue.push(7);
    EXPECT_EQ(10, queue.max());

    queue.pop();
    EXPECT_EQ(10, queue.max());
    queue.pop();
    EXPECT_EQ(10, queue.max());
    queue.pop();
    EXPECT_EQ(10, queue.max());
    queue.pop();
    EXPECT_EQ(10, queue.max());
    queue.pop();
    EXPECT_EQ(10, queue.max());
    queue.pop();
    EXPECT_EQ(7, queue.max());
    queue.pop();
    EXPECT_EQ(0, queue.max());
}    
