class Solution:
    def nthUglyNumber(self, n: int) -> int:
        minHeap = [1]
        heapq.heapify(minHeap)
        
        nth = 0
        mnValue = 0
        
        while minHeap and nth < n:
            nth += 1
            mnValue = heapq.heappop(minHeap)
            
            while minHeap and minHeap[0] == mnValue:
                heapq.heappop(minHeap)
            
            heapq.heappush(minHeap, 2 * mnValue)
            heapq.heappush(minHeap, 3 * mnValue)
            heapq.heappush(minHeap, 5 * mnValue)
        
        return mnValue
