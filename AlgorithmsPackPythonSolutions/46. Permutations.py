class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        result = []
        self.permute_bt(nums, 0, result)
        return result

    def permute_bt(self, nums, index, result):
        if index == len(nums):
            result.append(nums[:])
            return

        for i in range(index, len(nums)):
            nums[index], nums[i] = nums[i], nums[index]
            self.permute_bt(nums, index + 1, result)
            nums[index], nums[i] = nums[i], nums[index]
