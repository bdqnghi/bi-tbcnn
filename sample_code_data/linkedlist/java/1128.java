import java.io.*;
import java.util.*;
//import commLib.*;
/*
 * 链表操作在LeetCode中占有一定的比例，不过面试中出现的频率并不是特别高，不过基本的操作还是要熟练的。这道题目还可以求于另一个数据结构数组中，也比较简单
 */
public class linkedlist {
	
	 //Definition for singly-linked list.
	 class ListNode {
	      int val;
	      ListNode next;
	      ListNode(int x) {
	          val = x;
	          next = null;
	      }
	  }
	 
	public static void main(String[] args){
		;
	}
	
	 public class queue {
		 void enqueue(int x){
			 ListNode node=new ListNode(x);
			 if(last==null) {
				 last = node;
				 return;
			 }
			 else{
				 last.next=node;
				 last=node;
			 }
		 }
		 int dequeue(){
			 if(first==null){
				 return -1;
			 }
			 else{
				 int val=first.val;
				 first=first.next;
				 return val;
			 }
		 }
		 
	 }
	 
	 
	 
	 public static ListNode kth(ListNode node,int[] count,int k){
		 if(node==null){
			 count[0]=0;
			 return null;
		 }
		 //if(node.next==null) count[0]=1;
		 ListNode res = kth(node.next,count,k);
		 count[0] += 1;
		 if(count[0]==k) {
			 return node;
		 }
		 return res;
	 }
	 
	 
	 public ListNode rem(ListNode head){
		 ListNode cur=head;
		 ListNode runner =cur;
		 while(cur.next!=null){
			 runner=cur;
			 while(runner.next!=null){
				 if(runner.val==cur.val){}
			 }
		 }
		 return head;
	 }

	 
	 
