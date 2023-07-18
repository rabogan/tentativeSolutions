class Solution:
    def minimumMountainRemovals(self, nums: List[int]) -> int:
        MAX = 1000 + 1
        LISmem = [-1] * MAX
        LDSmem = [-1] * MAX
        nums_ = nums

        def LIS(index):
            if index == -1:
                return 0
            if LISmem[index] != -1:
                return LISmem[index]
            ret = 0
            for prev in range(index - 1, -1, -1):
                if nums_[prev] < nums_[index]:
                    ret = max(ret, LIS(prev))
            ret += 1
            LISmem[index] = ret
            return ret

        def LDS(index):
            if index >= len(nums_):
                return 0
            if LDSmem[index] != -1:
                return LDSmem[index]
            ret = 0
            for next in range(index + 1, len(nums_)):
                if nums_[index] > nums_[next]:
                    ret = max(ret, LDS(next))
            ret += 1
            LDSmem[index] = ret
            return ret

        n = len(nums_)
        mountains = 0
        for i in range(n):
            if LIS(i) == 1 or LDS(i) == 1:
                continue
            cur = LIS(i) + LDS(i) - 1
            mountains = max(mountains, cur)
        return n - mountains
