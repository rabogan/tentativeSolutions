class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        sz = len(nums)
        nums.sort(reverse=True)
        for i in range(sz - 2):
            if nums[i] < nums[i + 1] + nums[i + 2]:
                return nums[i] + nums[i + 1] + nums[i + 2]
        return 0
