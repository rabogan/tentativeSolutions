class Solution:
    def possible(self, bloomDay, bouquet, flowers, day):
        adjFlowers = 0
        bouCount = 0
        
        for i in range(len(bloomDay)):
            if bloomDay[i] <= day:
                adjFlowers += 1
                
                if adjFlowers == flowers:
                    bouCount += 1
                    adjFlowers = 0
                if bouCount == bouquet:
                    return True
            else:
                adjFlowers = 0
        return False
    
    def minDays(self, bloomDay, m, k):
        sz = len(bloomDay)
        if m * k > sz:
            return -1
        
        start = 1
        end = int(1e9)
        ans = -1
        
        while start <= end:
            mid = start + (end - start) // 2
            if self.possible(bloomDay, m, k, mid):
                end = mid - 1
                ans = mid
            else:
                start = mid + 1
        return ans
