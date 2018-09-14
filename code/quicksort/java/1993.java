package com.wiceflow.Sort.quicksort;

/**
 * 快排
 * Created by BF on 2017/10/2.
 */
public class quicksort {

    public int[] getB() {
        return b;
    }

    private int[] b = new int[101];

    public quicksort(int[] nums) {
        this.b = nums;
    }
    // 6 1 2 7 9 3 4 5 10 8
    // 快排方法
    public void quicksort(int left, int right) {
        int l1 = left, r1 = right;

        if (left > right)
            return;

        while (l1 != r1) {
            // 先从右边往左找 顺序很重要 右边是比准基数大的数
            while (b[r1] >= b[left]&&l1<r1) {
                r1--;
            }
            while (b[l1] <= b[left]&&l1<r1) {
                l1++;
            }
            // 交换两个数的位置 且这时候准基数还没相遇
            if (l1 < r1) {
                int temp = b[r1];
                b[r1] = b[l1];
                b[l1] = temp;
            }
        }

        // 这时候第一轮排序已经完成了
        // 6 1 2 5 4 3 9 7 10 8
        // 将准基数归位
        // 3 1 2 5 4 6 9 7 10 8
        int temp = b[left];
        b[left] = b[l1];
        b[l1] = temp;
        // 继续处理左边的，递归  中间的数已经是在中间了，不必纳入继续排序中
        quicksort(left, l1 - 1);
        // 处理右边的
        quicksort(l1+1, right);
    }


}
