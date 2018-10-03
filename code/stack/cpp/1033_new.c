#include <iostream>
#include <stack>

using namespace std;

template <typename T>
stack<T> sort_stack(stack<T> inputStack)
{
    stack<T> outputStack;

    while (!inputStack.empty())
    {
        T tmp = inputStack.top();
        inputStack.pop();

        while (!outputStack.empty() && outputStack.top() > tmp)
        {
            inputStack.push(outputStack.top());
            outputStack.pop();
        }

        outputStack.push(tmp);
    }

    return outputStack;
}

int main(void)
{
    stack<int> inputStack;
    inputStack.push(4);
    inputStack.push(5);
    inputStack.push(2);
    inputStack.push(1);
    inputStack.push(3);

    stack<int> sortedStack = sort_stack(inputStack);

    // Display the stack
    while (!sortedStack.empty())
    {
        int tmp = sortedStack.top();
        sortedStack.pop();
        cout << tmp << endl;
    }

    return 0;
}
