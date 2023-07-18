class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        nums.sort()
        sum = 0
        sz = len(nums)
        for i in range(0, sz, 2):
            sum += nums[i]
        return sum
