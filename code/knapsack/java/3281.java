package week10;


import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

class Knapsack
{
	public static void main (String args[]) throws Exception // entry point from OS
	{
		new MyClass();  // create dynamic entry point
	}
}

class MyClass {

	MyClass () throws IOException
	{
		int B[][];
		int numItems, maxWeight, w, k;
		int benefit[], weight[];
		int remainingWeight;
		int profitWeight;
		int setNumber = 1;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		// System.out.println(maxWeight+" "+ numItems);
		for (int tc = 1; tc <= t; tc++) 
		{

			String[] inp1 = br.readLine().split(" ");
			//***  Read in the initial numItems, maxWeight pair
			//ls = new Scanner(s.nextLine());
			numItems = Integer.parseInt(inp1[1]);
			maxWeight = Integer.parseInt(inp1[0]);
			// *** Read in all the data for the items
			benefit = new int [numItems+1];
			weight = new int [numItems+1];
			boolean items[] = new boolean[numItems+1];
			Map<Integer,Integer> profit = new HashMap<Integer,Integer>(numItems);
			// ls = new Scanner(s.nextLine());
			for (k = 1; k <= numItems; k++)
			{  
				String[] inp2 = br.readLine().split(" ");
				benefit [k] = Integer.parseInt(inp2[1]);
				weight [k] = Integer.parseInt(inp2[0]);
				int highProfit = (maxWeight/ weight[k])*benefit[k];
				profit.put(k, highProfit);
			}
			profit =
					profit.entrySet().stream()
					.sorted(Collections.reverseOrder(Map.Entry.comparingByValue()))
					.collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue,
							(e1, e2) -> e2, LinkedHashMap::new));
			// *** initialize
			B = new int [numItems+1][maxWeight+1]; 
			for (w = 0; w <= maxWeight; w++) 
				B[0][w] = 0; 

			// *** Now do the work!
			for (k = 1; k <= numItems; k++)
			{
				for (w = maxWeight; w >= weight[k]; w--)
					if (benefit[k] + B[k-1][w-weight[k]] > B[k-1][w])
						B[k][w] = benefit[k] + B[k-1][w-weight[k]];
					else
						B[k][w] = B[k-1][w];

				for (w = 0; w < weight[k]; w++) {
					if(w<=maxWeight)
						B[k][w] = B[k-1][w];
					else 
						break;
				}
			}
			//          for(int i=0;i<=numItems;i++){
			//        	  for(int j=0;j<=maxWeight;j++){
			//        		  System.out.print(B[i][j]+" ");
			//        	  }
			//        	  System.out.println();
			//          }
			// *** Print out the results.   
			for (k = numItems, remainingWeight=maxWeight; k > 0; k--)
			{
				if (remainingWeight >= weight[k])
					if ( B[k][remainingWeight] == (benefit[k] + B[k-1][remainingWeight - weight[k]]) )
					{
						//  System.out.print("  " + k);
						items[k]=true;
						remainingWeight -= weight[k];

					}
			}
			StringBuilder sb = new StringBuilder("Case #");
			sb.append(tc);
			sb.append(":");
			profitWeight = maxWeight;
			Iterator<Map.Entry<Integer, Integer>> profitIterator =  profit.entrySet().iterator();
			while (profitIterator.hasNext()) {
				Map.Entry<Integer, Integer> entry = profitIterator.next();
				//if(items[entry.getKey()]){
					//while(profitWeight>=weight[entry.getKey()]){
						sb.append("  ");
						sb.append(entry.getKey());
						profitWeight -= weight[entry.getKey()];
					//}
				//}
				//System.out.printf("Key : %s and Value: %s %n", entry.getKey(), 
				//                                               entry.getValue());
			}
			System.out.println(sb.toString());
			//          for(int i=1;i<=numItems;i++){
			//        	  if(items[i]){
			//             	  System.out.print("  " + i);
			//        	  }
			//   
			//          }
			br.readLine();
		}  

	}

}  //**  end of the "MyClass" class