package kehou.zouye2;

/*
 * �κ���ҵ2
 * ����һ����Stack�������ջ�����ص�Ϊ������ȳ�����
 * ��ӷ���add(Object obj)���Լ�delete( )��
 * ���main����������֤��Ҫ��
 * 1.	ʹ��LinkedListʵ�ֶ�ջ
 * 2.	����LinkedList�����ʱ��ʹ��addLast( )����
 * 3.	�ڴ�LinkedList��ȡ��ʱ��ʹ��removeLast( )����

 */
import java.util.LinkedList;
@SuppressWarnings("unchecked")
public class Stack {

	public LinkedList list = new LinkedList();

	/**
	 * ���Ԫ��ʱ������ӵ������
	 * 
	 * @param obj
	 */
	public void add(Object obj) {
		list.addLast(obj);
	}

	/**
	 * ɾ��ʱ����ɾ�����һ��
	 */
	public void delete() {
		list.removeLast();
	}

	public static void main(String[] args) {
		Stack s = new Stack();
		// �������Ԫ��
		s.add("a");
		s.add("b");
		s.add("c");
		System.out.print("�������Ԫ�غ�");
		System.out.println(s.list);
		// ɾ��һ��Ԫ��
		s.delete();
		System.out.print("ɾ��һ��Ԫ�غ�");
		System.out.println(s.list);

	}
}
