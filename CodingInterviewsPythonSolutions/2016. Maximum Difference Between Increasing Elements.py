class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        result = float('-inf')
        n = len(nums)
        maxSoFar = nums[-1]
        for i in range(n - 2, -1, -1):
            if nums[i] < maxSoFar:
                result = max(result, maxSoFar - nums[i])
            maxSoFar = max(maxSoFar, nums[i])
        if result == float('-inf'):
            return -1
        return result
