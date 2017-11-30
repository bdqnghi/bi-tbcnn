package com.epam.cdp.java_testng.iryna_lasotskaya.Part2task2;

import java.util.LinkedList;
import java.util.ListIterator;
import java.util.Random;
/**
 * Created by Iryna_Lasotskaya on 08.02.2017.
 */
public class Linkedlist {


    public static LinkedList<Integer> getRandomLinkedList() {
        // 1. Ты объявила коллекцию
        LinkedList<Integer> numbersGeneratedList = new LinkedList<>();

        // 2. Создала объект для генерации рандомных чисел
        Random random = new Random();
        for (int i = 0; i < 7000; i++) {
            // 3. делаешь заполнение коллекции
            numbersGeneratedList.add(random.nextInt());
        }

        return numbersGeneratedList;

    }
}
