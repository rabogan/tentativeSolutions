class Solution:
    def search(self, nums, target):
        start = 0
        end = len(nums) - 1
        ans = -1
        while start <= end:
            mid = start + (end - start) // 2
            if nums[mid] < target:
                start = mid + 1
            elif nums[mid] > target:
                end = mid - 1
            else:
                ans = mid
                break
        return ans
