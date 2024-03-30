class Solution {
    public int[][] multiply(int[][] mat1, int[][] mat2) {
        int rows = mat1.length;
        int cols = mat2[0].length;
        int common = mat1[0].length;
        
        int[][] result = new int[rows][cols];
        
        for (int r = 0; r < rows; r++) {
            for (int k = 0; k < common; k++) {
                if (mat1[r][k] != 0) {
                    for (int c = 0; c < cols; c++) {
                        result[r][c] += mat1[r][k] * mat2[k][c];
                    }
                }
            }
        }
        return result;
    }
}
