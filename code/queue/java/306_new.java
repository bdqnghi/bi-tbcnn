package cgl.webservices.queueservice;

public class QueueBean {
	 String queueName;
	 String queueMessage;
	 String queueTime;

	 public QueueBean() {
	 }
	 
	 public String getQueueName(){
		  return queueName;
	 }

	 public String getQueueMessage() {
		  return queueMessage;
	 }

	 public String getQueueTime() {
		  return queueTime;
	 }
	 
	 public void setQueueName(String queueName) {
		  this.queueName=queueName;
	 }

	 public void setQueueMessage(String queueMessage) {
		  this.queueMessage=queueMessage;
	 }

	 public void setQueueTime(String queueTime){
		  this.queueTime=queueTime;
	 }
	 
}