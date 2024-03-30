class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        int[] result = new int[n - k + 1];
        Deque<Integer> dq = new ArrayDeque<>();
        int idx = 0;
        
        for (int i = 0; i < n; i++) {
            if (i >= k && dq.peekFirst() == nums[i - k]) {
                dq.removeFirst();
            }
            
            while (!dq.isEmpty() && nums[i] > dq.peekLast()) {
                dq.removeLast();
            }
            
            dq.addLast(nums[i]);
            
            if (i >= k - 1) {
                result[idx++] = dq.peekFirst();
            }
        }
        return result;
    }
}
