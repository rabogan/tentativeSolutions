class Solution:
    def missing(self, nums, index):
        return nums[index] - nums[0] - index

    def kth(self, nums, k, index):
        return nums[index] + k - self.missing(nums, index)

    def missingElement(self, nums, k):
        n = len(nums)

        if self.missing(nums, n - 1) < k:
            return self.kth(nums, k, n - 1)

        start = 0
        end = n - 1
        ans = end

        while start <= end:
            mid = start + (end - start) // 2
            if self.missing(nums, mid) < k:
                start = mid + 1
            else:
                end = mid - 1
                ans = mid

        return self.kth(nums, k, ans - 1)
