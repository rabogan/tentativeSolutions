# https://leetcode.com/problems/max-value-of-equation/discuss/1107702/Python-3-or-Heap
class Solution:
    def findMaxValueOfEquation(self, points: List[List[int]], k: int) -> int:
        max_val = float("-inf")
        heap = []
        heapq.heapify(heap)
        for i in range(len(points)):
            while len(heap)>0 and abs(heap[0][1]-points[i][0])>k:
                heapq.heappop(heap)
            if len(heap)>0:
                max_val = max(max_val, -heap[0][0]+points[i][0]+points[i][1])
            heapq.heappush(heap, (-points[i][1]+points[i][0], points[i][0])) 
        return max_val
