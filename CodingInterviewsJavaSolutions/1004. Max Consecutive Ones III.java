class Solution {
    public int longestOnes(int[] nums, int k) {
        int sz = nums.length;
        int result = 0;
        int start = 0;
        int zeroes = 0;
        for (int end = 0; end < sz; end++) {
            zeroes += nums[end] == 0 ? 1 : 0;
            while (zeroes > k) {
                zeroes -= nums[start] == 0 ? 1 : 0;
                start++;
            }
            result = Math.max(result, end - start + 1);
        }
        return result;
    }
}
