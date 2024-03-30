class Solution {
    private int[] dr = {-1, 0, 1, 0};
    private int[] dc = {0, 1, 0, -1};
    
    private class Cell {
        int r;
        int c;
        
        public Cell(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }
    
    private boolean isValid(int r, int c, int[][] rooms) {
        if (r < 0 || r >= rooms.length)
            return false;
        if (c < 0 || c >= rooms[0].length)
            return false;
        return true;
    }
    
    public void wallsAndGates(int[][] rooms) {
        int rows = rooms.length;
        if (rows == 0)
            return;
        int cols = rooms[0].length;
        if (cols == 0)
            return;
        
        Queue<Cell> queue = new LinkedList<>();
        boolean[][] visited = new boolean[rows][cols];

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (rooms[r][c] == 0) {
                    queue.offer(new Cell(r, c));
                    visited[r][c] = true;
                }
            }
        }

        while (!queue.isEmpty()) {
            Cell cell = queue.poll();
            int r = cell.r;
            int c = cell.c;
            int distance = rooms[r][c] + 1;
            
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                
                if (isValid(nr, nc, rooms) && !visited[nr][nc] && rooms[nr][nc] == Integer.MAX_VALUE) {
                    rooms[nr][nc] = distance;
                    queue.offer(new Cell(nr, nc));
                    visited[nr][nc] = true;
                }
            }
        }
    }
}
