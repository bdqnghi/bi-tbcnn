/**
 * 思想是不断地剔掉叶节点，最终应该只剩下一个节点
 */
public class Solution {
    public boolean isValidSerialization(String preorder) {
        Stack<String> stack = new Stack<>();
        String[] arr = preorder.split(",");
        for (int i = 0; i < arr.length; i++) {
            stack.push(arr[i]);
            while (stack.size() >= 3 && 
                   stack.get(stack.size() - 1).equals("#") && 
                   stack.get(stack.size() - 2).equals("#") && 
                   !stack.get(stack.size() - 3).equals("#")) {
                stack.pop();
                stack.pop();
                stack.pop();
                stack.push("#");
            }
        }
        if (stack.size() == 1 && stack.get(0).equals("#")) {
            return true;
        }
        return false;
    }
}