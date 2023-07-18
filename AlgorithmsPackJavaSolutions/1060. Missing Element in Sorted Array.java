class Solution {
    private int missing(int[] nums, int index) {
        return nums[index] - nums[0] - index;
    }

    private int kth(int[] nums, int k, int index) {
        return nums[index] + k - missing(nums, index);
    }

    public int missingElement(int[] nums, int k) {
        int n = nums.length;

        if (missing(nums, n - 1) < k) {
            return kth(nums, k, n - 1);
        }

        int start = 0;
        int end = n - 1;
        int ans = end;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (missing(nums, mid) < k) {
                start = mid + 1;
            } else {
                end = mid - 1;
                ans = mid;
            }
        }

        return kth(nums, k, ans - 1);
    }
}
