class Solution {
    public int maxSubArray(int[] nums) {
        int sz = nums.length;
        int result = Integer.MIN_VALUE;
        int maxSoFar = 0;
        
        for (int i = 0; i < sz; i++) {
            maxSoFar = Math.max(nums[i], nums[i] + maxSoFar);
            result = Math.max(result, maxSoFar);
        }
        
        return result;
    }
}
