package infiniteStack;

/**
 * @author Stanislav Chetvertkov
 *         Date: 27.06.12
 *         Time: 18:37
 */
public class Main {
    public static void main(String[] args){
        StackNode stackNode1 = new StackNode("1");
        StackNode stackNode2 = new StackNode("2");
        StackNode stackNode3 = new StackNode("3");
        StackNode stackNode4 = new StackNode("4");

        InfiniteStack infiniteStack = new InfiniteStack();
        infiniteStack.push(stackNode1);
        infiniteStack.push(stackNode2);
        infiniteStack.push(stackNode3);
        infiniteStack.push(stackNode4);

        infiniteStack.pop();
        infiniteStack.pop();
    }
}
