class Solution {
    public int maxArray(int[] nums) {
        int sz = nums.length;
        int maxSumUntilHere = 0;
        int result = Integer.MIN_VALUE;
        for (int idx = 0; idx < sz; idx++) {
            maxSumUntilHere = Math.max(0, maxSumUntilHere + nums[idx]);
            result = Math.max(result, maxSumUntilHere);
        }
        return result;
    }
    
    public int minArray(int[] nums) {
        int sz = nums.length;
        int minSumUntilHere = 0;
        int result = Integer.MAX_VALUE;
        for (int idx = 0; idx < sz; idx++) {
            minSumUntilHere = Math.min(0, minSumUntilHere + nums[idx]);
            result = Math.min(minSumUntilHere, result);
        }
        return result;
    }
    
    public int maxAbsoluteSum(int[] nums) {
        return Math.max(Math.abs(maxArray(nums)), Math.abs(minArray(nums)));
    }
}
