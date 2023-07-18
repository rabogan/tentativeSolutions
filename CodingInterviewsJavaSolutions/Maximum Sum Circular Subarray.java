class Solution {
    public int summed(int[] nums) {
        int n = nums.length;
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += nums[i];
        }
        return total;
    }

    public int minArray(int[] nums) {
        int n = nums.length;
        int result = Integer.MAX_VALUE;
        int minSoFar = 0;
        for (int i = 0; i < n; i++) {
            minSoFar = Math.min(minSoFar + nums[i], nums[i]);
            result = Math.min(result, minSoFar);
        }
        return result;
    }

    public int maxArray(int[] nums) {
        int n = nums.length;
        int result = Integer.MIN_VALUE;
        int maxSoFar = 0;
        for (int i = 0; i < n; i++) {
            maxSoFar = Math.max(maxSoFar + nums[i], nums[i]);
            result = Math.max(result, maxSoFar);
        }
        return result;
    }

    public int maxSubarraySumCircular(int[] nums) {
        int n = nums.length;
        int sum = summed(nums);
        int mn = minArray(nums);
        int mx = maxArray(nums);
        if (sum == mn) {
            return mx;
        }
        return Math.max(mx, sum - mn);
    }
}
