class Solution:
    def largestSumAfterKNegations(self, nums: List[int], k: int) -> int:
        nums.sort()
        
        sum = 0
        mnValue = float('inf')
        for i in range(len(nums)):
            if k > 0 and nums[i] < 0:
                k -= 1
                nums[i] *= -1
            mnValue = min(mnValue, nums[i])
            sum += nums[i]
        
        if k % 2 == 1:
            sum -= 2 * mnValue
        
        return sum
