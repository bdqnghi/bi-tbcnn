package linkedlistuse;

public class Linkedlist{
    private class Node{
          Node(Object o){
                this.o=o;
          }
           Object o;
           Node next;
    }
    private Node first;
    
    public void add(Object elem){
        Node node=new Node(elem);
        if(first ==null){
                first=node;
        }
        else{
            append(node);
        }
    }
    
    private void append(Node node){
        Node last=first;
        while(last.next!=null){
            last=last.next;
        }
        last.next=node;
    }
    public Object get(int index){
        return findElemOf(index);
    }
    private Object findElemOf(int index){
        int count=0;
        Node last=first;
        while(count<index){
            last=last.next;
            count++;
        }
        return last.o;
    }
    
}