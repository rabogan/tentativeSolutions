class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        sz = len(nums)
        expectedSum = sz * (sz - 1) // 2
        actualSum = sum(nums)
        
        if actualSum == expectedSum:
            return sz
        
        return expectedSum - actualSum + sz
