class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        sz = len(nums)
        result = float('-inf')
        maxSoFar = 0
        
        for i in range(sz):
            maxSoFar = max(nums[i], nums[i] + maxSoFar)
            result = max(result, maxSoFar)
        
        return result
