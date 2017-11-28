package knapsack;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;


public class Knapsack {
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.print("배낭의 사이즈를 입력하세요(0~50) : ");
		Scanner sc = new Scanner(System.in);
		int W = sc.nextInt();
		int N = 0;
		sc.close();
		
		ArrayList<Integer> tmp_item = new ArrayList<Integer>(); // 아이템 이름을 저장할 ArrayList
		ArrayList<Integer> tmp_value = new ArrayList<Integer>(); // Value를 저장할 ArrayList
		ArrayList<Integer> tmp_weight = new ArrayList<Integer>(); // 무게를 저장할 ArrayList
			
		String dataFileName = "data11.txt"; // 데이터를 읽어온다. 
		BufferedReader dataFile; 
		try {
			dataFile = new BufferedReader(new FileReader(dataFileName));
			String data = "";
			while((data = dataFile.readLine()) != null){
				String[] tmp = data.split(",");
				tmp_item.add(Integer.valueOf(tmp[0])); // 아이템 
				tmp_value.add(Integer.valueOf(tmp[1])); // 가중치 Value
				tmp_weight.add(Integer.valueOf(tmp[2])); // 무게
				N++;									// 아이템 갯수 count
			} 
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		int[] item = tmp_item.stream().mapToInt(i -> i).toArray(); // 아이템List를 Array로 저장 
		int[] value = tmp_value.stream().mapToInt(i -> i).toArray(); // 가중치를 Array로 저장 
		int[] weight = tmp_weight.stream().mapToInt(i -> i).toArray(); // 무게를 Array로 저장
		
		int[][] OPT = new int[N+1][W+1];			// 전체 가중치를 저장할 배열 
		
		for (int i = 0; i < N + 1; i++ ){
			for (int w = 0; w < W + 1; w++){
				if (i == 0){					// if i == 0
					OPT[i][w] = 0;
				}
				else if (weight[i-1] > w){		// if wi > w
					OPT[i][w] = OPT[i-1][w];
				}
				else{							// otherwise
					OPT[i][w] = Math.max(OPT[i-1][w], value[i-1]+OPT[i-1][w-weight[i-1]]);
				}
			}
		}
		
		for (int[] rows : OPT){	// 표 출력 
			for (int col : rows) {
				System.out.format("%5d", col);
			}
			System.out.println();
		}
		
		// 최대값 출력 
		System.out.println("max : " + OPT[N][W]);

		// 선택된 아이템 번호 출력 
		System.out.print("item :");
		for (int n = N, w = W; n > 0 ; n--){
			if(w >= weight[n-1]){		// 넣을수 있는 공간이 있을때  
				if(OPT[n][w] == (value[n-1] + OPT[n-1][w - weight[n-1]])){ // 현재것 가중치와 그것을 뺀 나머지 가중치값의 합이 같다  
					System.out.print(" " + item[n-1]);						// 해당 아이템 사용 
					w = w- weight[n-1];										// 해당 아이템의 무게 만큼 뺀다.
				}
			}
		}
		
		System.out.println();
	}
}
