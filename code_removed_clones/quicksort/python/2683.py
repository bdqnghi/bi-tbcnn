import test

def quick_sort(array):
    """Quicksort

    Properties:
        Unstable
        Time: O(n^2). Average: O(n * log(n))
        Space: O(n). Average: O(log(n))

    Description:
        Wikipedia: http://en.wikipedia.org/wiki/Quicksort
        Cormen [1]: section 7, page 170
        Sedgewick [2]: section 2.3, page 288

    History:
        Author: Tony Hoare (1960)
    """
    def sort(low, high):
        if low >= high:
            return
        p = array[low + (high - low) // 2]
        i = low
        j = high

        while i <= j:
            while array[i] < p:
                i += 1
            while array[j] > p:
                j -= 1

            if i <= j:
                array[i], array[j] = array[j], array[i]
                i += 1
                j -=1

        sort(low, j)
        sort(i, high)

    sort(0, len(array) - 1)


def main():
    test.test_sort(quick_sort)
    print('All tests passed')


if __name__ == '__main__':
    main()
