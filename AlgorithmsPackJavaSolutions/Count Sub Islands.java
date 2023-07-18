class Solution {
    private boolean isIsland;
    private final int[] dr = {-1, 0, 1, 0};
    private final int[] dc = {0, 1, 0, -1};
    
    public int countSubIslands(int[][] grid1, int[][] grid2) {
        int rows = grid2.length;
        int cols = grid2[0].length;
        int count = 0;
        
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid2[r][c] == 1) {
                    isIsland = true;
                    dfs(r, c, grid1, grid2);
                    count += isIsland ? 1 : 0;
                }
            }
        }
        
        return count;
    }
    
    private void dfs(int r, int c, int[][] grid1, int[][] grid2) {
        if (!isValid(r, c, grid2) || grid2[r][c] == 0) {
            return;
        }
        
        if (grid1[r][c] == 0) {
            isIsland = false;
            return;
        }
        
        grid2[r][c] = 0;
        
        for (int d = 0; d < 4; d++) {
            dfs(r + dr[d], c + dc[d], grid1, grid2);
        }
    }
    
    private boolean isValid(int r, int c, int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        
        return r >= 0 && r < rows && c >= 0 && c < cols;
    }
}
