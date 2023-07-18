class Solution {
    private static final int MAX = 100 + 1;
    private int[][] memory;
    private int[][] matrix;

    public int minFallingPathSum(int[][] matrix) {
        this.matrix = matrix;
        int rows = matrix.length;
        int cols = matrix[0].length;
        memory = new int[MAX][MAX];
        for (int[] row : memory) {
            Arrays.fill(row, -1);
        }

        int minSum = Integer.MAX_VALUE;
        for (int c = 0; c < cols; c++) {
            minSum = Math.min(minSum, fallingSum(0, c, rows, cols));
        }
        return minSum;
    }

    private int fallingSum(int r, int c, int rows, int cols) {
        if (c < 0 || c >= cols) {
            return Integer.MAX_VALUE / 2;
        }

        if (r == rows - 1) {
            return matrix[r][c];
        }

        if (memory[r][c] != -1) {
            return memory[r][c];
        }

        int dl = fallingSum(r + 1, c - 1, rows, cols);
        int down = fallingSum(r + 1, c, rows, cols);
        int dr = fallingSum(r + 1, c + 1, rows, cols);

        memory[r][c] = matrix[r][c] + Math.min(dl, Math.min(down, dr));
        return memory[r][c];
    }
}
