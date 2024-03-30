class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int n = nums.length;
        int[] res = new int[n];
        Arrays.fill(res, -1);
        Deque<Integer> stack = new ArrayDeque<>();
        
        for (int i = 0; i < 2 * n; i++) {
            while (!stack.isEmpty() && nums[i % n] > nums[stack.peekLast()]) {
                int index = stack.removeLast();
                res[index] = nums[i % n];
            }
            
            if (i < n) {
                stack.addLast(i);
            }
        }
        return res;
    }
}