	 /*
	  * 这道题目比较简单，经典的链表基本操作。维护两个指针对应两个链表，因为一般会以一条链表为基准
	  * ，比如说l1, 那么如果l1当期那的元素比较小，那么直接移动l1即可，否则将l2当前的元素插入到l1当前元素的前面。
	  * 算法时间复杂度是O(m+n),m和n分别是两条链表的长度，空间复杂度是O(1)，代码如下：
*/
public ListNode mergeTwoLists(ListNode l1, ListNode l2) {  
    ListNode helper = new ListNode(0);  
    ListNode pre = helper;  
    helper.next = l1;  
    while(l1!=null && l2 != null)  
    {  
        if(l1.val>l2.val)  
        {  
            ListNode next = l2.next;  
            l2.next = pre.next;  
            pre.next = l2;  
            l2 = next;  
        }  
        else  
        {  
            l1 = l1.next;  
        }  
        pre = pre.next;  
  
    }  
    if(l2!=null)  
    {  
        pre.next = l2;  
    }  
    return helper.next;  
} 
/*
这个题类似的有Merge Sorted Array，只是后者是对数组进行合并操作，面试中可能会一起问到。扩展题目Merge k Sorted Lists, 
这是一个在分布式系统中比较有用的基本操作，还是需要重视，面试中可以发散出很多问题。
	  */

/*
 * 这是一道数组操作的题目，思路比较明确，就是维护三个index，分别对应数组A，数组B，和结果数组。然后A和B同时从后往前扫，每次迭代中A和B指向的元素大的便加入结果数组中，然后index-1，另一个不动。代码如下： 
*/
public void mergeSortedArray(int A[], int m, int B[], int n) {  
    if(A==null || B==null)  
        return;  
    int idx1 = m-1;  
    int idx2 = n-1;  
    int len = m+n-1;  
    while(idx1>=0 && idx2>=0)  
    {  
        if(A[idx1]>B[idx2])  
        {  
            A[len--] = A[idx1--];  
        }  
        else  
        {  
            A[len--] = B[idx2--];  
        }  
    }  
    while(idx2>=0)  
    {  
        A[len--] = B[idx2--];  
    }          
} 
/* 
这里从后往前扫是因为这个题目中结果仍然放在A中，如果从前扫会有覆盖掉未检查的元素的可能性。算法的时间复杂度是O(m+n),m和n分别是两个数组的长度，空间复杂度是O(1)。这个题类似的有Merge Two Sorted Lists，只是后者是对于LinkedList操作，面试中可能会一起问到。
 */


/*
 * 这道题目在分布式系统中非常常见，来自不同client的sorted list要在central server上面merge起来。这个题目一般有两种做法，下面一一介绍并且分析复杂度。 第一种做法比较容易想到，就是有点类似于MergeSort的思路,就是分治法，不了解MergeSort的朋友，请参见归并排序-维基百科，是一个比较经典的O(nlogn)的排序算法，还是比较重要的。思路是先分成两个子任务，然后递归求子任务，最后回溯回来。这个题目也是这样，先把k个list分成两半，然后继续划分，知道剩下两个list就合并起来，合并时会用到Merge Two Sorted Lists这道题，不熟悉的朋友可以复习一下。代码如下： 

*/
public ListNode mergeKLists(ArrayList<ListNode> lists) {  
    if(lists==null || lists.size()==0)  
        return null;  
    return helper(lists,0,lists.size()-1);  
}  
private ListNode helper(ArrayList<ListNode> lists, int l, int r)  
{  
    if(l<r)  
    {  
        int m = (l+r)/2;  
        return merge(helper(lists,l,m),helper(lists,m+1,r));  
    }  
    return lists.get(l);  
}  
private ListNode merge(ListNode l1, ListNode l2)  
{   
    ListNode dummy = new ListNode(0);  
    dummy.next = l1;  
    ListNode cur = dummy;  
    while(l1!=null && l2!=null)  
    {  
        if(l1.val<l2.val)  
        {  
            l1 = l1.next;  
        }  
        else  
        {  
            ListNode next = l2.next;  
            cur.next = l2;  
            l2.next = l1;  
            l2 = next;  
        }  
        cur = cur.next;  
    }  
    if(l2!=null)  
        cur.next = l2;  
    return dummy.next;  
}  
/*
我们来分析一下上述算法的时间复杂度。假设总共有k个list，每个list的最大长度是n，那么运行时间满足递推式T(k) = 2T(k/2)+O(n*k)。根据主定理，可以算出算法的总复杂度是O(nklogk)。如果不了解主定理的朋友，可以参见主定理-维基百科。空间复杂度的话是递归栈的大小O(logk)。
接下来我们来看第二种方法。这种方法用到了堆的数据结构，思路比较难想到，但是其实原理比较简单。维护一个大小为k的堆，每次取堆顶的最小元素放到结果中，然后读取该元素的下一个元素放入堆中，重新维护好。因为每个链表是有序的，每次又是去当前k个元素中最小的，所以当所有链表都读完时结束，这个时候所有元素按从小到大放在结果链表中。这个算法每个元素要读取一次，即是k*n次，然后每次读取元素要把新元素插入堆中要logk的复杂度，所以总时间复杂度是O(nklogk)。空间复杂度是堆的大小，即为O(k)。代码如下：
*/
public ListNode mergeKLists2(ArrayList<ListNode> lists) {  
    PriorityQueue<ListNode> heap = new PriorityQueue<ListNode>(10,new Comparator<ListNode>(){  
            @Override  
            public int compare(ListNode n1, ListNode n2)  
            {  
                return n1.val-n2.val;  
            }  
        });  
    for(int i=0;i<lists.size();i++)  
    {  
        ListNode node = lists.get(i);   
        if(node!=null)  
        {  
            heap.offer(node);  
        }  
    }  
    ListNode head = null;  
    ListNode pre = head;  
    while(heap.size()>0)  
    {  
        ListNode cur = heap.poll();  
        if(head == null)  
        {  
            head = cur;  
            pre = head;  
        }  
        else  
        {  
            pre.next = cur;  
        }  
        pre = cur;  
        if(cur.next!=null)  
            heap.offer(cur.next);  
    }  
    return head;  
}  
//可以看出两种方法有着同样的时间复杂度，都是可以接受的解法，但是却代表了两种不同的思路，数据结构也不用。个人觉得两种方法都掌握会比较好哈，因为在实际中比较有应用，所以也是比较常考的题目。	 
	 
	 
	 /*
	  * Swap Nodes in Pairs Total Accepted: 35570 Total Submissions: 109363 My Submissions Question Solution 
Given a linked list, swap every two adjacent nodes and return its head.
For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.
Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
	  */
	 //这道题属于链表操作的题目，思路比较清晰，就是每次跳两个节点，后一个接到前面，前一个接到后一个的后面，最后现在的后一个（也就是原来的前一个）接到下下个结点（如果没有则接到下一个）。代码如下： 
	// [java] view plaincopy在CODE上查看代码片派生到我的代码片
	 public ListNode swapPairs(ListNode head) {  
	     if(head == null)  
	         return null;  
	     ListNode helper = new ListNode(0);  
	     helper.next = head;  
	     ListNode pre = helper;  
	     ListNode cur = head;  
	     while(cur!=null && cur.next!=null)  
	     {  
	         ListNode next = cur.next.next;  
	         cur.next.next = cur;  
	         pre.next = cur.next;  
	         if(next!=null && next.next!=null)  
	             cur.next = next.next;  
	         else  
	             cur.next = next;  
	         pre = cur;  
	         cur = next;  
	     }  
	     return helper.next;  
	 }  
	 //这道题中用了一个辅助指针作为表头，这是链表中比较常用的小技巧，因为这样可以避免处理head的边界情况，一般来说要求的结果表头会有变化的会经常用这个技巧，大家以后会经常遇到。
	 //因为这是一遍过的算法，时间复杂度明显是O(n)，空间复杂度是O(1)。实现中注意细节就可以了，不过我发现现在面试中链表操作的题目出现并不多，所以个人觉得大家练一下就好了，不用花太多时间哈。
	 
	 
	 
