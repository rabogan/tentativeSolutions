class Solution {
    public int maximumDifference(int[] nums) {
        int result = Integer.MIN_VALUE;
        int n = nums.length;
        int maxSoFar = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < maxSoFar) {
                result = Math.max(result, maxSoFar - nums[i]);
            }
            maxSoFar = Math.max(maxSoFar, nums[i]);
        }
        if (result == Integer.MIN_VALUE) {
            return -1;
        }
        return result;
    }
}
