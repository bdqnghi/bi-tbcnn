extern "C"
{
#include "Stack.h"
}

#include "CppUTest/TestHarness.h"

TEST_GROUP(Stack)
{
    Stack* stack;

    void setup()
    {
      stack = Stack_Create();
    }

    void teardown()
    {
       Stack_Destroy(stack);
    }
};
TEST(Stack, Create)
{
	FAIL("Start Here")
}

// TEST(Stack, shouldBeEmpty)
// {
// 	CHECK(Stack_isEmpty(stack))
// }
// 
// TEST(Stack, shouldNotBeEmptyAfterPush)
// {
// 	Stack_push(stack, 1);
// 	CHECK(!Stack_isEmpty(stack));
// }
// 
// TEST(Stack, shouldBeEmptyAfterAPushPop)
// {
// 	Stack_push(stack, 1);
// 	Stack_pop(stack);
// 	CHECK(Stack_isEmpty(stack));
// }
// 
// TEST(Stack, shouldPushPopMultiple)
// {
// 	Stack_push(stack, 1);
// 	Stack_push(stack, 1);
// 	Stack_pop(stack);
// 	CHECK(!Stack_isEmpty(stack));
// }
// 
// TEST(Stack, shouldPopValues)
// {
// 	Stack_push(stack, 21);
// 	LONGS_EQUAL(21, Stack_top(stack))
// }
// 
// TEST(Stack, shouldPopMultipleValues)
// {
// 	Stack_push(stack, 21);
// 	Stack_push(stack, 28);
// 	Stack_push(stack, 12);	
// 	LONGS_EQUAL(12, Stack_top(stack));
// 	Stack_pop(stack);
// 	LONGS_EQUAL(28, Stack_top(stack));
// 	Stack_pop(stack);
// 	LONGS_EQUAL(21, Stack_top(stack));
// 	Stack_pop(stack);	
// }
//
// What's next? ...