	 /*
	  * Insertion Sort List Total Accepted: 33512 Total Submissions: 129872 My Submissions Question Solution 
Sort a linked list using insertion sort.
	  */
	// 这道题跟Sort List类似，要求在链表上实现一种排序算法，这道题是指定实现插入排序。插入排序是一种O(n^2)复杂度的算法，基本想法相信大家都比较了解，就是每次循环找到一个元素在当前排好的结果中相对应的位置，然后插进去，经过n次迭代之后就得到排好序的结果了。了解了思路之后就是链表的基本操作了，搜索并进行相应的插入。时间复杂度是排序算法的O(n^2)，空间复杂度是O(1)。代码如下： 
	 //[java] view plaincopy在CODE上查看代码片派生到我的代码片
	 public ListNode insertionSortList(ListNode head) {  
	     if(head == null)  
	         return null;  
	     ListNode helper = new ListNode(0);  
	     ListNode pre = helper;  
	     ListNode cur = head;  
	     while(cur!=null)  
	     {  
	         ListNode next = cur.next;  
	         pre = helper;  
	         while(pre.next!=null && pre.next.val<=cur.val)  
	         {  
	             pre = pre.next;  
	         }  
	         cur.next = pre.next;  
	         pre.next = cur;  
	         cur = next;  
	     }  
	     return helper.next;  
	 }  
	 //这道题其实主要考察链表的基本操作，用到的小技巧也就是在Swap Nodes in Pairs中提到的用一个辅助指针来做表头避免处理改变head的时候的边界情况。作为基础大家还是得练习一下哈。
	 
	 
	 /*
	  * Sort List Total Accepted: 33512 Total Submissions: 158169 My Submissions Question Solution 
Sort a linked list in O(n log n) time using constant space complexity.
	  */
	/* 这道题跟Insertion Sort List类似，要求我们用O(nlogn)算法对链表进行排序，但是并没有要求用哪一种排序算法，我们可以使用归并排序，快速排序，堆排序等满足要求的方法来实现。对于这道题比较容易想到的是归并排序，因为我们已经做过Merge Two Sorted Lists，这是归并排序的一个subroutine。剩下我们需要做的就是每次找到中点，然后对于左右进行递归，最后用Merge Two Sorted Lists把他们合并起来。代码如下：
	 [java] view plaincopy在CODE上查看代码片派生到我的代码片
	 */
	 public ListNode sortList(ListNode head) {  
	     return mergeSort(head);  
	 }  
	 private ListNode mergeSort(ListNode head)  
	 {  
	     if(head == null || head.next == null)  
	         return head;  
	     ListNode walker = head;  
	     ListNode runner = head;  
	     while(runner.next!=null && runner.next.next!=null)  
	     {  
	         walker = walker.next;  
	         runner = runner.next.next;  
	     }  
	     ListNode head2 = walker.next;  
	     walker.next = null;  
	     ListNode head1 = head;  
	     head1 = mergeSort(head1);  
	     head2 = mergeSort(head2);  
	     return merge(head1, head2);  
	 }  
	 private ListNode merge(ListNode head1, ListNode head2)  
	 {  
	     ListNode helper = new ListNode(0);  
	     helper.next = head1;  
	     ListNode pre = helper;  
	     while(head1!=null && head2!=null)  
	     {  
	         if(head1.val<head2.val)  
	         {  
	             head1 = head1.next;  
	         }  
	         else  
	         {  
	             ListNode next = head2.next;  
	             head2.next = pre.next;  
	             pre.next = head2;  
	             head2 = next;  
	         }  
	         pre = pre.next;  
	     }  
	     if(head2!=null)  
	     {  
	         pre.next = head2;  
	     }  
	     return helper.next;  
	 }  
	 /*
	 不过用归并排序有个问题就是这里如果把栈空间算上的话还是需要O(logn)的空间的。对于其他排序算法，用兴趣的同学可以实现一下哈。
	 排序是面试中比较基础的一个主题，所以对于各种常见的排序算法大家还是要熟悉，不了解的朋友可以参见排序算法 - Wiki。
	 特别是算法的原理，很多题目虽然没有直接考察排序的实现，但是用到了其中的思想，
	 比如非常经典的topK问题，就用到了快速排序的原理，关于这个问题在Median of Two Sorted Arrays中有提到，有兴趣的朋友可以看看。	 
	 */
	 
