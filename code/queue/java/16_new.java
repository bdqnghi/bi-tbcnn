package GenericArrayQueue;

/**
 * Created by stirredo on 1/20/14.
 */
public class QueueApp {
    public static void main(String[] args) {
        Queue<Integer> queue = new Queue<Integer>(6);
        queue.insert(10);
        queue.insert(20);
        queue.insert(30);
        queue.insert(40);
        queue.insert(50);
        queue.delete();
        queue.delete();
        queue.insert(60);
        queue.insert(100);
        while(!queue.isEmpty()) {
            System.out.println(queue.delete());
        }

    }
}
