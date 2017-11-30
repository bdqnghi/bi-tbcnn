
public class Knapsack {

	//��n=5��p=[6,3,5,4,6],w=[2,2,6,5,4],��c=10
	static int N = 5;
	static int[] p = {6,3,5,4,6};
	static int[] w = {4,2,6,5,2};
	
	public static void main(String[] args) {
		int sum=0;
		int c = 10;
		
		String str;
		String[] name = {"a","b","c","d","e"};
		int[] x = knapsack(p, w, name, c);
		str="Ӧ��ѡ��:";
		for(int i=0; i<N; i++){
			sum += x[i]*p[i];
			str += name[i] + "," + x[i] + "��;    ";
		}
		System.out.println(str + "\n    �ܼ�ֵ:"+sum);
		
		/*
		sum = f(0,c);
		System.out.println("  �ܼ�ֵ:"+sum);
		*/
	}
	
	/**
	 * knapsack�����������⣺��N����Ʒ<br>
	 * 		Լ������:	sum(weight[i]*count[i]) <= capacity;<br>
	 * 		��:		max{sum(weight[i]*profit[i])};<br>
	 * 		�����л����������������
	 * @param profit int[N] ������Ʒ�ļ�ֵ 
	 * @param weight int[N] ������Ʒ������
	 * @param name String[N] ÿ�����������
	 * @param capacity int �������
	 * @return count int[N] ��Ž����������ƷӦѡ����
	 */
	public static int[] knapsack(int [] profit, int[] weight,
			String[] name, int capacity){
		int N = profit.length;
		int i;
		if(N != weight.length || N != name.length){
			return null;
		}
		int[] count = new int[5];	//��������������Ʒ������
		double[] price = new double[N];	//profit per weight:����
		for(i = 0; i < N; i++){
			price[i] = profit[i]/weight[i];
		}
		/* ��price������:�ɴ�С */
		int j, indexOfNextMax;
		double nextMax;
		for(i = 0; i < N-1; i++){
			indexOfNextMax = i;
			nextMax = price[i];
			for(j = i+1; j < N; j++){
				if(price[j] > nextMax){
					indexOfNextMax = j;
					nextMax = price[j];
				}
			}
			if(i != indexOfNextMax){
				BasicTool.swap(price, i, indexOfNextMax);
				BasicTool.swap(profit, i, indexOfNextMax);
				BasicTool.swap(weight, i, indexOfNextMax);
				BasicTool.swap(name, i, indexOfNextMax);
			}
		}
		/* ���������Ʒ������ */
		int limit,sum = 0, remaining = capacity;
		for(i = 0; i < N; i++){
			limit = remaining/weight[i];
			count[i] = limit;
			sum += limit * profit[i];
			remaining -= limit * weight[i];
		}
		return count;//���ؽ��
	}
	
	public static int f(int index, int remaining){
		if(remaining <= 0)
			return 0;
		int limit = remaining / w[index];
		if(index == N - 1){
			return limit * p[index];
		}
		int max = 0,temp = 0;
		for(int i=0; i<=limit;i++){
			temp = f(index+1,remaining-w[index]*i) + i*p[index];
			System.out.println("index="+index+":profit="+p[index]+",weight="+w[index]+",upper limit="+limit+",remaining="+remaining
					+"\n\t"+i+"��,possible profit="+temp+",max="+max+",remaining="+(remaining-w[index]*i));
			if(temp > max){
				max = temp;
			}
		}
		return max;
	}
}
