public class Solution {
    public int largestSumAfterKNegations(int[] nums, int k) {
        Arrays.sort(nums);
        
        int sum = 0;
        int mnValue = Integer.MAX_VALUE;
        for (int i = 0; i < nums.length; i++) {
            if (k > 0 && nums[i] < 0) {
                k--;
                nums[i] *= -1;
            }
            mnValue = Math.min(mnValue, nums[i]);
            sum += nums[i];
        }
        
        if (k % 2 == 1) {
            sum -= 2 * mnValue;
        }
        
        return sum;
    }
}
