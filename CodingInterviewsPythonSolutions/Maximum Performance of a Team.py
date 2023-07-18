class Solution:
    def maxPerformance(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:
        MOD = 10**9 + 7
        engineers = list(zip(efficiency, speed))
        engineers.sort(reverse=True)
        
        speedSum = 0
        ans = 0
        
        mnHeap = []
        
        for i in range(len(engineers)):
            e, s = engineers[i]
            
            speedSum += s
            heapq.heappush(mnHeap, s)
            
            if len(mnHeap) > k:
                speedSum -= heapq.heappop(mnHeap)
            
            ans = max(ans, speedSum * e)
        
        ans %= MOD
        return ans
