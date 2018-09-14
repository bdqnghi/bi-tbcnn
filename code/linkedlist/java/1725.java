package BootcampProblems.Lecture7;

import java.util.Scanner;

public class linkedlist {

	public static Node<Integer> takeinput(){
		 
		Scanner s = new Scanner(System.in);
		System.out.println("Enter data");
		
		Node<Integer> head = null,tail=null;
		int data = s.nextInt();
		while(data != -1){
			Node<Integer> newNode = new Node<Integer>(data);
			if(head == null){
				head = newNode;
				tail = newNode;
			}
			else{
				tail.next = newNode;
				tail = newNode;
			}
			System.out.println("Enter data");
			data =  s.nextInt();
		}
	
		return head;
		
	}
	
	public static void print(Node<Integer> head) {
		Node<Integer> temp = head;
		while(temp != null)
		{
			System.out.print(temp.data + "->");
			temp = temp.next;
		}
	}
	
	public static void printelement(Node<Integer> head, int pos)
	{
		Node<Integer> temp =head;
		int counter = 1;
		while(temp !=null && counter != pos)
		{
			temp = temp.next;
			counter++;
		}
		System.out.println("data at pos "+ temp.data);
	}
	
	
	
	public static Node<Integer> insertatpos(Node<Integer> head, int data,int pos)
	{
		Node<Integer> newNode = new Node<Integer>(data);
		if(pos == 1)
		{
			newNode.next = head;
			head = newNode;
			return head;
		}
		else
		{
			Node<Integer> temp =head;
			int counter = 2;
			while(temp.next !=null && counter != pos)
			{
//				System.out.println("hey");
				temp = temp.next;
				counter++;
			}
			if(temp.next == null)
			{
				temp.next = newNode;
			}
			else
			{
				newNode.next = temp.next;
				temp.next = newNode;
			}		
		}
		return head;
	}
	
	
	public static int length(Node<Integer> head)
	{
		if(head.next == null)
			return 1;
		return 1 + length(head.next);
	}
	
	public static Node<Integer> delete(Node<Integer> head, int pos)
	{
		Node<Integer> temp = head;
		if(pos == 1)
		{
			head = temp.next;
			temp.next = null;
			return head;
		}
		else
		{
			int counter = 2;
			Node<Integer> prev = temp;
			temp = temp.next;
			while(temp.next !=null && counter != pos)
			{
				temp = temp.next;
				prev = prev.next;
				counter++;
			}
			if(temp.next == null)
			{
				prev.next = null;
			}
			else
			{
				prev.next = temp.next;
				temp.next = null;
			}		
		}
		return head;
	}
	
//	1 2 3 4 5 6
	
	
	public static Node<Integer> insertrecursion(Node<Integer> head ,int data, int i)
	{
		if(i == 1)
		{		
			Node<Integer> newNode = new Node<Integer>(data);
			newNode.next = head;
			return newNode;
		}		
		
		Node<Integer> newhead =  insertrecursion(head.next,data, i-1);
		head.next = newhead;
		return head;
	}
	
	public static Node<Integer> deleterecursion(Node<Integer> head , int i)
	{
		if(i == 1)
		{		
			Node<Integer> temp = head;
			head = temp.next;
			temp.next = null;
			return head;
		}		
		head.next = deleterecursion(head.next, i-1);
		return head;
	}
//	5 4 2 1

	public static void Swap(Node<Integer> temp1 , Node<Integer> temp2)
	{
		Node<Integer> temp =  temp1.next;
		temp1.next = temp2.next;
		temp2.next = temp;
		
	}
	
	
	public static Node<Integer> bubblesort(Node<Integer> head)
	{
		if(head == null || head.next == null)
			return head;
		int len = length(head);
		
		for(int i = 0 ; i < len ; i++)
		{
			Node<Integer> currNode = head;
			Node<Integer> prev = null;
			while(currNode.next != null)
			{
				if(currNode.data > currNode.next.data)
				{
					if(prev == null)
					{
						Node<Integer> next = currNode.next;
						currNode.next = next.next;
						next.next = currNode;
						prev = next;
						head = next;
					}

					else{
						Node<Integer> next = currNode.next;
						currNode.next = next.next;
						next.next = currNode;
						prev.next =  next;
						prev = prev.next;
					}
					
				}
				else
				{
					prev = currNode;
					currNode = currNode.next;
				}
			}
		}
		return head;
	}
	
	
	
	
	
	
	public static void main(String[] args) {
		
		Node<Integer> head = takeinput();
		print(head);
	
		// insert at i th pos
//		Scanner s = new Scanner(System.in);
//		System.out.println("Enter ith pos");
//		int i = s.nextInt();
//		
//		printelement(head, i);
//		head = insertatpos(head,25,i);
//		print(head);
		
		// length of link list
		
//		System.out.println();
//		System.out.println("length " +length(head));
		
		//delete the element at ith
		
//		head = delete(head, i);
//		print(head);

		
		// Insertion using recursion
//		head = insertrecursion(head,25, i);
//		print(head);
		
		
		//delete using recursion
//		head = deleterecursion(head, i);
//		print(head);
		
		
		head = bubblesort(head);
		System.out.println("after sort");
		print(head);
		
	}

	
}
