class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        n = len(nums)
        nums.sort()
        for i in range(1, n - 1, 2):
            nums[i], nums[i + 1] = nums[i + 1], nums[i]