	/*You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
	 * 
	这道题比较简单，是cc150里面的题，思路很明确，就是按照位数读下去，维护当前位和进位，时间复杂度是O(n),空间复杂度是O(1).代码如下：
	*/
	public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
	    int carry = 0;
	    int digit = 0;
	    ListNode head = null;
	    ListNode pre = null;
	    while(l1!=null && l2!=null)
	    {
	        digit = (l1.val+l2.val+carry)%10;
	        carry = (l1.val+l2.val+carry)/10;
	        ListNode newNode = new ListNode(digit);
	        if(head==null)
	            head = newNode;
	        else
	            pre.next = newNode;
	        pre = newNode;
	        l1 = l1.next;
	        l2 = l2.next;
	    }
	    while(l1!=null)
	    {
	        digit = (l1.val+carry)%10;
	        carry = (l1.val+carry)/10;
	        ListNode newNode = new ListNode(digit);
	        if(head==null)
	            head = newNode;
	        else
	            pre.next = newNode;
	        pre = newNode;
	        l1 = l1.next;            
	    }
	    while(l2!=null)
	    {
	        digit = (l2.val+carry)%10;
	        carry = (l2.val+carry)/10;
	        ListNode newNode = new ListNode(digit);
	        if(head==null)
	            head = newNode;
	        else
	            pre.next = newNode;
	        pre = newNode;
	        l2 = l2.next;            
	    }        
	    if(carry>0)
	    {
	        ListNode newNode = new ListNode(carry);
	        pre.next = newNode;
	    }
	    return head;
	} 
	/*实现中注意维护进位，陷阱的话记住最后还要判一下有没有进位，如果有再生成一位。 
	这道题还是有一些扩展的，比如这个其实是BigInteger的相加，数据结果不一定要用链表，也可以是数组，面试中可能两种都会问而且实现。
	然后接下来可以考一些OO设计的东西，比如说如果这是一个类应该怎么实现，也就是把数组或者链表作为成为成员变量，再把这些操作作为成员函数，
	进一步的问题可能是如何设计constructor，这个问题除了基本的还得对内置类型比如int, long的constructor, 
	类似于BigInteger(int num), BigInteger(int long). 总体来说问题还是比较简单，但是这种问题不能出错，所以还是要谨慎对待。
	*/
	
	/*
	Linked List Cycle Total Accepted: 46466 Total Submissions: 128358 My Submissions Question Solution 
	Given a linked list, determine if it has a cycle in it.

	Follow up:
	Can you solve it without using extra space?
	这道题是cc150里面的题目，算是链表里面比较经典的题目。
	我们先讲一下比较直接容易想到的方法，就是用一个hashset，然后把扫过的结点放入hashset中，如果出现重复则返回true。
	想法比较简单，也很好实现，这里就不放代码了，有兴趣的朋友可以写写。
	下面我们来考虑如何不用额外空间来判断是否有cycle，用到的方法很典型，就是那种walker-runner的方法，基本想法就是维护两个指针，
	一个走的快，一个走得慢，当一个走到链表尾或者两个相见的时候，能得到某个想要的结点，比如相遇点，中点等等。
	介绍完方法，剩下的主要就是数学了，假设两个指针walker和runner，walker一倍速移动，runner两倍速移动。
	有一个链表，假设他在cycle开始前有a个结点，cycle长度是c，而我们相遇的点在cycle开始后b个结点。
	那么想要两个指针相遇，意味着要满足以下条件：(1) a+b+mc=s; (2) a+b+nc=2s; 其中s是指针走过的步数，m和n是两个常数。
	这里面还有一个隐含的条件，就是s必须大于等于a，否则还没走到cycle里面，两个指针不可能相遇。假设k是最小的整数使得a<=kc，也就是说(3) a<=kc<=a+c。
	接下来我们取m=0, n=k，用(2)-(1)可以得到s=kc以及a+b=kc。由此我们可以知道，只要取b=kc-a(由(3)可以知道b不会超过c)，那么(1)和(2)便可以同时满足，
	使得两个指针相遇在离cycle起始点b的结点上。
	因为s=kc<=a+c=n，其中n是链表的长度，所以走过的步数小于等于n，时间复杂度是O(n)。并且不需要额外空间，空间复杂度O(1)。代码如下：
	*/
	public boolean hasCycle(ListNode head) {
	    if(head == null)
	        return false;
	    ListNode walker = head;
	    ListNode runner = head;
	    while(runner!=null && runner.next!=null)
	    {
	        walker = walker.next;
	        runner = runner.next.next;
	        if(walker == runner)
	            return true;
	    }
	    return false;
	} //这道题是链表中比较有意思的题目，基于这个方法，我们不仅可以判断链表中有没有cycle，还可以确定cycle的位置，有兴趣的朋友可以看看Linked List Cycle II。

	/*
	 * 这道题是Linked List Cycle的扩展，就是在确定是否有cycle之后还要返回cycle的起始点的位置。
	 * 从Linked List Cycle中用的方法我们可以得知a=kc-b（不了解的朋友可以先看看Linked List Cycle）。
	 * 现在假设有两个结点，一个从链表头出发，一个从b点出发，经过a步之后，第一个结点会到达cycle的出发点，而第二个结点会走过kc-b，
	 * 加上原来的b刚好也会停在cycle的起始点。
	 * 如此我们就可以设立两个指针，以相同速度前进知道相遇，而相遇点就是cycle的起始点。
	 * 算法的时间复杂度是O(n+a)=O(2n)=O(n)，先走一次确定cycle的存在性并且走到b点，然后走a步找到cycle的起始点。空间复杂度仍是O(1)。代码如下：
*/
public ListNode detectCycle(ListNode head)
{
    if(head == null || head.next == null)
        return null;
    ListNode walker = head.next;
    ListNode runner = head.next.next;
    while(runner!=null && walker!=runner)
    {
        walker = walker.next;
        if(runner.next!=null)
            runner = runner.next.next;
        else
            runner = null;
    }
    if(runner == null)
        return null;
    runner = head;
    while(walker!=runner)
    {
        walker = walker.next;
        runner = runner.next;
    }
    return walker;
}
/*
 * Intersection of Two Linked Lists Total Accepted: 14044 Total Submissions: 51251 My Submissions Question Solution 
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.	
 */


	
	/*Partition List Total Accepted: 28439 Total Submissions: 104295 My Submissions Question Solution 
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
	 * 这是一道链表操作的题目，要求把小于x的元素按顺序放到链表前面。我们仍然是使用链表最常用的双指针大法，一个指向当前小于x的最后一个元素，一个进行往前扫描。如果元素大于x，那么继续前进，否则，要把元素移到前面，并更新第一个指针。这里有一个小细节，就是如果不需要移动（也就是已经是接在小于x的最后元素的后面了），那么只需要继续前进即可。算法时间复杂度是O(n)，空间只需要几个辅助变量，是O(1)。代码如下：
	 */
	public ListNode partition(ListNode head, int x) {
	    if(head == null)
	        return null;
	    ListNode helper = new ListNode(0);
	    helper.next = head;
	    ListNode walker = helper;
	    ListNode runner = helper;
	    while(runner.next!=null)
	    {
	        if(runner.next.val<x)
	        {
	            if(walker!=runner)
	            {
	                ListNode next = runner.next.next;
	                runner.next.next = walker.next;
	                walker.next = runner.next;
	                runner.next = next;
	            }
	            else
	                runner = runner.next;
	            walker = walker.next;
	        }
	        else
	        {
	            runner = runner.next;
	        }
	    }
	    return helper.next;
	}
			
		
	
	/*
	 * Given a sorted linked list, delete all duplicates such that each element appear only once.
For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
	 这是一道比较简单的链表操作的题目，要求是删去有序链表中重复的元素。
	 方法比较清晰，维护两个指针，一个指向当前不重复的最后一个元素，一个进行依次扫描，遇到不重复的则更新第一个指针，
	 继续扫描，否则就把前面指针指向当前元素的下一个（即把当前元素从链表中删除）。时间上只需要一次扫描，所以是O(n)，空间上两个额外指针，是O(1)。
	 */
	//by code ganker
	public ListNode deleteDuplicates(ListNode head) {  
	    if(head == null)  
	        return head;  
	    ListNode pre = head;  
	    ListNode cur = head.next;  
	    while(cur!=null)  
	    {  
	        if(cur.val == pre.val)  
	            pre.next = cur.next;  
	        else      
	            pre = cur;  
	        cur = cur.next;  
	    }  
	    return head;  
	}  
	//链表操作在LeetCode中占有一定的比例，不过面试中出现的频率并不是特别高，不过基本的操作还是要熟练的。这道题目还可以求于另一个数据结构数组中，也比较简单，有兴趣可以看看Remove Duplicates from Sorted Array。

