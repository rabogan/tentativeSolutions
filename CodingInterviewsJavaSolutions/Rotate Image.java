class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;

        for (int r = 0; r < n; r++) {
            for (int c = r + 1; c < n; c++) {
                int temp = matrix[r][c];
                matrix[r][c] = matrix[c][r];
                matrix[c][r] = temp;
            }
        }

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n / 2; c++) {
                int temp = matrix[r][c];
                matrix[r][c] = matrix[r][n - c - 1];
                matrix[r][n - c - 1] = temp;
            }
        }
    }
}
