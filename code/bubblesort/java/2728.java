/*
* bublesort
* based on Professor Darin Brezeale's version
*/

public class Bubblesort
{
	public static void main(String[] args)
	{
		int d[] = {-23, -5, 6, 10, 1};

		print1D(d);
		bubble(d);
		print1D(d);
	}

	public static void print1D(int[] d)
	{
		for(int i = 0; i < d.length; i++)
			System.out.printf("%d  ", d[i]);
		System.out.println();
	}

	/*
	* bubblesort takes an arr and sorts it
	*/
	public static void bubble(int[] d)
	{
		boolean sorted;
		int i, temp;

		do
		{
			sorted = true;
			for(i = 0; i < d.length-1; i++)
			{
				if(d[i] > d[i+1])
				{
					temp = d[i];
					d[i] = d[i+1];
					d[i+1] = temp;
					sorted = false;
				}
			}
		} while( !sorted );
	}
}