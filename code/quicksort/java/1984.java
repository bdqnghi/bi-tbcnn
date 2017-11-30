package crossutil;

import java.util.Arrays;
import java.util.List;

/**
 * This Quicksort class is an amateur implementation
 * written for practice.  The pivot is chosen as the 
 * median of the first, middle, and last in each sub-
 * list.  The algorithm is almost completely
 * standard, but I have been more verbose than usual.
 * My goal in writing this was to make it 
 * readable---not necessarily to optimize it for speed.
 * For whatever reason, I tend to have problems keeping
 * track of the indices when writing quicksort, so I
 * was attempting to write this class so that there 
 * was absolutely no place for indexing errors to hide. 
 * 
 * @author Adam Cross
 *
 */
public abstract class Quicksort
{
	static class QuickSorter<T extends Comparable<T>>
	{
		List<T> list;
		QuickSorter(){}
		public List<T> sort(List<T> list)
		{
			this.list = list;
			sort(0, list.size());
			return list;
		}
		IndexPair swapAllInversionPairs(IndexPair invPair, int beginIndex, int endIndex, IndexValuePair<T> pivot)
		{
			invPair = getNextInversionPair(invPair, beginIndex, endIndex, pivot);
			while (invPair.left < invPair.right)
			{
				swap(invPair.left, invPair.right);
				invPair = getNextInversionPair(invPair, beginIndex, endIndex, pivot);
			}
			return invPair;
		}
		
		Integer partitionTheSublist(int beginIndex, int endIndex)
		{
			IndexValuePair<T> pivot = getPivot(beginIndex, endIndex);
			IndexPair invPair = null;
			invPair = swapAllInversionPairs(invPair, beginIndex, endIndex, pivot);
			//
			
			int pivotLowerBound = invPair.right;
			int pivotUpperBound = invPair.left;
			if (pivotLowerBound >= pivotUpperBound)
				throw new RuntimeException();
			pivot = pivotToFinalPosition(pivot, pivotLowerBound, pivotUpperBound);
			return pivot.index;
		}
		
		void sort(int beginIndex, int endIndex)
		{
			boolean sublistIsQuiteShort = (endIndex - beginIndex <= 10);
			if (sublistIsQuiteShort)
			{
				insertionSort(list, beginIndex, endIndex);
			} else {
				int pivotIndex = partitionTheSublist(beginIndex, endIndex);
				sort(beginIndex, pivotIndex);
				sort(pivotIndex, endIndex);
			}
		}
		IndexValuePair<T> getPivot(int beginIndex, int endIndex)
		{
			int length = endIndex - beginIndex;
			IndexValuePair<T> first, middle, last;
			int halfway = beginIndex + length/2;
			int maxIndex = endIndex - 1;
			first = new IndexValuePair<>(beginIndex, list.get(beginIndex));
			middle = new IndexValuePair<>(halfway, list.get(halfway));
			last = new IndexValuePair<>(maxIndex, list.get(maxIndex));
			return getMedianOf(first, middle, last);
		}
		
		IndexPair getNextInversionPair(IndexPair inversionPair, int startIndex, int endIndex, IndexValuePair<T> pivot)
		{
			int leftIndex, rightIndex;
			if (inversionPair == null)
			{
				leftIndex = startIndex;
				rightIndex = endIndex - 1;
			} else {
				leftIndex = inversionPair.left;
				rightIndex = inversionPair.right - 1;
			}
			int lowerBound = startIndex - 1;
			int upperBound = endIndex;
			
			while (leftIndex < upperBound && list.get(leftIndex).compareTo(pivot.value) <= 0)
				leftIndex++;
			while (rightIndex > lowerBound && list.get(rightIndex).compareTo(pivot.value) >= 0)
				rightIndex--;
			return new IndexPair(leftIndex, rightIndex);
		}
		void swap(int i, int j)
		{
			T placeholder = list.get(i);
			list.set(i, list.get(j));
			list.set(j, placeholder);
		}
		IndexValuePair<T> pivotToFinalPosition(IndexValuePair<T> pivot,  int leftBound, int rightBound)
		{
			boolean pivotIsTooFarLeft = (pivot.index < leftBound);
			boolean pivotIsTooFarRight = (pivot.index > rightBound);
			if (pivotIsTooFarLeft) {
				swap(pivot.index,leftBound);
				return new IndexValuePair<T>(leftBound, pivot.value);
			} else if (pivotIsTooFarRight)
			{
				swap(pivot.index, rightBound);
				return new IndexValuePair<T>(rightBound, pivot.value);
			} else {
				return pivot;
			}
		}
	}
	
	public static <T extends Comparable<T>> List<T> sort(List<T> list)
	{
		QuickSorter<T> sorter = new QuickSorter<>();
		return sorter.sort(list);
	}

	static <T extends Comparable<T>> void insertionSort(List<T> list, int beginIndex, int endIndex)
	{
		if (endIndex - beginIndex <= 1)
			return;
		int maxIndex = endIndex - 1;
		for(int partition = beginIndex; partition < maxIndex; partition++)
		{
			T sortElement = list.get(partition + 1);
			int testIndex = partition;
			while (testIndex >= beginIndex && list.get(testIndex).compareTo(sortElement) > 0)
				list.set(testIndex + 1 , list.get(testIndex--));
			list.set(++testIndex, sortElement);
		}
	}
	static <U extends Comparable<U>> U getMedianOf(U a, U b, U c)
	{
		List<U> threeSortables = Arrays.asList(a, b, c);
		insertionSort(threeSortables, 0, 3);
		return threeSortables.get(1);
	}
}
