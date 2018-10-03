public class Main {
    public static <T> Stack<T> createStack(T... values) {
        return createStack(values, 0, new EmptyStack<T>());
    }

    public static <T> Stack<T> createStack(T[] values, int current, Stack<T> stack) {
        if (current == values.length)
            return stack;
        Stack<T> newStack = stack.push(values[current]);
        current += 1;
        return createStack(values, current, newStack);
    }
    private static <T> void printStack(Stack<T> stack) {
        if (stack.isEmpty()) 
            return;
        else {
            System.out.println(stack.top());
            printStack(stack.pop());
        }
    }
    public static void main(String[] args) {
        printStack(createStack(0, 1, 2, 3, 4, 5));
    }
}
