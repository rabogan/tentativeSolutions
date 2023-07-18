class Solution {
    private final int[] dr = {-1, 0, 1, 0};
    private final int[] dc = {0, 1, 0, -1};

    private class Cell {
        int r;
        int c;

        public Cell(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }

    private Queue<Cell> q = new LinkedList<>();

    private boolean isValid(int r, int c, int[][] grid) {
        if (r < 0 || r >= grid.length)
            return false;
        if (c < 0 || c >= grid[0].length)
            return false;
        return true;
    }

    private void dfs(int r, int c, int[][] grid) {
        if (!isValid(r, c, grid) || grid[r][c] != 1)
            return;

        grid[r][c] = 2;
        q.offer(new Cell(r, c));

        for (int d = 0; d < 4; d++) {
            dfs(r + dr[d], c + dc[d], grid);
        }
    }

    public int shortestBridge(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;

        for (int r = 0; r < rows && q.isEmpty(); r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    dfs(r, c, grid);
                    break;
                }
            }
        }

        int levels = 0;
        while (!q.isEmpty()) {
            int sz = q.size();
            while (sz-- > 0) {
                int r = q.peek().r;
                int c = q.peek().c;
                q.poll();

                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];
                    if (!isValid(nr, nc, grid) || grid[nr][nc] == 2 || grid[nr][nc] == 3)
                        continue;

                    if (grid[nr][nc] == 1)
                        return levels;

                    grid[nr][nc] = 3;
                    q.offer(new Cell(nr, nc));
                }
            }
            levels++;
        }
        return levels;
    }
}
