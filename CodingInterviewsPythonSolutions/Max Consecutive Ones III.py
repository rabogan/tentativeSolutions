class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        sz = len(nums)
        result = 0
        start = 0
        zeroes = 0
        for end in range(sz):
            zeroes += nums[end] == 0
            while zeroes > k:
                zeroes -= nums[start] == 0
                start += 1
            result = max(result, end - start + 1)
        return result
