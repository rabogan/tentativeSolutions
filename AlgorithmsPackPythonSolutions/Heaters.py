class Solution:
    def possible(self, houses, heaters, radius):
        j = 0
        sz = len(heaters)
        for i in range(sz):
            leftC = heaters[i] - radius
            rightC = heaters[i] + radius
            
            while j < len(houses) and leftC <= houses[j] <= rightC:
                j += 1
        return j == len(houses)
    
    def findRadius(self, houses, heaters):
        houses.sort()
        heaters.sort()
        
        start = 0
        end = int(1e9)
        ans = end
        
        while start <= end:
            mid = start + (end - start) // 2
            if self.possible(houses, heaters, mid):
                end = mid - 1
                ans = mid
            else:
                start = mid + 1
        return ans
