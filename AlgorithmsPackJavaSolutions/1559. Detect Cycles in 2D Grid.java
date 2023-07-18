class Solution {
    private final int[] dr = {-1, 0, 1, 0};
    private final int[] dc = {0, 1, 0, -1};
    private boolean isCycle;

    private boolean isValid(int r, int c, char[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        return r >= 0 && r < rows && c >= 0 && c < cols;
    }

    private void dfs(int r, int c, char[][] grid, boolean[][] visited, char oldColor, int parentRow, int parentCol) {
        if (!isValid(r, c, grid) || grid[r][c] != oldColor || isCycle) {
            return;
        }

        if (visited[r][c]) {
            isCycle = true;
            return;
        }

        visited[r][c] = true;

        for (int d = 0; d < 4; d++) {
            int nr = dr[d] + r;
            int nc = dc[d] + c;

            if (nr == parentRow && nc == parentCol) {
                continue;
            }

            dfs(nr, nc, grid, visited, oldColor, r, c);
        }
    }

    public boolean containsCycle(char[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        boolean[][] visited = new boolean[rows][cols];

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (!visited[r][c]) {
                    isCycle = false;
                    dfs(r, c, grid, visited, grid[r][c], -1, -1);
                    if (isCycle) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
}
