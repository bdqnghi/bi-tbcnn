package com.shi;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ConcurrentLinkedQueue;

/**
 * Created by Administrator on 2017/6/20.
 */
public class Queue {

  public static void main(String[] args) {

    ConcurrentLinkedQueue<String> queue = new ConcurrentLinkedQueue<String>();
  /*  queue.add("1");
    queue.add("2");
    queue.add("3");
    queue.add("4");
    queue.add("5");
    queue.add("6");
    queue.add("7");
    queue.add("8");
    queue.add("9");
    queue.add("11");
    queue.add("12");
    queue.add("13");
    queue.add("14");
    queue.add("15");
    queue.add("16");
    queue.add("17");
    queue.add("18");
    queue.add("19");
    queue.add("21");
    queue.add("22");
    queue.add("23");
    queue.add("24");
    queue.add("25");
    queue.add("26");
    queue.add("27");
    queue.add("28");
    queue.add("29");*/

    if (queue.isEmpty()) {
      return;
    }

    List<String> list = new ArrayList<>();
    while (true) {
      System.out.println(queue.poll());
      list.add(queue.poll());
      if (queue.size() == 0) {
        break;
      }
    }
    int size = list.size();
    System.out.println("xxx-" + size);
  }

}
