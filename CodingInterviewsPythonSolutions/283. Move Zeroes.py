class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        start = 0
        end = 0
        sz = len(nums)
        
        while end < sz:
            if nums[end] != 0:
                nums[start], nums[end] = nums[end], nums[start]
                start += 1
            end += 1
