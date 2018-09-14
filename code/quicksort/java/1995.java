package nearestNeigh;

import java.util.Collections;
import java.util.List;

public class Quicksort {
	
	public static List<Point> byLat(List<Point> l, int low, int high) {

		int lowWall = low;
		int highWall = high;
		
		Point pivot = l.get((low + high)/2);
		while (lowWall < highWall) {
			while (l.get(lowWall).lat < pivot.lat)
				lowWall++;

			while (l.get(highWall).lat > pivot.lat)
				highWall--;

			if (lowWall <= highWall)
				Collections.swap(l, lowWall, highWall);
		}
		if (low + 1 < lowWall)
			byLat(l, low, lowWall);
		if (high > highWall + 1)
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