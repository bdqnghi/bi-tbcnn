package compilertalk.vm;

import java.io.PrintStream;
import java.util.Locale;

public class Stack {
	/**
	 * Stack values.
	 */
	public final float[] values;

	/**
	 * Initialize a new stack of the given size.
	 * 
	 * @param stackSize
	 *            Stack size
	 */
	public Stack(int stackSize) {
		values = new float[stackSize];
	}

	/**
	 * Stack pointer. Always points to the top position where the next element
	 * should be pushed.
	 */
	public int sp;

	/**
	 * Standard output stream. Useful for tests to redirect output without
	 * redirecting the global standard output stream.
	 */
	public PrintStream out = System.out;
	
	/**
	 * Locale used for formatting. Useful for tests.
	 */
	public Locale locale = Locale.getDefault();
}
