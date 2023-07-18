class NumMatrix {
    int[][] accum;
    
    public NumMatrix(int[][] matrix) {
        this.accum = matrix;
        rowCumSum();
        colCumSum();
    }
    
    private void rowCumSum() {
        int rows = accum.length;
        int cols = accum[0].length;
        for (int r = 0; r < rows; r++) {
            for (int c = 1; c < cols; c++) {
                accum[r][c] += accum[r][c - 1];
            }
        }
    }
    
    private void colCumSum() {
        int rows = accum.length;
        int cols = accum[0].length;
        for (int c = 0; c < cols; c++) {
            for (int r = 1; r < rows; r++) {
                accum[r][c] += accum[r - 1][c];
            }
        }
    }
    
    private int cellSum(int r, int c) {
        if (r < 0 || c < 0) {
            return 0;
        }
        return accum[r][c];
    }
    
    public int sumRegion(int row1, int col1, int row2, int col2) {
        return (
            cellSum(row2, col2)
            - cellSum(row2, col1 - 1)
            - cellSum(row1 - 1, col2)
            + cellSum(row1 - 1, col1 - 1)
        );
    }
}
