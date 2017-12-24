import java.io.*;
import java.util.*;
public class DFS{
	public static int A[][];
	public static boolean used[];
	public static int n;
	public static int color[];
	public static Scanner sc;
	public static void main(String[]args){
		try{
			sc=new Scanner(new FileInputStream("System.in"));
		}
		catch(Exception e){
			//System.out.println(e.stackTrace());
		}
		n=sc.nextInt();
		int v=sc.nextInt();
		A=new int[n+1][n+1];
		for(int i=1;i<n+1; i++){
			for(int j=1;j<n+1;j++)
				A[i][j]=sc.nextInt();
		}
		color= new int[n+1];
		for(int i=1;i<n+1;i++){
			color[i]=0;
		}
		DFS(v,v);
		System.out.println("Loop NOT found in this graph!");
	}
	public static void DFS(int v, int k){
		color[v]=1;
		for(int i=1;i<n+1;i++){
		if(k!=i)
			if (A[v][i]==1)
				if(color[i]==0){
					DFS(i,v);
				}else{
					System.out.println("Loop found in this graph!");
					System.exit(0);
				}

		}
		color[v]=2;
	}
}