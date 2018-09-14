public class Point {
	public int x;
	public int y;

	public Point(int x, int y) {
		this.x = x;
		this.y = y;
	}

}
 public class Swap {
 	static void swapPoint(Point p) {
 		int temp = p.x;
 		p.x = p.y;
 		p.y = temp;
 	}

 	public static void main(String args[]) {
 		int x = 30;
 		int y = 19;
 		System.out.println("Orig x: " + x);
 		System.out.println("Orig y: " + y);
 		swap(x, y);
 		System.out.println("New x: " + x);
 		System.out.println("New y: " + y);
 		Point p = new Point(x, y);
 		System.out.println("Orig x: " + p.x);
 		System.out.println("Orig y: " + p.y);
 		swapPoint(p);
 		System.out.println("New x: " + p.x);
 		System.out.println("New y: " + p.y);

 	}
 }