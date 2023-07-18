class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        events.sort(reverse=True)
        minHeap = []
        attended = 0
        day = 0
        while events or minHeap:
            if not minHeap:
                day = events[-1][0]
            while events and events[-1][0] <= day:
                heapq.heappush(minHeap, events.pop()[1])
            heapq.heappop(minHeap)
            attended += 1
            day += 1
            while minHeap and minHeap[0] < day:
                heapq.heappop(minHeap)
        return attended
