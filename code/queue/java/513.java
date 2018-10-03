package jp.gr.java_conf.genzo.java.sample.collection;

import java.util.Date;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.DelayQueue;
import java.util.concurrent.Delayed;
import java.util.concurrent.TimeUnit;

public class QueueDelayQueue {

	/**
	 * @param args
	 * 
	 */
	public static void main(String[] args) throws InterruptedException {

		long[] waits = { 10, 8, 6, 0, 1, 2 };
		String[] tests = { "10", "8", "6", "0", "1", "2" };

		// 遅延時間のばらばらのデータをqueueに入れる
		BlockingQueue<Task> queue = new DelayQueue<Task>();
		for (int i = 0; i < waits.length; i++) {
			queue.add(new Task(tests[i], waits[i]));
		}

		// 空になるまでループする。
		while (true) {
			Task task = queue.take();
			task.execute();
		}

	}

	/**
	 * java.util.concurrent.Delayedを実装した例.
	 * 
	 */
	static class Task implements Delayed {

		final private long execTime;
		final private String text;

		/**
		 * テキストと遅延時間を指定したコンストラクタ.
		 * 
		 * @param text
		 * @param wait
		 */
		Task(String text, long wait) {
			this.text = text;
			this.execTime = System.nanoTime() + TimeUnit.SECONDS.toNanos(wait);
		}

		/*
		 * (non-Javadoc)
		 * 
		 * @see java.lang.Comparable#compareTo(java.lang.Object)
		 */
		@Override
		public int compareTo(Delayed o) {
			long diff = execTime - ((Task) o).execTime;
			if (diff == 0) {
				return 0;
			}

			return (diff > 0) ? 1 : -1;
		}

		/*
		 * (non-Javadoc)
		 * 
		 * @see
		 * java.util.concurrent.Delayed#getDelay(java.util.concurrent.TimeUnit)
		 */
		@Override
		public long getDelay(TimeUnit unit) {
			// 残遅延時間を返却
			System.out.println(String.format("%tT getDelay text=[%s] w=[%d]",
					new Date(), text, execTime - System.nanoTime()));
			return execTime - System.nanoTime();
		}

		/**
		 * 処理.
		 */
		public void execute() {
			System.out.println(String.format("%tT execute  text=[%s]秒後",
					new Date(), text));
		}

	}
}
