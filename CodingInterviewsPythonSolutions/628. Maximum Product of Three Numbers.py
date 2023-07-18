class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        minHeap = []
        maxHeap = []
        
        for num in nums:
            heapq.heappush(minHeap, num)
            heapq.heappush(maxHeap, -num)
            
            if len(minHeap) > 3:
                heapq.heappop(minHeap)
            if len(maxHeap) > 2:
                heapq.heappop(maxHeap)
        
        max1, max2, max3 = heapq.nlargest(3, minHeap)
        min1 = heapq.heappop(maxHeap)
        min2 = heapq.heappop(maxHeap)
        
        return max(max1 * max2 * max3, min1 * min2 * max1)
