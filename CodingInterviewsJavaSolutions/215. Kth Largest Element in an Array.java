class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        int sz = nums.length;

        for (int i = 0; i < sz; i++) {
            if (minHeap.size() <= k || nums[i] > minHeap.peek()) {
                minHeap.offer(nums[i]);
            }

            if (minHeap.size() > k) {
                minHeap.poll();
            }
        }

        return minHeap.peek();
    }
}
