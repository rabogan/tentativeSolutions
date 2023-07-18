class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        MAX = 5000 + 1
        memory = [-1] * MAX
        memory[0] = 1
        def combi(target):
            if target < 0:
                return 0
            if target == 0:
                return 1
            if memory[target] != -1:
                return memory[target]
            ret = 0
            for value in nums:
                ret += combi(target - value)
            memory[target] = ret
            return ret
        return combi(target)
