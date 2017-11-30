class LinkedList{
	int data;
	LinkedList next;

	public LinkedList(int data, LinkedList next){
		this.data = data;
		this.next = next;
	}

	static boolean isEmpty(LinkedList l){
		return l == null;
	}

	public static void main(String [] args){
		LinkedList l0 = null;
		LinkedList l1 = new LinkedList(1, null);
		LinkedList l2 = new LinkedList(2, l1);
	}
}