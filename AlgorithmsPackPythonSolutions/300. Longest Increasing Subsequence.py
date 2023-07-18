class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        MAX = 2500 + 1
        memory = [-1] * MAX
        
        def LIS(index):
            if index >= len(nums):
                return 0
            if memory[index] != -1:
                return memory[index]
            ret = 0
            for next_index in range(index, len(nums)):
                if nums[index] < nums[next_index]:
                    ret = max(ret, LIS(next_index))
            ret += 1
            memory[index] = ret
            return ret
        
        nums = [float('-inf')] + nums
        return LIS(0) - 1
