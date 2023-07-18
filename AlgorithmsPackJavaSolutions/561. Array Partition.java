public class Solution {
    public int arrayPairSum(int[] nums) {
        Arrays.sort(nums);
        int sum = 0;
        int sz = nums.length;
        for (int i = 0; i < sz; i += 2) {
            sum += nums[i];
        }
        return sum;
    }
}
