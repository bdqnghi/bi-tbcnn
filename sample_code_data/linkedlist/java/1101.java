package Test;

import java.util.HashMap;
import java.util.Scanner;
import java.util.Stack;
import java.util.logging.Logger;

/**
 * Created by MingfengMa .
 * Data : 2017/2/7
 * Desc :
 */
public class Linkedlist {

    Logger logger = Logger.getLogger("linkedlist");

    public static class Node{
        int data; //数据域
        Node next; //指针域
        public Node(int data){
            this.data = data;
            this.next = null;
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        Node head = null;
        if (in.hasNext()){
            head = new Node(in.nextInt());
        }
        Node tmp = head;
        while (in.hasNext()){
            tmp.next = new Node(in.nextInt());
            tmp = tmp.next;
        }

        in.close();
    }

    //求单链表中结点的个数
    public static int getListLength(Node head){
        int len = 0;
        while (head != null){
            len++;
            head = head.next;
        }
        return len;
    }

    //单链表反转-循环
    public static Node reverseList(Node head){
        if (head == null || head.next == null)
            return head;
        Node pre = null;
        Node tmp;
        while (head!=null){
            tmp = head.next;
            head.next = pre;
            pre = head;
            head = tmp;
        }
        return pre;
    }

    //单链表翻转-递归
    public static Node reverseListRec(Node head){
        if (head == null || head.next == null)
            return head;
        Node rehead = reverseListRec(head.next);
        head.next.next = head;
        head.next = null;
        return rehead;
    }

    //查找单链表中的倒数第K个结点(k>0)
    public static Node reGetKthNode(Node head,int k){
        if (head == null)
            return head;
        int len = getListLength(head);
        if (k>len)
            return null;
        Node target = head;
        Node nexk = head;
        for (int i =0;i<k;i++){
            nexk = nexk.next;
        }
        while (nexk!=null){
            target = target.next;
            nexk =nexk.next;
        }
        return target;
    }

    //查找单链表的中间结点
    public static Node getMiddleNode(Node head){
        if (head == null || head.next == null)
            return head;
        Node target = head;
        Node temp = head;
        while (temp!= null&& temp.next!= null){
            target = target.next;
            temp = temp.next.next;
        }
        return target;
    }

    //从尾到头打印单链表,递归
    public static void reversePrintListRec(Node head){
        if (head == null){
            return;
        }else {
            reversePrintListRec(head.next);
            System.out.println(head.data);
        }
    }

    //打印单链表,栈
    public static void reversePrintListStack(Node head){
        Stack<Node> stack = new Stack<Node>();
        while (head!=null){
            stack.push(head);
            head = head.next;
        }
        while (!stack.isEmpty()){
            System.out.println(stack.pop().data);
        }
    }

    //合并两个有序的单链表head1和head2,循环
    public static Node merageSortedList(Node head1,Node head2){
        if (head1 == null) return head2;
        if (head2 == null) return head1;
        //合并列表
        Node target = null;
        //获取新链表头元素
        if (head1.data > head2.data){
            target = head2;
            head2 = head2.next;
        }else {
            target = head1;
            head1 = head1.next;
        }
        target.next = null;
        Node mergeHead = target;
        //遍历两个链表中的所有元素并比较大小加入新链表
        while (head1!= null && head2!= null){
            if (head1.data >head2.data){
                target.next=head2;
                head2 = head2.next;
            }else {
                target.next = head1;
                head1=head1.next;
            }
            target=target.next;
            target.next = null;
        }
        if (head1==null)
            target.next = head2;
        else
            target.next = head1;
        return mergeHead;
    }

    //合并两个有序的单链表head1和head2,递归
    public static Node mergeSortedListRec(Node head1,Node head2){
        if (head1 == null) return head2;
        if (head2 == null) return head1;
        if (head1.data > head2.data){
            head2.next = mergeSortedListRec(head2.next,head1);
            return head2;
        }else {
            head1.next = mergeSortedListRec(head1.next,head2);
            return head1;
        }
    }

    //判断单链表是否有环,快慢指针
    public static boolean hasCycle(Node head){
        boolean flag =false;
        Node p1 = head;
        Node p2 = head;
        while (p1 !=null && p2!=null){
            p1 = p1.next;
            p2 = p2.next.next;
            if (p1 == p2){
                flag = true;
                break;
            }
        }
        return flag;
    }

    //判断两个单链表是否相交
    public static Node isIntersect(Node head1,Node head2){
        Node target = null;
        if (head1 == null || head2 == null) return null;
        int len1 = getListLength(head1);
        int len2 = getListLength(head2);
        if (len1 >= len2){
            for (int i = 0;i< len1-len2;i++){
                head1 = head1.next;
            }
        }else {
            for (int i=0;i<len2-len1;i++){
                head2 = head2.next;
            }
        }

        while (head1!=null&&head2!=null){
            if (head1==head2){
                target = head1;
                break;
            }else {
                head1 = head1.next;
                head2 = head2.next;
            }
        }
        return target;
    }

    //获取环
    public static Node getFirstNodeInCycleHashMap(Node head){
        Node target = null;
        HashMap<Node,Boolean> map = new HashMap<>();
        while (head!= null){
            if (map.containsKey(head))
                target = head;
            else {
                map.put(head,true);
            }
            head = head.next;
        }
        return target;
    }


}
