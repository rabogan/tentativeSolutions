class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int rows = matrix.length;
        int cols = matrix[0].length;

        int startRow = 0;
        int startCol = cols - 1;

        while (startRow < rows && startCol >= 0) {
            if (matrix[startRow][startCol] == target) {
                return true;
            } else if (matrix[startRow][startCol] < target) {
                startRow++;
            } else {
                startCol--;
            }
        }
        return false;
    }
}
