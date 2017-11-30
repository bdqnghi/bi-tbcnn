import java.util.*;
//Here goes node class
//it contains next node and data in it
class Node{
    private Node next;
    private int data;
    public Node(int data){
        this.data = data;
        this.next = null;
    }
    public int getData(){
        return this.data;

    }
    public void setData(int data){
        this.data = data;
    }
    public Node getNext(){
        return this.next;
    }
    public void setNext(Node next){
        this.next = next;
    }
}
// main list class
// here all function goes
class list {
    private Node head;
    
    public list(){
        this.head = null;
    }
    public list(int data){
        head = new Node(data);
    }
    public void traverse(){
        Node temp = head;
        if(head == null)
            System.out.println("list is empty");
        else{
            while(temp != null){
                System.out.println(temp.getData());
                temp = temp.getNext();
            }
        }
    }
    public boolean isEmpty(){
        return ((head==null)?true:false);
    }
    public void addFirst(int data){
        if(isEmpty())
            head = new Node(data);
        else{
            Node temp = new Node(data);
            temp.setNext(head);
            head = temp;
        }
    }
    public void addAfter(int data , int newData){
        if(isEmpty())
            System.out.println("Empty list , no data matching");
        else{
            Node temp = head;
            while(temp != null ){
                if(temp.getData() == data){
                    Node temp2 = new Node(newData);
                    temp2.setNext(temp.getNext());
                    temp.setNext(temp2);
                    //System.out.println("setting node");
                    break;
                }
                temp = temp.getNext();
            }
            System.out.println((temp == null ) ? "No data found" : "Data inserted");
        }
    }
    public void addAtPosition(int index , int data){
        if(isEmpty())
            head = new Node(data);
        else{
            Node temp = head;
            for(int i=0;i<index;i++)
                temp = temp.getNext();
            Node T2 = new Node(data);
            t2.setNext(temp.getNext());
            temp.setNext(T2);
        }
    }
}
public class linkedlist{
    public static void main(String args[]){
        list l = new list(4);
        //l.traverse();
        l.addFirst(5);
        l.addFirst(6);
        //l.traverse();
        l.addAfter(8,12);
        //l.traverse();
        l.addAfter(5,13);
        l.addAfter(4,8);
    }
}

