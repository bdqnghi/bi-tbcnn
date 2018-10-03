package com.william.demo.jdon.jserver.connector.queue;

public class QueueFactory {

    private final static MessageQueue tcp_queue = new MessageQueue();
    private final static MessageQueue udp_queue = new MessageQueue();

    public final static int TCP_QUEUE = 1;
    public final static int UDP_QUEUE = 2;

    private final static QueueFactory factory = new QueueFactory();

    public static QueueFactory getInstance(){
        return factory;
    }

    public  MessageQueue getQueue(int queueType){
        if (queueType == TCP_QUEUE)
            return tcp_queue;
        else
            return udp_queue;
    }

}