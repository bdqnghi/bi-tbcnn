package knapsack;

import java.util.Scanner;

public class Knapsack {

	public static void main(String[] args) {
		// 3 20 18 15 10 25 24 15
		Scanner scan = new Scanner(System.in);		
		int n = scan.nextInt();//��Ʒ����n		
		double c = scan.nextInt();//��������c
		int ID[] = new int[n+1];//ÿ����ƷID
		for(int i=0; i<=n; i++)
			ID[i] = i;
		double w[] = new double[n+1];//ÿ����Ʒ����wi
		for(int i=1; i<=n; i++)
			w[i] = scan.nextDouble();
		double v[] = new double[n+1];//ÿ����Ʒ��ֵvi
		double x[] = new double[n+1];//ÿ����Ʒ�Լ۱�
		for(int i=1; i<=n; i++){
			v[i] = scan.nextDouble();
			x[i] = v[i]/w[i];
		}	
		double a[] = new double[n+1];//װ�������ĸ�����Ʒ����
		bubbleSort(ID, w, v, x);
		knap(c, ID, w, x, a);
		double temp[] = new double[n+1];//����װ�������ĸ�����Ʒ����
		for(int i=1; i<temp.length; i++){
			if(ID[i] < 0){
				int t = -ID[i];
				temp[t] = a[i]; 
			}
		}
		for(int i=1; i<temp.length; i++)
			System.out.print(temp[i] + " ");
	}
	public static void knap(double c, int ID[], double w[], double x[], double a[]){
		int i;
		for(i=1; i<x.length; i++){
			if(w[i]>c) 
				break;
			a[i] = 1.0;
			ID[i] = -ID[i];
			c -= w[i];
		}
		if (i < x.length){
	      a[i] = c/w[i]; 
	      ID[i] = -ID[i];
		}
	}
	public static void bubbleSort(int ID[], double w[], double v[], double x[]){//ð�������㷨 ����  
        for(int i=1;i<x.length-1;i++){   
           for(int j=i+1;j<x.length;j++){   
               if (x[i]<x[j]){   
            	   double temp=x[i];   
                   x[i]=x[j];   
                   x[j]=temp;
                   
                   double temp1=w[i];   
                   w[i]=w[j];   
                   w[j]=temp1;
                   
                   double temp2=v[i];   
                   v[i]=v[j];   
                   v[j]=temp2;
                   
                   int temp3=ID[i];   
                   ID[i]=ID[j];   
                   ID[j]=temp3;
               }   
           }  
        }   
	}

}
