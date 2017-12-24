package edu.bridgeport.mohammad;

public class Queue<T> {
  private Node<T> front;
  private Node<T> rear;

  public boolean enqueue(T item){
    Node<T> node = new Node<T>(item);

    if(front == null) {
      front = rear = node;
    } else {
      rear.setNext(node);
      rear = node;
    }

    return true;
  }

  public T look() {
	  if(front != null) {
		  return front.getData();
	  } else {
		  return null;
	  }
  }

  public T dequeue() {
    if(front == null) return null;
    Node<T> current = front;
    this.front = current.getNext();
    return current.getData();
  }

  public boolean empty() {
	  return front == null;
  }

  public String toString() {
	if(empty()) { return "Queue: [empty]"; }
	  
    StringBuilder output = new StringBuilder();
    output.append("Queue: ");

    Node<T> current = front;
    while(current != null) {
      output.append(current.getData() + ", ");
      current = current.getNext();
    }
    
    output.delete(output.length() - 2, output.length());    
    return output.toString();
  }
}
