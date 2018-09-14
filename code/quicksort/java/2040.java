/*-
 * Copyright © 2009 Diamond Light Source Ltd., Science and Technology
 * Facilities Council Daresbury Laboratory
 *
 * This file is part of GDA.
 *
 * GDA is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License version 3 as published by the Free
 * Software Foundation.
 *
 * GDA is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along
 * with GDA. If not, see <http://www.gnu.org/licenses/>.
 */

package gda.analysis.numerical.sorting;

/**
 * A standard quicksort algorithm See any computing or numerical analysis book for details !!!
 */
public class Quicksort {
	/**
	 * @param a
	 * @param lo
	 * @param hi
	 */
	public static void quicksort(int[] a, int lo, int hi) {
		// lo is the lower index, hi is the upper index
		// of the region of array a that is to be sorted
		int i = lo, j = hi, h;
		int x = a[(lo + hi) / 2];

		// partition
		do {
			while (a[i] < x) {
				i++;
			}
			while (a[j] > x) {
				j--;
			}
			if (i <= j) {
				h = a[i];
				a[i] = a[j];
				a[j] = h;
				i++;
				j--;
			}
		} while (i <= j);

		// recursion
		if (lo < j)
			quicksort(a, lo, j);
		if (i < hi)
			quicksort(a, i, hi);
	}

	/**
	 * @param a
	 * @param lo
	 * @param hi
	 */
	public static void quicksort(double[] a, int lo, int hi) {
		// lo is the lower index, hi is the upper index
		// of the region of array a that is to be sorted
		int i = lo, j = hi;
		double x = a[(lo + hi) / 2], h;

		// partition
		do {
			while (a[i] < x) {
				i++;
			}
			while (a[j] > x) {
				j--;
			}
			if (i <= j) {
				h = a[i];
				a[i] = a[j];
				a[j] = h;
				i++;
				j--;
			}
		} while (i <= j);

		// recursion
		if (lo < j)
			quicksort(a, lo, j);
		if (i < hi)
			quicksort(a, i, hi);
	}

}
