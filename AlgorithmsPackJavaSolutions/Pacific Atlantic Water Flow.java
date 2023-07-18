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
    
    private boolean isValid(int r, int c, int[][] heights) {
        if (r < 0 || r >= heights.length)
            return false;
        if (c < 0 || c >= heights[0].length)
            return false;
        return true;
    }
    
    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        List<List<Integer>> result = new ArrayList<>();
        int rows = heights.length;
        if (rows == 0)
            return result;
        int cols = heights[0].length;
        if (cols == 0)
            return result;
        
        boolean[][] atlanticGraph = new boolean[rows][cols];
        boolean[][] pacificGraph = new boolean[rows][cols];
        
        Queue<Cell> atlanticQueue = new LinkedList<>();
        Queue<Cell> pacificQueue = new LinkedList<>();
        
        // Add the border cells to their respective queues and mark them as visited
        for (int r = 0; r < rows; r++) {
            atlanticQueue.offer(new Cell(r, cols - 1));
            pacificQueue.offer(new Cell(r, 0));
            atlanticGraph[r][cols - 1] = true;
            pacificGraph[r][0] = true;
        }
        
        for (int c = 0; c < cols; c++) {
            atlanticQueue.offer(new Cell(rows - 1, c));
            pacificQueue.offer(new Cell(0, c));
            atlanticGraph[rows - 1][c] = true;
            pacificGraph[0][c] = true;
        }
        
        // Perform BFS starting from the border cells to reach all accessible cells
        bfs(heights, atlanticQueue, atlanticGraph);
        bfs(heights, pacificQueue, pacificGraph);
        
        // Check for cells that can flow to both the Pacific and Atlantic oceans
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (atlanticGraph[r][c] && pacificGraph[r][c]) {
                    List<Integer> coordinates = new ArrayList<>();
                    coordinates.add(r);
                    coordinates.add(c);
                    result.add(coordinates);
                }
            }
        }
        
        return result;
    }
    
    private void bfs(int[][] heights, Queue<Cell> queue, boolean[][] visited) {
        while (!queue.isEmpty()) {
            Cell cell = queue.poll();
            int r = cell.r;
            int c = cell.c;
            
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                
                if (isValid(nr, nc, heights) && !visited[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                    visited[nr][nc] = true;
                    queue.offer(new Cell(nr, nc));
                }
            }
        }
    }
}
