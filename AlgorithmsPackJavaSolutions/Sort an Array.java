public class Solution {
    public int[] sortArray(int[] nums) {
        final int SHIFT = 50000;
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            nums[i] += SHIFT;
        }
        
        int maxValue = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] > maxValue) {
                maxValue = nums[i];
            }
        }
        
        int[] count = new int[maxValue + 1];
        for (int i = 0; i < n; i++) {
            count[nums[i]]++;
        }
        
        int idx = 0;
        for (int i = 0; i <= maxValue; i++) {
            for (int j = 0; j < count[i]; j++, idx++) {
                nums[idx] = i - SHIFT;
            }
        }
        
        return nums;
    }
}