/*Remove Duplicates from Sorted List II Total Accepted: 31359 Total Submissions: 125870 My Submissions Question Solution 
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
 * 这道题跟Remove Duplicates from Sorted List比较类似，只是这里要把出现重复的元素全部删除。其实道理还是一样，
 * 只是现在要把前驱指针指向上一个不重复的元素中，如果找到不重复元素，则把前驱指针知道该元素，否则删除此元素。
 * 算法只需要一遍扫描，时间复杂度是O(n)，空间只需要几个辅助指针，是O(1)。代码如下：
 * */ 
public ListNode deleteDuplicatesII(ListNode head) {  
    if(head == null)  
        return head;  
    ListNode helper = new ListNode(0);  
    helper.next = head;  
    ListNode pre = helper;  
    ListNode cur = head;  
    while(cur!=null)  
    {  
        while(cur.next!=null && pre.next.val==cur.next.val)  
        {  
            cur = cur.next;  
        }  
        if(pre.next==cur)  
        {  
            pre = pre.next;  
        }  
        else  
        {  
            pre.next = cur.next;  
        }  
        cur = cur.next;  
    }  
      
    return helper.next;  
}  
//可以看到，上述代码中我们创建了一个辅助的头指针，是为了修改链表头的方便。前面介绍过，一般会改到链表头的题目就会需要一个辅助指针，是比较常见的技巧。

 /*
  * Reorder List Total Accepted: 31753 Total Submissions: 153067 My Submissions Question Solution 
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
You must do this in-place without altering the nodes' values.
For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
  */
