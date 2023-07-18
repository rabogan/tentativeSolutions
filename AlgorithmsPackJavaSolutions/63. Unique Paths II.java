class Solution {
    private static final int MAX = 100 + 1;
    private int[][] memory;
    private int[][] grid;

    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        memory = new int[MAX][MAX];
        grid = obstacleGrid;
        for (int[] row : memory) {
            Arrays.fill(row, -1);
        }
        return countWays(0, 0);
    }

    private int countWays(int r, int c) {
        int rows = grid.length;
        int cols = grid[0].length;

        if (r >= rows || c >= cols || grid[r][c] == 1) {
            return 0;
        }

        if (rows - 1 == r && cols - 1 == c) {
            return 1;
        }

        if (memory[r][c] != -1) {
            return memory[r][c];
        }

        int down = countWays(r + 1, c);
        int right = countWays(r, c + 1);

        memory[r][c] = down + right;
        return memory[r][c];
    }
}
