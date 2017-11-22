package Sort;

/**
 * Created by wanyu on 2017/3/16.
 */
public class bubblesort {
    int[] arrays;

    bubblesort(int[] arrys) {
        this.arrays = arrys;
    }
    public static void main(String[] args){
        TestNum num = new TestNum(100,1,100);

        bubblesort bubblesort = new bubblesort(num.get());
        bubblesort.sort();

    }
    public void sort() {
        int n = arrays.length;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                if (arrays[i] > arrays[j]) {
                    int temp = arrays[j];
                    arrays[j] = arrays[i];
                    arrays[i] = temp;
                }

            }

        }
        Judge judge = new Judge();
       System.out.println( judge.right(arrays));
    }
}
