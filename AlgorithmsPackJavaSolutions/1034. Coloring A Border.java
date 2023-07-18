class Solution {
    private final int[] dr = {-1, 0, 1, 0};
    private final int[] dc = {0, 1, 0, -1};

    public int[][] colorBorder(int[][] grid, int row, int col, int color) {
        int rows = grid.length;
        int cols = grid[0].length;
        boolean[][] visited = new boolean[rows][cols];
        dfs(row, col, grid, visited, grid[row][col]);

        colorIn(grid, visited, color);

        return grid;
    }

    private boolean isValid(int r, int c, int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        return r >= 0 && r < rows && c >= 0 && c < cols;
    }

    private void dfs(int r, int c, int[][] grid, boolean[][] visited, int color) {
        if (!isValid(r, c, grid) || visited[r][c] || grid[r][c] != color) {
            return;
        }

        visited[r][c] = true;

        for (int d = 0; d < 4; d++) {
            dfs(r + dr[d], c + dc[d], grid, visited, color);
        }
    }

    private void colorIn(int[][] grid, boolean[][] visited, int color) {
        int rows = grid.length;
        int cols = grid[0].length;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                for (int d = 0; d < 4; d++) {
                    if (!visited[r][c]) {
                        continue;
                    }

                    int nr = dr[d] + r;
                    int nc = dc[d] + c;

                    if (!isValid(nr, nc, grid) || !visited[nr][nc]) {
                        grid[r][c] = color;
                    }
                }
            }
        }
    }
}
