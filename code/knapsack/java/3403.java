import java.util.*;
public class Knapsack {
	
	public static void main (String[] args){
			int[] peso= {1,2,1,3,4,2,4,2,4,1};
			int[] valor={10,15,30,20,10,11,23,4,1,23};
			
			
			int[][] matriz = new int[10][10];
		int i;
		int j;
		for (i=0;i<10;i++){
			Arrays.fill(matriz[i],-1);
			}
		for(i=0;i<10;i++){
			matriz[i][0]=0;
			matriz[0][i]=0;
			}
		
		
		i=0;
		j=0;
		//algoritmo
		
				
		
		
		for(i=0;i<10;i++){
			System.out.println(Arrays.toString(matriz[i]));
			
			}
		
		}
	
	
	MFKnapsack( ) //HACER
	
	
	
	
	
	
	
	}
