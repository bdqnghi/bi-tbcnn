import java.util.*;

class Student implements Comparable<Student>{
	String name;
	int age;
	public Student(String s,int a){
		name = s;
		age = a;
	}
	@Override
	public int compareTo(Student s){
		if(this.age < s.age){
			return 1; // do swap
		}else if(this.age > s.age){
			return -1; // dont swap
		}else{
			return this.name.compareTo(s.name); // return which is alphabetical ordered
		}
		
	}
}


class Queue_Priority_Queue {
	public static void main(String[] args) {
		Queue<Integer> q = new LinkedList<Integer>();
		System.out.println("Queue");
		q.add(11);
		q.add(15);
		q.add(12);
		q.add(1);
		q.add(10);
		System.out.println(q.poll()); // 11
		System.out.println("Priority Queue");
		
		PriorityQueue<Student> pq = new PriorityQueue<Student>();/// Object should impelemented by comparable 
//		pq.add(11);
//		pq.add(15);
//		pq.add(12);
//		pq.add(1);
//		pq.add(10);
//		
//		System.out.println(pq.poll()); // 1

		pq.add(new Student("uanek",22));
		pq.add(new Student("abid",12));
		pq.add(new Student("zahid",18));
		pq.add(new Student("belal",5));
		pq.add(new Student("tarek",22));
		
		System.out.println(pq.poll().name);
		
		
	}
}


