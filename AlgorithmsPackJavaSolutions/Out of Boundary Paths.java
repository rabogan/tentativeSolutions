class Solution {
    private static final int MAX = 50 + 1;
    private int rows;
    private int cols;
    private int moves;
    private int[][][] memory;
    private static final int MOD = (int) 1e9 + 7;

    public int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        rows = m;
        cols = n;
        moves = maxMove;
        memory = new int[MAX][MAX][MAX];
        for (int[][] row : memory) {
            for (int[] col : row) {
                Arrays.fill(col, -1);
            }
        }
        return count(startRow, startColumn, 0);
    }

    private int count(int r, int c, int move) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            return 1;
        }

        if (move == moves) {
            return 0;
        }

        if (memory[r][c][move] != -1) {
            return memory[r][c][move];
        }

        int ret = count(r + 1, c, move + 1);
        ret += count(r - 1, c, move + 1);
        ret %= MOD;

        ret += count(r, c + 1, move + 1);
        ret %= MOD;

        ret += count(r, c - 1, move + 1);
        ret %= MOD;

        memory[r][c][move] = ret;
        return ret;
    }
}
