package chapter5.item26;

import java.util.Arrays;
import java.util.EmptyStackException;

/**
 * スタックを配列で実装したクラス。
 * 
 */
public class Stack {

	/** スタック */
	private Object[] elements;
	/** 現在のスタックの要素数 */
	private int size = 0;
	/** スタックの初期サイズ */
	private static final int DEFAULT_INITIAL_CAPACITY = 16;

	/**
	 * デフォルトコストラクタ。
	 */
	public Stack() {
		elements = new Object[DEFAULT_INITIAL_CAPACITY];
	}

	/**
	 * スタックに要素を格納する。
	 * 
	 * @param e
	 */
	public void push(Object e) {
		ensureCapacity();
		elements[size++] = e;
	}

	/**
	 * スタックから要素を取り出す。
	 * 
	 * @return
	 */
	public Object pop() {
		if (size == 0) {
			throw new EmptyStackException();
		}
		Object result = elements[--size];
		elements[size] = null;// 廃れた参照を除く
		return result;
	}

	/**
	 * スタックの要素が空かチェックする
	 * 
	 * @return
	 */
	public boolean isEmpty() {
		return size == 0;
	}

	/**
	 * スタックがいっぱいだった場合にスタックの容量を拡張する。
	 */
	private void ensureCapacity() {
		if (elements.length == size) {
			elements = Arrays.copyOf(elements, 2 * size + 1);
		}
	}

	/**
	 * スタックの簡単なテスト。
	 * 
	 * @param args
	 */
	public static void main(String[] args) {
		Stack stack = new Stack();
		String[] input = { "1a", "2b", "3c", "4d" };
		for (String str : input) {
			stack.push(str);
		}
		while (!stack.isEmpty()) {
			System.out.println(((String)stack.pop()).toUpperCase());
		}
	}
}
