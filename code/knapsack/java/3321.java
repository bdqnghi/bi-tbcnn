package algorithms.dynamic;

public class Knapsack {


	public static void main(String args[]){

		int K=13;
		int n=5;
		int w[]=new int[]{0,5,4,3,2,4};
		int p[]=new int[]{0,4,2,4,1,5};


		int profit[][]=new int[n+1][K+1];
		int dir[][]=new int[n+1][K+1];

System.out.println("Profit Array:");
		for(int i=1;i<=n;i++){
			for(int j=1;j<=K;j++){

				if(w[i]>j){
					// we cant add this item into knapsack
					profit[i][j]=profit[i-1][j];
					dir[i][j]=1;
				}else{

					profit[i][j]=Math.max(profit[i-1][j],p[i]+profit[i-1][j-w[i]]);
					if(profit[i-1][j]>p[i]+profit[i-1][j-w[i]])
						dir[i][j]=1;
					else
						dir[i][j]=2;	

				}
			}
			for(int l=0;l<=K;l++){
				System.out.print("\t"+profit[i][l]);
			}
			System.out.println();
		}
		System.out.println("\nDir array");
		for(int i=0;i<=n;i++){
			for(int l=0;l<=K;l++){
				System.out.print("\t"+dir[i][l]);
			}
			System.out.println();
		}




		System.out.println("Profit:"+profit[n][K]);

		int j=K;
		for(int i=n;i>=1;i--){
			if(dir[i][j]==2){
				System.out.print(" <item "+i+",weight:"+w[i]+",profit:"+p[i]+">,");
				j=j-w[i];
			} 
		}



	}

}
