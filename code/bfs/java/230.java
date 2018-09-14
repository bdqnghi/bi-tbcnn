package acm;

import java.util.PriorityQueue;
import java.util.Queue;

/**
 * 宽度优先遍历
 * @author 14512 on 2018/9/13.
 */
public class BFS {

    public static void main(String[] args) {
        solve();
    }

    /**
     * 问题描述：给定一个NxM得迷宫，通道和墙组成，每一步可以向邻接的上下左右移动。
     * 请求出起点到终点所需的最小步数（从起点一定可以移动到终点）
     * N，M <= 100
     */
    private static final int INF = 10000000;
    private static char[][] maze;
    private static int N, M;

    /**
     * 起点坐标
     */
    private static Point start;
    /**
     * 终点坐标
     */
    private static Point end;
    /**
     * 到各个位置的最短距离数组
     */
    private static int[][] d;
    /**
     * 四个方向上的移动量
     */
    private static int[] dx = new int[]{1, 0, -1, 0};
    private static int[] dy = new int[]{0, 1, 0, -1};
    private static void solve() {
        N = 10;
        M = 10;
        d = new int[N][M];
        maze = new char[][] {
                {'#', 'S', '#', '#', '#', '#', '#', '#', '.', '#'},
                {'.', '.', '.', '.', '.', '.', '#', '.', '.', '#'},
                {'.', '#', '.', '#', '#', '.', '#', '#', '.', '#'},
                {'.', '#', '.', '.', '.', '.', '.', '.', '.', '.'},
                {'#', '#', '.', '#', '#', '.', '#', '#', '#', '#'},
                {'.', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
                {'.', '#', '#', '#', '#', '#', '#', '#', '.', '#'},
                {'.', '.', '.', '.', '#', '.', '.', '.', '.', '.'},
                {'.', '#', '#', '#', '#', '.', '#', '#', '#', '.'},
                {'.', '.', '.', '.', '#', '.', '.', '.', 'G', '#'}
        };
        int count = bfs();
        System.out.println(count);
    }

    /**
     * 求从起点到终点的最短距离
     * 如果无法到达时INF
     * @return
     */
    private static int bfs() {
        Queue<Point> queue = new PriorityQueue<>();
        //所有的位置都初始化为INF
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (maze[i][j] == 'S') {
                    start = new Point(i, j);
                }
                if (maze[i][j] == 'G') {
                    end = new Point(i, j);
                }
                d[i][j] = INF;
            }
        }
        //起点入队，这一地点位置的距离为0
        queue.add(start);
        d[start.x][start.y] = 0;

        while (!queue.isEmpty()) {
            Point point = queue.poll();
            if (point.equals(end)) {
                break;
            }

            for (int i = 0; i < 4; i++) {
                int nx = point.x + dx[i];
                int ny = point.y + dy[i];

                //判断是否可以移动以及是否已经访问过
                if (0 <= nx && nx < N && 0 <= ny && ny < M
                        && maze[nx][ny] != '#'
                        && d[nx][ny] == INF) {
                    //可以访问，入队
                    queue.add(new Point(nx, ny));
                    //该位置的距离为point的距离+1
                    d[nx][ny] = d[point.x][point.y] + 1;
                }
            }
        }
        return d[end.x][end.y];
    }

    private static class Point implements Comparable {
        int x;
        int y;
        Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        boolean equals(Point that) {
            return this.x == that.x && this.y == that.y;
        }

        @Override
        public int compareTo(Object o) {
            return 0;
        }
    }
}
