package tracy.algorithm.stack;

import java.util.Stack;

/**
 * User: tracy
 * Date: 14-9-23下午11:50
 */
public class ReverseStack {

    public static <T> void reverse(Stack<T> stack){
        if(!stack.isEmpty()){
            T top = stack.pop();
            reverse(stack);
            addToBottom(stack,top);
        }
    }

    private static <T> void addToBottom(Stack<T> stack,T t){
        if(stack.isEmpty()){
            stack.push(t);
        }else{
            T top = stack.pop();
            addToBottom(stack, t);
            stack.push(top);
        }
    }
}
