class Solution:
    def maxArray(self, nums: List[int]) -> int:
        sz = len(nums)
        maxSumUntilHere = 0
        result = float('-inf')
        for idx in range(sz):
            maxSumUntilHere = max(0, maxSumUntilHere + nums[idx])
            result = max(result, maxSumUntilHere)
        return result
    
    def minArray(self, nums: List[int]) -> int:
        sz = len(nums)
        minSumUntilHere = 0
        result = float('inf')
        for idx in range(sz):
            minSumUntilHere = min(0, minSumUntilHere + nums[idx])
            result = min(minSumUntilHere, result)
        return result
    
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        return max(abs(self.maxArray(nums)), abs(self.minArray(nums)))
