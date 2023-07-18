public class Solution {
    public int largestPerimeter(int[] nums) {
        int sz = nums.length;
        Arrays.sort(nums);
        for (int i = sz - 1; i >= 2; i--) {
            if (nums[i - 2] + nums[i - 1] > nums[i]) {
                return nums[i - 2] + nums[i - 1] + nums[i];
            }
        }
        return 0;
    }
}
