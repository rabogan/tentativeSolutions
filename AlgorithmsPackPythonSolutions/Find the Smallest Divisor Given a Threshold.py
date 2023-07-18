class Solution:
    def count(self, nums, index):
        count = 0
        for num in nums:
            count += (num + index - 1) // index
        return count
    
    def smallestDivisor(self, nums, threshold):
        start = 1
        end = max(nums)
        ans = end

        while start <= end:
            mid = start + (end - start) // 2
            if self.count(nums, mid) <= threshold:
                end = mid - 1
                ans = mid
            else:
                start = mid + 1
        return ans
