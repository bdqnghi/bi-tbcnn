package knapsack;

import java.util.Scanner;

public class Knapsack {

	public static void main(String[] args) {
		// TODO �Զ����ɵķ������
		Scanner scan = new Scanner(System.in);
//		 n = 4, c = 5;
//		 w[] = {0, 2, 1, 3, 2};
//		 v[] = {0, 12, 10, 20, 15};
		//��Ʒ����n
		int n = scan.nextInt();
		//��������c
		int c = scan.nextInt();
		//ÿ����Ʒ����wi
		int w[] = new int[n+1];
		w[0] = 1;
		for(int i=1; i<=n; i++)
			w[i] = scan.nextInt();
		//ÿ����Ʒ��ֵvi
		int v[] = new int[n+1];
		v[0] = 1;
		for(int i=1; i<=n; i++)
			v[i] = scan.nextInt();
		//����ֵ����
		int m[][] = new int[n+1][c+1];
		//��Ʒ��ѡ������
		int x[] = new int[n+1];
		
		Knapsack1(v, w, c, n, m);
		Traceback(m, w, c, n, x);
		for(int i=1; i<x.length; i++)
			System.out.print(x[i]+" ");
	}
	//vΪ��ֵ����,Vi(1 <= i <= n)  wΪ��������,Wi(1 <= i <= n)  cΪ��������  nΪ��Ʒ����������Ʒi����1 <= i <= n
	public static void Knapsack1(int v[], int w[], int c, int n,int m[][]){
		int jMax = min(w[n]-1, c);
		for(int j=0; j<=jMax; j++)//��ʼ��m[n][j], ��ά����������һ��
			m[n][j] = 0;
		for(int j=w[n]; j<=c; j++)//��ʼ��m[n][j]
			m[n][j] = v[n];
		for(int i=n-1; i>0; i--){
			jMax = min(w[i]-1, c);
			for(int j=0; j<=jMax; j++)
				m[i][j] = m[i+1][j];
			for(int j=w[i]; j<=c; j++)
				m[i][j] = max(m[i+1][j], m[i+1][j-w[i]]+v[i]);		
		}
//		m[1][c] = m[2][c];
//		if(c >= w[1])
//			m[1][c] = max(m[1][c], m[2][c-w[1]]+v[1]);
	}
	public static void Traceback(int m[][], int w[], int c, int n, int x[]){
		for(int i=1; i<n; i++)
			if(m[i][c] == m[i+1][c])
				x[i] = 0;
			else{
				x[i] = 1;
				c -= w[i];
			}
		x[n] = (m[n][c] != 0)?1:0;
	}
	public static int min(int x, int y){return x<y?x:y;}
	public static int max(int x, int y){return x>y?x:y;}

}
