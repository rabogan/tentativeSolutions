class Solution {
    private int count(int[] nums, int index) {
        int count = 0;
        for (int num : nums) {
            count += (num + index - 1) / index;
        }
        return count;
    }
    
    public int smallestDivisor(int[] nums, int threshold) {
        int start = 1;
        int end = Arrays.stream(nums).max().getAsInt();
        int ans = end;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (count(nums, mid) <= threshold) {
                end = mid - 1;
                ans = mid;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
}
