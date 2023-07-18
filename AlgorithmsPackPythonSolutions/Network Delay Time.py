import heapq
from typing import List

class Solution:
    def dijkstra(self, adjList: List[List[Tuple[int, int]]], nodes: int, src: int) -> List[int]:
        dist = [float('inf')] * nodes
        dist[src] = 0
        visited = [False] * nodes
        pq = [(0, src)]

        while pq:
            minWeight, minIndex = heapq.heappop(pq)
            if visited[minIndex]:
                continue
            
            for to, weight in adjList[minIndex]:
                if dist[to] > dist[minIndex] + weight:
                    dist[to] = dist[minIndex] + weight
                    heapq.heappush(pq, (dist[to], to))
            
            visited[minIndex] = True
        
        return dist

    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        edgeList = [[] for _ in range(n)]
        for u, v, w in times:
            edgeList[u - 1].append((v - 1, w))
        
        res = self.dijkstra(edgeList, n, k - 1)
        result = max(res)
        return result if result < float('inf') else -1
