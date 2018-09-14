package singular.cluster.bubblesort;

/**
 * Created by Andrew Michel on 10/9/2017.
 */
public final class Bubblesort
{
    // Private constructor
    private Bubblesort() {}

    public static void sort(int[] array)
    {
        sort(array, 0, array.length);
    }

    public static void sort(int[] array, int startIndex, int endIndex)
    {
        boolean swapOccurred = true;
        int swapValue = Integer.MIN_VALUE;

        for(int i = startIndex; i < endIndex && swapOccurred; i++)
        {
            swapOccurred = false;

            for(int k = startIndex; k < endIndex - i - 1; k++)
            {
                if(array[k] > array[k + 1])
                {
                    swapOccurred = true;
                    swapValue = array[k];
                    array[k] = array[k + 1];
                    array[k + 1] = swapValue;
                }
            }
        }
    }
}
