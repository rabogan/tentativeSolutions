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

    public int[] nextSmallerIndex(int[] heights) {
        int n = heights.length;
        int[] result = new int[n];
        Arrays.fill(result, n);
        Stack<Integer> stk = new Stack<>();

        for (int i = 0; i < n; i++) {
            while (!stk.isEmpty() && heights[i] < heights[stk.peek()]) {
                result[stk.peek()] = i;
                stk.pop();
            }
            stk.push(i);
        }

        return result;
    }

    public int[] previousSmallerIndex(int[] heights) {
        int[] res = Arrays.copyOf(heights, heights.length);
        reverseArray(res);
        res = nextSmallerIndex(res);
        reverseArray(res);
        int n = res.length;
        for (int i = 0; i < n; i++) {
            res[i] = n - res[i] - 1;
        }
        return res;
    }

    private void reverseArray(int[] arr) {
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

    public int largestRectangleArea(int[] heights) {
        int[] next = nextSmallerIndex(heights);
        int[] prev = previousSmallerIndex(heights);
        int n = heights.length;
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int left = prev[i] + 1;
            int right = next[i] - 1;
            int area = heights[i] * (right - left + 1);
            maxArea = Math.max(area, maxArea);
        }
        return maxArea;
    }

    public int largestSubmatrix(int[][] matrix) {
        prefixSumCol(matrix);
        int rows = matrix.length;
        int area = 0;
        for (int r = 0; r < rows; r++) {
            Arrays.sort(matrix[r]);
            area = Math.max(area, largestRectangleArea(matrix[r]));
        }
        return area;
    }
}
