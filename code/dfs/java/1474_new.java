import java.util.*;

public class SolutionDFS {
    int m = 0;
    int n = 0;
    char[][] board;

    public void solve(char[][] board) {
        if (board.length == 0 || board[0].length == 0) return;
        m = board.length;
        n = board[0].length;
        this.board = board;

        for (int i = 0; i < n; i++) {
            // Top row
            dfsMark(i, 0);

            // Bottom row
            dfsMark(i, m - 1);
        }

        for (int i = 0; i < m; i++) {
            // Left column
            dfsMark(0, i);

            // Right column
            dfsMark(n - 1, i);
        }

        // Mark
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }

                if (board[i][j] == '+') {
                    board[i][j] = 'O';
                }
            }
        }
    }

    public void dfsMark(int x, int y) {
        if (x < 0 || x >= n || y < 0 || y >= m || board[y][x] != 'O') return;
        board[y][x] = '+';

        // Right
        dfsMark(x + 1, y);

        // Down
        dfsMark(x, y + 1);

        // Left
        dfsMark(x - 1, y);

        // Up
        dfsMark(x, y - 1);
    }
}
