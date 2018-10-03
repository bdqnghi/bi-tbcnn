


class ListNode
{
    Object element;
    ListNode next = null;
}

class Queue
{
    private ListNode front = null, back = null;

    public void Put(Object element)
    { 
	if (IsEmpty()) back = front = new ListNode();
	else back = back.next = new ListNode();
	back.element = element;
    }

    public Object Get() throws Exception
    { 
	if (IsEmpty()) throw new Exception();
	Object element = front.element;
	front = front.next;
	return element;
    }

    public boolean IsEmpty()
    { return front == null; }

    public void Empty()
    { front = back = null; }
}
