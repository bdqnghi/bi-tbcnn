package chapter5.item28;

import java.util.Collection;

public interface Stack<E> {

	/**
	 * スタックに要素を格納する。
	 * 
	 * @param e
	 */
	public void push(E e);

	/**
	 * スタックから要素を取り出す。
	 * 
	 * @return
	 */
	public E pop();

	/**
	 * スタックの要素が空かチェックする
	 * 
	 * @return
	 */
	public boolean isEmpty();

	/**
	 * スタックにまとめて格納する。
	 * 
	 * @param src
	 */
	public void pushAll(Iterable<E> src);
	//public void pushAll(Iterable<? extends E> src);

	/**
	 * スタックからまとめて要素を取り出して引数コレクションに格納する。
	 * 
	 * @param dst
	 */
	public void popAll(Collection<E> dst);
	//public void popAll(Collection<? super E> dst);
}