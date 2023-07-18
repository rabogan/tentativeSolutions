class Solution {
    public int triangleNumber(int[] nums) {
        int count = 0;
        Arrays.sort(nums);
        int sz = nums.length;
        for (int i = 0; i < sz - 2; i++) {
            int k = i + 2;
            for (int j = i + 1; j < sz - 1; j++) {
                if (nums[i] == 0) {
                    break;
                }
                while (k < sz && nums[i] + nums[j] > nums[k]) {
                    k++;
                }
                count += k - j - 1;
            }
        }
        return count;
    }
}
