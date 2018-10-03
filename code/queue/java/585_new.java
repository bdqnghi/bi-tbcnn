class Exercise7 {
    public static void main(String[] args) {
        Queue<String> queue = new Queue<String>();
        queue.enq("first");
        queue.enq("second");
        queue.enq("third");
        queue.deq();
        queue.deq();
        queue.enq("forth");
        queue.enq("fifth");
        queue.enq("sixth");
        queue.deq();
        queue.enq("seventh");
        queue.enq("eigth");

        while(!queue.isEmpty()) {
            System.out.println(queue.deq());
        }

    }
}
