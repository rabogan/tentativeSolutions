class Solution:
    def searchRange(self, nums, target):
        first = bisect.bisect_left(nums, target)
        second = bisect.bisect(nums, target)
        
        if first == len(nums) or nums[first] != target:
            return [-1, -1]
        
        return [first, second - 1]
