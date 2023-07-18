class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        maxHeap = []
        for idx in range(len(points)):
            loc = [points[idx][0], points[idx][1]]
            dist = loc[0] * loc[0] + loc[1] * loc[1]
            
            if len(maxHeap) < k or dist < -maxHeap[0][0]:
                heapq.heappush(maxHeap, (-dist, loc))
            
            if len(maxHeap) > k:
                heapq.heappop(maxHeap)
        
        result = []
        while maxHeap:
            result.append(heapq.heappop(maxHeap)[1])
        
        return result
