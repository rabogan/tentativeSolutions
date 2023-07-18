/*
This TLEs on LeetCode...
*/

class Solution:
    def isIdealPermutation(self, nums: List[int]) -> bool:
        tmp = nums.copy()

        def merge_sorted_subarrays(nums, start, mid, end):
            global_conversions = 0
            i, j, k = start, mid + 1, start
            while k <= end:
                if i > mid:
                    tmp[k] = nums[j]
                    j += 1
                elif j > end:
                    tmp[k] = nums[i]
                    i += 1
                elif nums[i] < nums[j]:
                    tmp[k] = nums[i]
                    i += 1
                else:
                    tmp[k] = nums[j]
                    j += 1
                    global_conversions += mid - i + 1
                k += 1
            for i in range(start, end + 1):
                nums[i] = tmp[i]
            return global_conversions

        def merge_sort(nums, start, end):
            if start == end:
                return 0
            mid = start + (end - start) // 2
            conv = merge_sort(nums, start, mid)
            conv += merge_sort(nums, mid + 1, end)
            conv += merge_sorted_subarrays(nums, start, mid, end)
            return conv

        n = len(nums)
        tmp = nums.copy()

        local_inversions = sum(nums[i] > nums[i + 1] for i in range(n - 1))
        global_inversions = merge_sort(nums, 0, n - 1)
        return global_inversions == local_inversions