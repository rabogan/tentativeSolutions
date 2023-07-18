class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        left = -1
        right = -1
        
        sz = len(nums)
        mxValue = nums[0]
        for i in range(1, sz):
            mxValue = max(nums[i], mxValue)
            if mxValue != nums[i]:
                right = i
        
        mnValue = nums[sz - 1]
        for i in range(sz - 2, -1, -1):
            mnValue = min(nums[i], mnValue)
            if mnValue != nums[i]:
                left = i
        
        if right == -1:
            return 0
        
        return right - left + 1
