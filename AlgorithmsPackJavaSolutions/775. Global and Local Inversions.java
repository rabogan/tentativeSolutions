class Solution {
    private int[] tmp;

    private long mergeSortedSubarrays(int[] nums, int start, int mid, int end) {
        long globalConversions = 0;
        for (int i = start, j = mid + 1, k = start; k <= end; k++) {
            if (i > mid)
                tmp[k] = nums[j++];
            else if (j > end)
                tmp[k] = nums[i++];
            else if (nums[i] < nums[j])
                tmp[k] = nums[i++];
            else {
                tmp[k] = nums[j++];
                globalConversions += mid - i + 1;
            }
        }
        System.arraycopy(tmp, start, nums, start, end - start + 1);
        return globalConversions;
    }

    private long mergeSort(int[] nums, int start, int end) {
        if (start == end)
            return 0;
        int mid = start + (end - start) / 2;
        long conv = mergeSort(nums, start, mid);
        conv += mergeSort(nums, mid + 1, end);
        conv += mergeSortedSubarrays(nums, start, mid, end);
        return conv;
    }

    public boolean isIdealPermutation(int[] nums) {
        int n = nums.length;
        tmp = new int[n];

        long localInversions = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1])
                localInversions++;
        }

        long globalInversions = mergeSort(nums, 0, n - 1);
        return globalInversions == localInversions;
    }
}
