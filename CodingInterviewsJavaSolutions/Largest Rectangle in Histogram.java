class Solution {
    public int[] next_smaller_element(int[] heights) {
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

    public int[] previous_smaller_element(int[] heights) {
        int[] res = new int[heights.length];
        for (int i = 0; i < heights.length; i++) {
            res[i] = heights[i];
        }
        reverseArray(res);
        res = next_smaller_element(res);
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
        int[] next = next_smaller_element(heights);
        int[] prev = previous_smaller_element(heights);
        int sz = heights.length;
        int maxArea = 0;

        for (int i = 0; i < sz; i++) {
            int left = prev[i] + 1;
            int right = next[i] - 1;
            int area = heights[i] * (right - left + 1);
            maxArea = Math.max(area, maxArea);
        }
        return maxArea;
    }
}
