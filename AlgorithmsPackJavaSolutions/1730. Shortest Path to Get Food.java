class Solution {
    private static final int[] dr = {-1, 0, 1, 0};
    private static final int[] dc = {0, 1, 0, -1};

    private boolean isValid(int r, int c, char[][] grid) {
        if (r < 0 || r >= grid.length)
            return false;
        if (c < 0 || c >= grid[0].length)
            return false;
        return true;
    }

    private int bfs(char[][] grid, boolean[][] visited, Cell start) {
        Queue<Cell> queue = new LinkedList<>();
        queue.offer(start);

        for (int level = 0, sz = queue.size(); !queue.isEmpty(); level++, sz = queue.size()) {
            while (sz-- > 0) {
                int r = queue.peek().r;
                int c = queue.peek().c;
                queue.poll();

                for (int d = 0; d < 4; d++) {
                    int nr = dr[d] + r;
                    int nc = dc[d] + c;
                    if (!isValid(nr, nc, grid) || visited[nr][nc] || grid[nr][nc] == 'X')
                        continue;

                    if (grid[nr][nc] == '#')
                        return level + 1;

                    visited[nr][nc] = true;
                    if (grid[nr][nc] == 'O')
                        queue.offer(new Cell(nr, nc));
                }
            }
        }
        return -1;
    }

    private class Cell {
        int r;
        int c;

        public Cell(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }

    public int getFood(char[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;

        Cell start = null;
        boolean[][] visited = new boolean[rows][cols];

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '*') {
                    start = new Cell(r, c);
                    visited[r][c] = true;
                    break;
                }
            }
        }

        return bfs(grid, visited, start);
    }
}
