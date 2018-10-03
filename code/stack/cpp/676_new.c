#include "tsqueue.h"

TwoStackQueue::TwoStackQueue() {}
TwoStackQueue::TwoStackQueue(const TwoStackQueue& q): push_stack(q.push_stack), pop_stack(q.pop_stack) {}
TwoStackQueue::TwoStackQueue(const Stack& s): push_stack(s) {}
TwoStackQueue::TwoStackQueue(const Stack& s1, const Stack& s2): push_stack(s1), pop_stack(s2) {}

TwoStackQueue& TwoStackQueue::operator=(const TwoStackQueue& q)
{
    if (this != &q)
    {
        push_stack = q.push_stack;
        pop_stack = q.pop_stack;
    }

    return *this;
}

void TwoStackQueue::refill_pop_stack()
{
    while (!push_stack.empty())
    {
        pop_stack.push(push_stack.top());
        push_stack.pop();
    }
}

bool TwoStackQueue::empty() const
{
    return push_stack.empty() && pop_stack.empty();
}

int TwoStackQueue::front()
{
    if (empty())
        return DEFAULT;
    if (pop_stack.empty())
        refill_pop_stack();
    return pop_stack.top();
}

void TwoStackQueue::push(int data)
{
    push_stack.push(data);
}

bool TwoStackQueue::pop()
{
    if (empty())
        return false;
    if (pop_stack.empty())
        refill_pop_stack();
    return pop_stack.pop();
}
