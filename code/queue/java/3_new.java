package edu.harvard.i2b2.crc.quartz;

public class AnalysisQueue {

	public static AnalysisQueue.QueueType getNextQueue(String queueName) {
		QueueType queueType = QueueType.valueOf(queueName);
		switch (queueType) {
		case FILLER:
			return QueueType.MEDIUM_QUEUE;
		case MEDIUM_QUEUE:
			return QueueType.LARGE_QUEUE;
		case LARGE_QUEUE:
			return QueueType.NO_MORE_QUEUE;
		default:
			return QueueType.NO_MORE_QUEUE;
		}
	}

	public enum QueueType {
		FILLER, MEDIUM_QUEUE, LARGE_QUEUE, NO_MORE_QUEUE;
	}
}
