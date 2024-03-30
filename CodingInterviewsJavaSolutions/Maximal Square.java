class Solution {
    public void prefixSumCol(int[][] matrix) {
        int rows = matrix.length;
        int cols = matrix[0].length;

        for (int c = 0; c < cols; c++) {
            for (int r = 1; r < rows; r++) {
                matrix[r][c] += (matrix[r][c] != 0) ? matrix[r - 1][c] : 0;
            }
        }
    }

    public int[] NSI(int[] heights) {
        int n = heights.length;
        int[] result = new int[n];
        Arrays.fill(result, n);
        Deque<Integer> stk = new ArrayDeque<>();

        for (int i = 0; i < n; i++) {
            while (!stk.isEmpty() && heights[i] < heights[stk.peek()]) {
                result[stk.peek()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        return result;
    }

    public int[] PSI(int[] heights) {
        int n = heights.length;
        int[] result = heights.clone();
        reverse(result);
        result = NSI(result);
        reverse(result);

        for (int i = 0; i < n; i++) {
            result[i] = n - result[i] - 1;
        }

        return result;
    }

    private void reverse(int[] arr) {
        int left = 0;
        int right = arr.length - 1;

        while (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }

    public int squareArea(int[] heights) {
        int n = heights.length;
        int[] prev = PSI(heights);
        int[] next = NSI(heights);
        int area = 0;

        for (int i = 0; i < n; i++) {
            int left = prev[i] + 1;
            int right = next[i] - 1;
            int side = Math.min(heights[i], (right - left + 1));
            area = Math.max(area, side * side);
        }

        return area;
    }

    public int maximalSquare(char[][] matrix) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        int[][] matrix2 = new int[rows][cols];

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                matrix2[r][c] = matrix[r][c] - '0';
            }
        }

        prefixSumCol(matrix2);

        int area = 0;

        for (int r = 0; r < rows; r++) {
            area = Math.max(area, squareArea(matrix2[r]));
        }
        return area;
    }
}
