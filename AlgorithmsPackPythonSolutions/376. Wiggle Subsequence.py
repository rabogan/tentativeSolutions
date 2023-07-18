class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        up = down = 0
        for idx in range(1, len(nums)):
            if nums[idx-1] < nums[idx]:
                up = down + 1
            elif nums[idx-1] > nums[idx]:
                down = up + 1
        return 1 + max(up, down)
