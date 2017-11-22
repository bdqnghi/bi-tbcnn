public class linkedlist {
  public Node head;
  public Node tail;

  public linkedlist(){
    head = new Node();
    tail = head;
  }

  public void addToTail(Object val){
  // implement the add to tail function 

  }


  public Object removeHead(){
  // implement the removeHead function 

  }

  public boolean contains(Object val){
  // implement the contains function

  }

  private static class Node {
    // Object variables
    Node next;
    Node prev;
    Object data;

    // NODE CONSTRUCTORS
    public Node(){
      next = null;
      data = null;
    }

    public Node(Object newData)
    {
      next = null;
      data = newData;
    }
    public Node(Object newData, Node nextNode)
    {
      next = nextNode;
      data = newData;
    }


// TEST YOUR CODE BELOW

  public static void main(String[] args){
    linkedlist mylist = new linkedlist();
    mylist.addToTail("Europe");
    mylist.addToTail("South America");
    mylist.addToTail("Asia");
    mylist.addTail("Africa");
    System.out.println(mylist);
    System.out.println(mylist.contains("Asia"));
    mylist.removeHead();
    System.out.println(mylist.contains("Europe"));
    System.out.println(mylist);

  }

}