class Solution:
    def possible(self, coins, row):
        total = (row * (row + 1)) // 2
        return coins >= total
    
    def arrangeCoins(self, n):
        start = 0
        end = n
        ans = 0
        while start <= end:
            row = start + (end - start) // 2
            if self.possible(n, row):
                ans = row
                start = row + 1
            else:
                end = row - 1
        return ans
