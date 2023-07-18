class Solution:
    def reductionOperations(self, nums: List[int]) -> int:
        nums.sort(reverse=True)
        operations = 0
        n = len(nums)
        
        for i in range(1, n):
            if nums[i] != nums[i - 1]:
                operations += i
        
        return operations
