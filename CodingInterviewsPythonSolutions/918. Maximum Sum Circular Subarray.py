class Solution:
    def summed(self, nums: List[int]) -> int:
        n = len(nums)
        total = 0
        for i in range(n):
            total += nums[i]
        return total

    def minArray(self, nums: List[int]) -> int:
        n = len(nums)
        result = float('inf')
        minSoFar = 0
        for i in range(n):
            minSoFar = min(minSoFar + nums[i], nums[i])
            result = min(result, minSoFar)
        return result

    def maxArray(self, nums: List[int]) -> int:
        n = len(nums)
        result = float('-inf')
        maxSoFar = 0
        for i in range(n):
            maxSoFar = max(maxSoFar + nums[i], nums[i])
            result = max(result, maxSoFar)
        return result

    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        n = len(nums)
        total = self.summed(nums)
        mn = self.minArray(nums)
        mx = self.maxArray(nums)
        if total == mn:
            return mx
        return max(mx, total - mn)