/*
这是一道比较综合的链表操作的题目，要按照题目要求给链表重新连接成要求的结果。其实理清思路也比较简单，分三步完成：（1）将链表切成两半，也就是找到中点，然后截成两条链表；（2）将后面一条链表进行reverse操作，就是反转过来；（3）将两条链表按顺序依次merge起来。
这几个操作都是我们曾经接触过的操作了，第一步找中点就是用Linked List Cycle中的walker-runner方法，一个两倍速跑，一个一倍速跑，知道快的碰到链表尾部，慢的就正好停在中点了。第二步是比较常见的reverse操作，在Reverse Nodes in k-Group也有用到了，一般就是一个个的翻转过来即可。第三步是一个merge操作，做法类似于Sort List中的merge，只是这里不需要比较元素打小了，只要按顺序左边取一个，右边取一个就可以了。
接下来看看时间复杂度，第一步扫描链表一遍，是O(n)，第二步对半条链表做一次反转，也是O(n)，第三部对两条半链表进行合并，也是一遍O(n)。所以总的时间复杂度还是O(n)，由于过程中没有用到额外空间，所以空间复杂度O(1)。代码如下：
*/
public void reorderList(ListNode head) {
    if(head == null || head.next==null)
    {
        return;
    }
    ListNode walker = head;
    ListNode runner = head;
    while(runner.next!=null && runner.next.next!=null)
    {
        walker = walker.next;
        runner = runner.next.next;
    }
    ListNode head1 = head;
    ListNode head2 = walker.next;
    walker.next = null;
    head2 = reverse(head2);
    while(head1!=null && head2!=null)
    {
        ListNode next = head2.next;
        head2.next = head1.next;
        head1.next = head2;
        head1 = head2.next;
        head2 = next;
    }
}
private ListNode reverse(ListNode head)
{
    ListNode pre = null;
    ListNode cur = head;
    while(cur!=null)
    {
        ListNode next = cur.next;
        cur.next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
} 
/*这道题看起来比较复杂，其实理清思路之后就都是链表常见的几个基本操作。这里我想多说一下reverse操作，因为这是链表最常见的操作。
有时候在第一轮电面这种比较基础的面试中，可能会要求实现reverse操作，但是因为有点过于简单，面试官会要求递归和非递归都实现一下。
上面的代码使用非递归的方式实现reverse。下面我们列举一下递归的代码，有兴趣的朋友可以看看哈。
*/
public ListNode recursive_reverse(ListNode head) {
    if(head == null || head.next==null)
        return head;
    return recursive_reverse(head, head.next);
}
private ListNode recursive_reverse(ListNode current, ListNode next) 
{
    if (next == null) return current;
    ListNode newHead = recursive_reverse(current.next, next.next);
    next.next = current;
    current.next = null;
    return newHead;
}
/*
Reverse Linked List II Total Accepted: 30086 Total Submissions: 114785 My Submissions Question Solution 
Reverse a linked list from position m to n. Do it in-place and in one-pass.
For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,
return 1->4->3->2->5->NULL.
Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
*/
//这道题是比较常见的链表反转操作，不过不是反转整个链表，而是从m到n的一部分。分为两个步骤，第一步是找到m结点所在位置，第二步就是进行反转直到n结点。反转的方法就是每读到一个结点，把它插入到m结点前面位置，然后m结点接到读到结点的下一个。总共只需要一次扫描，所以时间是O(n)，只需要几个辅助指针，空间是O(1)。代码如下： 
public ListNode reverseBetween(ListNode head, int m, int n) {  
    if(head == null)  
        return null;  
    ListNode dummy = new ListNode(0);  
    dummy.next = head;  
    ListNode preNode = dummy;  
    int i=1;  
    while(preNode.next!=null && i<m)  
    {  
        preNode = preNode.next;  
        i++;  
    }  
    if(i<m)  
        return head;  
    ListNode mNode = preNode.next;  
    ListNode cur = mNode.next;  
    while(cur!=null && i<n)  
    {  
        ListNode next = cur.next;  
        cur.next = preNode.next;  
        preNode.next = cur;  
        mNode.next = next;  
        cur = next;  
        i++;  
    }  
    return dummy.next;  
}  
//上面的代码还是有些细节的，链表的题目就是这样，想起来道理很简单，实现中可能会出些小差错，还是熟能生巧哈。


/*
Rotate List Total Accepted: 27268 Total Submissions: 124650 My Submissions Question Solution 
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/
//这是一道链表操作的题目，基本思路是用walker-runner定位到要旋转的那个结点，然后将下一个结点设为新表头，并且把当前结点设为表尾。需要注意的点就是旋转的结点数可能超过链表长度，所以我们要对这个进行取余。定位旋转的尾结点的不超过链表的长度，所以时间复杂度是O(n)，空间复杂度是O(1)。代码如下： 
public ListNode rotateRight(ListNode head, int n) {  
    if(head == null)  
    {  
        return null;  
    }  
    ListNode walker = head;  
    ListNode runner = head;  
    int idx = 0;  
    while(runner!=null && idx<n)  
    {  
        runner = runner.next;  
        idx++;  
    }  
    if(runner == null)  
    {  
        n %= idx;  
        runner = head;  
        idx=0;  
        while(runner!=null && idx<n)  
        {  
            runner = runner.next;  
            idx++;  
        }  
    }  
    while(runner.next!=null)  
    {  
        walker = walker.next;  
        runner = runner.next;  
    }  
    runner.next = head;  
    ListNode newHead = walker.next;  
    walker.next = null;  
    return newHead;  
}  
//上面的实现中采取的方式是直接走到那个结点，如果没超过长度就直接旋转了，如果超过了，就进行取余，并且重新跑到结尾点。其实也可以先直接求长度，然后取余之后再走。其实各有利弊，所以大家根据喜好实现即可哈。



}
