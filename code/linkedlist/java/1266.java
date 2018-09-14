package demo;
import java.util.*;
public class Linkedlist {
	public static void main(String [] rgs){
		LinkedList ll = new LinkedList();
		Emp emp1 = new Emp("sa01","aa",1.2f);
		Emp emp2 = new Emp("sa02","bb",1.2f);
		//������൱��ջ�Ľṹ��
		ll.addFirst(emp1);
		ll.addFirst(emp2);
		//������Ǵ�ͷ���ȥ�����Ը����Ҫ����ݽṹ��ѡ���뷽ʽ
		for (int i=0;i<ll.size();i++){
			System.out.println(((Emp)ll.get(i)).getName());
		}
		//   ll.remove();
	}

}
