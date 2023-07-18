class Solution {
    private final int[] dr = {-1, 0, 1, 0};
    private final int[] dc = {0, 1, 0, -1};
    
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        int rows = image.length;
        int cols = image[0].length;
        boolean[][] visited = new boolean[rows][cols];
        
        dfs(sr, sc, image, visited, image[sr][sc], newColor);
        
        return image;
    }
    
    private void dfs(int r, int c, int[][] image, boolean[][] visited, int oldColor, int newColor) {
        if (!isValid(r, c, image) || image[r][c] != oldColor || visited[r][c]) {
            return;
        }
        
        visited[r][c] = true;
        image[r][c] = newColor;
        
        for (int d = 0; d < 4; d++) {
            dfs(r + dr[d], c + dc[d], image, visited, oldColor, newColor);
        }
    }
    
    private boolean isValid(int r, int c, int[][] image) {
        int rows = image.length;
        int cols = image[0].length;
        
        return r >= 0 && r < rows && c >= 0 && c < cols;
    }
}
