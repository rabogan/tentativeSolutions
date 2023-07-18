class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        minHeap = []
        sz = len(nums)

        for i in range(sz):
            if len(minHeap) <= k or nums[i] > minHeap[0]:
                heapq.heappush(minHeap, nums[i])

            if len(minHeap) > k:
                heapq.heappop(minHeap)

        return minHeap[0]
