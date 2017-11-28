package Standard_Algorithms;

public class Mergesort
{
    // To merge sorted the sorted subarray A[p] ... A[q] with the
    // sorted subarray A[q+1] ... A[r],
    private static void merge(float[] A, int p, int q, int r)
    {
        // Let's make a new array L to hold A[p] ... A[q],
        int LSize = q-p+1;
        float[] L = new float[LSize+1];
        for (int i=0; i<LSize; i++)
            {
                L[i] = A[p+i];
            }
        // But let's actually put a sentinel value on the end to tell
        // us when we've used up all the actual elements of A[p]
        // ... A[q].
        L[LSize] = Float.POSITIVE_INFINITY;

        // And then do the same thing for A[q+1] ... A[r]; we'll call
        // this new array R.
        int RSize = r-q;
        float[] R = new float[RSize+1];
        for (int j=0; j<RSize; j++)
            {
                R[j] = A[q+1+j];
            }
        R[RSize] = Float.POSITIVE_INFINITY;

        // Merge!
        int i = 0;
        int j = 0;
        for (int k=p; k<r+1; k++)
            {
                if (L[i] <= R[j])
                    {
                        A[k] = L[i];
                        i++;
                    }
                else
                    {
                        A[k] = R[j];
                        j++;
                    }
            }
    }

    // We can use our merge procedure to sort an array recursively!
    public static void mergesort(float[] A, int p, int r)
    {
        // The recursion bottoms out for subarrays with only one
        // element, which cannot help but be sorted.
        if (p < r)
            {
                int q = (p+r)/2;
                mergesort(A, p, q);
                mergesort(A, q+1, r);
                merge(A, p, q, r);
            }
    }

}