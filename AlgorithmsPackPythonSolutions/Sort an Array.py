class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        SHIFT = 50000
        n = len(nums)
        for i in range(n):
            nums[i] += SHIFT
        
        maxValue = nums[0]
        for i in range(1, n):
            if nums[i] > maxValue:
                maxValue = nums[i]
        
        count = [0] * (maxValue + 1)
        for i in range(n):
            count[nums[i]] += 1
        
        idx = 0
        for i in range(maxValue + 1):
            for j in range(count[i]):
                nums[idx] = i - SHIFT
                idx += 1
        
        return nums
