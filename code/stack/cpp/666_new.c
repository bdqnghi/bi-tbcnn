#include "gtest/gtest.h"
#include "max_stack.h"

TEST(MaxStackTestCase, Normal)
{
    MaxStack stack;
    EXPECT_EQ(0, stack.max());

    stack.push(1);
    EXPECT_EQ(1, stack.max());

    stack.push(5);
    EXPECT_EQ(5, stack.max());

    stack.push(3);
    EXPECT_EQ(5, stack.max());

    stack.push(8);
    EXPECT_EQ(8, stack.max());

    stack.push(2);
    EXPECT_EQ(8, stack.max());

    stack.pop();
    EXPECT_EQ(8, stack.max());

    stack.pop();
    EXPECT_EQ(5, stack.max());

    stack.push(1);
    EXPECT_EQ(5, stack.max());

    stack.push(12);
    EXPECT_EQ(12, stack.max());

    stack.pop();
    EXPECT_EQ(5, stack.max());
}
