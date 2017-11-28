package main.algorithm;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Queue;

/**
 * 幅優先探索の使用例を辞書的に格納したクラス 
 *
 */
public class BFS {

    static int H = 100, W = 100;
    /**
     * 幅優先探索を使用したフィールドの捜査
     * 2次元配列のマップを捜査する。
     * 
     */
    static char[][] field = new char[H + 2][W + 2];
    static {
        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= W; j++) {
                field[i][j]  = Math.random() >= 0.3 ? '.' : '-' ;
            }
        }
        field[1][1] = 'S';
        field[H][W] = '.';
    }

    static int[] dx = {1, 0, 0, -1};
    static int[] dy = {0, 1, -1, 0};

    /**
     * 幅優先探索を使用して、ゴール地点までの最短経路での歩数をカウントする。
     * ゴールに到達できない場合は、impossibleを出力する。
     */
    private static void bfsSearch() {
        boolean[][] used = new boolean[H + 2][W + 2];
        Deque<Integer> xQue = new ArrayDeque<Integer>();
        Deque<Integer> yQue = new ArrayDeque<Integer>();

        xQue.add(1);
        yQue.add(1);

        Deque<Integer> nextXQue = new ArrayDeque<Integer>();
        Deque<Integer> nextYQue = new ArrayDeque<Integer>();
        boolean isPossible = false;
        int index = 0;
        for (; index < H * W; index++) {
            while(!xQue.isEmpty()) {
                int x = xQue.poll();
                int y = yQue.poll();
                if (x == H && y == W) {
                    isPossible = true;
                    System.out.println(index);
                    break;
                }
                for (int i = 0; i < 4; i++) {
                    int mx = x + dx[i];
                    int my = y + dy[i];
                    if (field[my][mx] == '.' && !used[my][mx]) {
                        used[my][mx] = true;
                        nextXQue.add(mx);
                        nextYQue.add(my);
                    }
                }
            }
            Deque<Integer> tmpXQue = xQue;
            Deque<Integer> tmpYQue = yQue;
            xQue = nextXQue;
            yQue = nextYQue;
            nextXQue = tmpXQue;
            nextYQue = tmpYQue;
        }
        if (!isPossible) System.out.println("impossible");
    }

    private static void printMap() {
        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= W; j++) {
                System.out.print(field[i][j]); 
            }
            System.out.println();
        }
    }

    /**
     * 幅優先探索を使用して、ゴール地点までの最短経路での歩数をカウントする。
     * ゴールに到達できない場合は、impossibleを出力する。
     * Queueのインスタンスを再構築しないようにした改良版
     * インスタンスを再構築しないことで実装の簡便化、処理の高速化を図る。
     * 但し、最短経路の歩数をカウントするために、歩数を切り替えるための変数(indexSwithX,indexSwithY)を設けているため、
     * 実装の複雑度はそこまで変わらないかも？
     */
    private static void bfsSearchNeo() {
        boolean[][] used = new boolean[H + 2][W + 2];
        Queue<Integer> xQue = new ArrayDeque<Integer>();
        Queue<Integer> yQue = new ArrayDeque<Integer>();

        xQue.add(1);
        yQue.add(1);

        boolean isPossible = false;
        int index = -1;
        int indexSwithX = 1;
        int indexSwithY = 1;
        while(!xQue.isEmpty()) {
            int x = xQue.poll();
            int y = yQue.poll();
            
            if(x == indexSwithX && y == indexSwithY) {
                index++;
                indexSwithX = 0;
                indexSwithY = 0;
            }
            
            if (x == H && y == W) {
                isPossible = true;
                System.out.println(index);
                break;
            }
            for (int i = 0; i < 4; i++) {
                int mx = x + dx[i];
                int my = y + dy[i];
                if (field[my][mx] == '.' && !used[my][mx]) {
                    used[my][mx] = true;
                    xQue.add(mx);
                    yQue.add(my);
                    if(indexSwithX == 0) {
                        indexSwithX = mx;
                        indexSwithY = my;
                    }
                }
            }
        }
        if (!isPossible) System.out.println("impossible");
    }

    public static void main(String[] args) {
//        printMap(); 
        long time = System.currentTimeMillis();
        bfsSearch();
        long a = System.currentTimeMillis() - time;
        bfsSearchNeo();
        long b = System.currentTimeMillis() - time - a;
        
        System.out.printf("%s %s \r\n", a , b);
    }
}
