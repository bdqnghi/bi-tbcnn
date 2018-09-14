import java.util.*;
public class bubblesort {
   public static void main(String[] args){
	   Scanner sc = new Scanner(System.in);
	   int g = sc.nextInt();
	   int[] r = new int[g];
	   for(int i = 0;i<g;i++){
		   r[i] = sc.nextInt();
	   }
	   for(int a = 0;a<g;a++){
		   for(int b = 0;b<g;b++){
			   if(r[a]<r[b]){
				   int c = r[a];
				   r[a] = r[b];
				   r[b] = c;
			   }
		   }
	   }
	   for(int i = 0;i<g;i++){
		   System.out.println(r[i]);
	   }
   }
}
