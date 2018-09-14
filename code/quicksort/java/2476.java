package nearestNeigh;

import java.util.Collections;
import java.util.List;

public class Quicksort {
	
	public static List<Point> byLat(List<Point> l, int low, int high) {

		int lowWall = low;	//	Left threshold of the unsearched portion of this partition
		int highWall = high;	//	Right threshold of the unsearched portion of this partition
		
		Point pivot = l.get((low + high)/2);	//	Pivot point is the median between high and low
		while (lowWall < highWall) {	//	While there is still unsorted parts of the partition
			while (l.get(lowWall).lat < pivot.lat)	//	Verify that all points in the left partition are lower than the pivot
				lowWall++;	//	Move wall along to the next point

			while (l.get(highWall).lat > pivot.lat) //	Verify that all points in the left partition are lower than the pivot
				highWall--; //	Move wall along to the next point

			if (lowWall <= highWall)	//	Checks that the point should be swapped
				Collections.swap(l, lowWall, highWall);
		}
		if (low + 1 < lowWall)	//	Sorts the left partition if there remaining nodes to the left of the pivot
			byLat(l, low, lowWall);
		if (high > highWall + 1)	//	Sorts the right partition if there are remaining nodes to the right of the pivot
			byLat(l, highWall, high);
		return l;
	}
	
	public static List<Point> byLon(List<Point> l, int low, int high) {

		if (high - low == 1)
			return l;
		
		int lowWall = low;
		int highWall = high;
		
		Point pivot = l.get((low + high)/2);
		while (lowWall < highWall) {
			while (l.get(lowWall).lon < pivot.lon)
				lowWall++;

			while (l.get(highWall).lon > pivot.lon)
				highWall--;

			if (lowWall <= highWall)
				Collections.swap(l, lowWall, highWall);
		}
		if (low < lowWall)
			byLon(l, low, lowWall);
		if (high > highWall)
			byLon(l, highWall, high);
		return l;
	}
	
	public static List<Point> byDist(List<Point> l, Point value, int low, int high) {

		if (high - low == 1)
			return l;
		
		int lowWall = low;
		int highWall = high;
		
		Point pivot = l.get((low + high)/2);
		while (lowWall < highWall) {
			while (l.get(lowWall).distTo(value) < pivot.distTo(value))
				lowWall++;

			while (l.get(highWall).distTo(value) > pivot.distTo(value))
				highWall--;

			if (lowWall <= highWall)
				Collections.swap(l, lowWall, highWall);
		}
		if (low < lowWall)
			byDist(l, value, low, lowWall);
		if (high > highWall)
			byDist(l, value, highWall, high);
		return l;
	}
}