class Solution:
    def triangleNumber(self, nums):
        count = 0
        nums.sort()
        sz = len(nums)
        for i in range(sz - 2):
            k = i + 2
            for j in range(i + 1, sz - 1):
                if nums[i] == 0:
                    break
                while k < sz and nums[i] + nums[j] > nums[k]:
                    k += 1
                count += k - j - 1
        return count
