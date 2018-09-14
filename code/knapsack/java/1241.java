/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dynamic_programming;

/**
 *
 * @author AnhTu
 */
//see more: http://www.geeksforgeeks.org/dynamic-programming-set-10-0-1-knapsack-problem/
/*
Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum 
total value in the knapsack. In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which 
represent values and weights associated with n items respectively. 
Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such 
that sum of the weights of this subset is smaller than or equal to W. 
You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).


*/
//cách giải ngây thơ: dùng đệ quy, time: O(2^n), với n là số lượng đồ vật
//Cách giải tối ưu hơn: dùng quy hoạch động

public class Knapsack {
    static int lookup[][];
    static int max(int a, int b) { 
        return (a > b)? a : b;
    }
    
    //hàm sau trả về giá trị lớn nhất của các item có thể lấy đc từ các items đã cho với điều kiện tổng khối lượng của các item lấy <= W
    //2 integer arrays: val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. Also given an integer W which represents knapsack capacity
    //nghĩa là item thứ k có giá trị là val[k] và khối lượng là wt[k]
    //n là số item còn lại chưa đc lấy
    //gọi tập các item lấy đc thỏa mãn yêu cầu đề bài là subitem (gồm những item sao cho tổng giá trị lớn nhất mà tổng khối lượng của chúng <= W)
    static int knapSack_naive(int W, int wt[], int val[], int n) {      //cách làm ngây thơ nhất: đệ quy và tính toán lại liên tục
        if(n==0 || W==0) return 0;  //trường hợp cơ sở của đệ quy
        
        if(wt[n-1] > W)  return knapSack_naive(W, wt, val, n-1);      //nếu khối lượng của bất kì phần tử nào đó > W thì ko lấy nó nữa
        else {
            int nthItemIncluded = val[n-1] + knapSack_naive(W-wt[n-1], wt, val, n-1);    //trường hợp item thứ n có thuộc subitem 
            int nthItemExcluded = knapSack_naive(W, wt, val, n-1);                       //trường hợp item thứ n ko thuộc subitem 
            return max(nthItemIncluded, nthItemExcluded);
        }
    }
    
    static int knapSack_DP_TopDown(int W, int wt[], int val[], int n) {     //dùng quy hoạch động: cải tiến từ cách trên
        lookup = new int [W+1][n+1];
        return knapSack_TopDown(W, wt, val, n);
    }
    
    static int knapSack_TopDown(int W, int wt[], int val[], int n) {    //chú ý rằng n = wt.length = val.length
        if(lookup[W][n] == 0) {
            if(n==0 || W==0) lookup[W][n] = 0;  //trường hợp cơ sở của đệ quy
            else if(wt[n-1] > W)  lookup[W][n] = knapSack_TopDown(W, wt, val, n-1);      //nếu khối lượng của phần tử thứ n (là phần tử n-1) nào đó lớn hơn trọng lượng còn lại của túi thì ko lấy nó nữa
            else {
                int nthItemIncluded = val[n-1] + knapSack_TopDown(W-wt[n-1], wt, val, n-1);    //trường hợp item thứ n có thuộc subitem 
                int nthItemExcluded = knapSack_TopDown(W, wt, val, n-1);                       //trường hợp item thứ n ko thuộc subitem 
                lookup[W][n] = max(nthItemIncluded, nthItemExcluded);
            }
        }
        
        return lookup[W][n];
    }
    
    static int knapSack_DP_BottomUp(int W, int wt[], int val[], int n) {
        int L[][] = new int[W+1][n+1];      //L[i][j] là giá trị khi lấy các đồ vật trong j đồ vật đầu tiên mà tổng trọng lượng ko vượt quá i, do đó kết quả của bài toán là L[W][n]
        int i,j;
        
        L[0][0] = 0;
        for (i = 0; i <= W; i++) {      //nếu ko có đồ vật nào
            L[i][0] = 0;
        }
        for (i = 0; i <= n; i++) {      //nếu trọng lượng của balo = 0, nghĩa là balo ko thể chứa thêm 1 đồ vật nào nữa
            L[0][i] = 0;
        }
        
        for (i = 1; i <= W; i++) {      //tăng dần trọng lượng của các đồ cần lấy, chỉ số i dùng cho trọng lượng
            for (j = 1; j <= n; j++) {      //với mỗi trọng lượng lấy j đồ đầu tiên, chỉ số j dùng cho giá trị và item thứ j
                if(wt[j-1] > i) L[i][j] = L[i][j-1];        //nếu trọng lượng của item thứ i lớn hơn trọng lượng còn lại của túi thì ko lấy nó nữa
                else {
                    int jthItemIncluded = val[j-1] + L[i-wt[j-1]][j-1];         //nếu item thứ j (là item j-1) có thuộc subitem: khi đó L[i][j] = (giá trị của item thứ j) + (L[i - khối lượng còn lại của túi sau khi thêm item j][j-1])
                    int jthItemExcluded = L[i][j-1];                            //nếu item thứ j (là item j-1) ko thuộc subitem 
                    L[i][j] = max(jthItemIncluded, jthItemExcluded);
                }
            }
        }
        return L[W][n];
    }
    
    //Còn 1 cách nữa: dùng thuật toán nhánh cận...
    
    public static void main(String[] args) {
        int val[] = new int[]{60, 100, 120};
        int wt[] = new int[]{10, 20, 30};
        int  W = 50;
        int n = val.length;
        System.out.println(knapSack_naive(W, wt, val, n));
        //knapSack(50,wt,val,3) = 120 + knapSack_naive(20,wt,val,2) = 120 + 100 + knapSack_naive(0, wt, val, 1) = 120 + 100 + 0 = 220
        
        System.out.println(knapSack_DP_TopDown(W, wt, val, n));
        System.out.println(knapSack_DP_BottomUp(W, wt, val, n));
    }
}