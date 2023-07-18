public class Solution {
    public int findUnsortedSubarray(int[] nums) {
        int left = -1;
        int right = -1;
        
        int sz = nums.length;
        int mxValue = nums[0];
        for (int i = 1; i < sz; i++) {
            mxValue = Math.max(nums[i], mxValue);
            if (mxValue != nums[i]) {
                right = i;
            }
        }
        
        int mnValue = nums[sz - 1];
        for (int i = sz - 2; i >= 0; i--) {
            mnValue = Math.min(nums[i], mnValue);
            if (mnValue != nums[i]) {
                left = i;
            }
        }
        
        if (right == -1) {
            return 0;
        }
        
        return right - left + 1;
    }
}
