class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        result = []
        filter_set = set()
        self.backtrack(nums, 0, filter_set)
        for permutation in filter_set:
            result.append(list(permutation))
        return result

    def backtrack(self, nums, index, filter_set):
        if index == len(nums):
            filter_set.add(tuple(nums))
            return

        for i in range(index, len(nums)):
            nums[index], nums[i] = nums[i], nums[index]
            self.backtrack(nums, index + 1, filter_set)
            nums[index], nums[i] = nums[i], nums[index]
