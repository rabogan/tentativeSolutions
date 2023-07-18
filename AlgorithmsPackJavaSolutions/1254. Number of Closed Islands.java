class Solution {
    private final int[] dr = {-1, 0, 1, 0};
    private final int[] dc = {0, 1, 0, -1};

    private boolean touchesBoundary;

    private boolean isValid(int r, int c, int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        return r >= 0 && r < rows && c >= 0 && c < cols;
    }

    private boolean onBoundary(int r, int c, int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        return r == 0 || r == rows - 1 || c == 0 || c == cols - 1;
    }

    private void dfs(int r, int c, int[][] grid, boolean[][] connectedComponentIDS, int ccid) {
        if (!isValid(r, c, grid) || connectedComponentIDS[r][c] || grid[r][c] == 1) {
            return;
        }

        if (onBoundary(r, c, grid)) {
            touchesBoundary = true;
        }

        connectedComponentIDS[r][c] = true;

        for (int d = 0; d < 4; d++) {
            dfs(r + dr[d], c + dc[d], grid, connectedComponentIDS, ccid);
        }
    }

    public int closedIsland(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        boolean[][] connectedComponentIDS = new boolean[rows][cols];
        int ccid = 0;
        int count = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 0 && !connectedComponentIDS[r][c]) {
                    touchesBoundary = false;
                    dfs(r, c, grid, connectedComponentIDS, ++ccid);
                    if (!touchesBoundary) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
}
