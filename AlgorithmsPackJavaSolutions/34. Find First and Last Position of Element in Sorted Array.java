class Solution {
    public int[] searchRange(int[] nums, int target) {
        int first = binarySearch(nums, target, true);
        int second = binarySearch(nums, target, false) - 1;
        
        if (first == nums.length || nums[first] != target) {
            return new int[]{-1, -1};
        }
        
        return new int[]{first, second};
    }
    
    private int binarySearch(int[] nums, int target, boolean leftMost) {
        int start = 0;
        int end = nums.length;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] > target || (leftMost && nums[mid] == target)) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
}
