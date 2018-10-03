#include <iostream>
#include <cassert>

#include "stack.h"

int main() {
    lock_free::stack<int> stack;
    assert(stack.unsafe_empty());

    stack.push(3);
    stack.push(2);
    stack.push(1);
    stack.push(0);

    assert(!stack.unsafe_empty());

    int val;
    while (stack.try_pop(val)) {
        std::cout << "val: " << val << std::endl;
    }

    assert(stack.unsafe_empty());

    stack.push(3);
    stack.push(2);
    stack.push(1);

    assert(!stack.unsafe_empty());

    stack.unsafe_clear();

    assert(stack.unsafe_empty());

    return 0;
}
