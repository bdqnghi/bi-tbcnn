
package test;

public class BFS {

	private final List[] v;
	private boolean[] mark;
	private int[] path;
	private int source;
	
	private class Queue {
		private List head;
		private List tail;
		
		public void enqueue(int t) {
			if(head == null) {
				head = tail = new List(t);
				return;
			}
			
			tail.next = new List(t);
			tail = tail.next;
		}
		
		public List dequeue() {
			if(head == null)
				return null;
				
			if(tail == head)
				tail = null;
			List t = head;
			head = head.next;
			return t;
		}
		
		public boolean isEmpty() {
			return head == null;
		}
				
	}
	
	private class List {
		public int v;
		public List next;
		
		public List(int v) {
			this.v = v;
		}
		
		public void add(int v) {
			List t = this;
			if(t.v == v) {
				System.out.println(v + " already connected ");
				return;
			}
			while(t.next != null) {
				if(t.v == v) {
					System.out.print("already connected");
					return;
				}
				t = t.next;
			}
			t.next = new List(v);
		}
	}
	
	public BFS(int num, int source) {
		this.v = new List[num];
		this.mark = new boolean[num];
		this.path = new int[num];
		this.source = source;
	}
	
	public void union(int p, int q) {
		if(v[p] == null)
			v[p] = new List(q);
		else
			v[p].add(q);
		if(v[q] == null)
			v[q] = new List(p);
		else
			v[q].add(p);
	}
	
	private void bfs(int s) {
		Queue q = new Queue();
		mark[s] = true;
		q.enqueue(s);
		while(!q.isEmpty()) {
			int t = q.dequeue().v;
			for(List i = v[t]; i != null; i = i.next) {
				if(mark[i.v] != true) {
					path[i.v] = t;
					mark[i.v] = true;
					q.enqueue(i.v);
				}
			}
		}
	}
	
	public void build() {
		bfs(source);
	}
	
	public boolean connected(int p) {
		return mark[p];
	}
	
	public void printPath(int p) {
		if(!connected(p)) {
			System.out.println("not connected");
			return;
		}
		
		System.out.print(p + " ");
		for(int t = p; t != source; t = path[t])
			System.out.print(path[t] + " ");
	}
	
	public static void main(String[] args) {
		int N = Integer.parseInt(args[0]);
		BFS z = new BFS(N, 0);
		for(int t = 1; t < N * 2; t += 2)
			z.union(Integer.parseInt(args[t]), Integer.parseInt(args[t+1]));
		z.build();
		z.printPath(5);
	}
}
