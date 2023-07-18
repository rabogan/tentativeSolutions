class Solution:
    def rob(self, nums: List[int]) -> int:
        MAX = 100 + 1
        memory = [-1] * MAX
        nums_ = nums

        def theft(index):
            if index >= len(nums_):
                return 0

            if memory[index] != -1:
                return memory[index]

            leave = theft(index + 1)
            take = nums_[index] + theft(index + 2)

            memory[index] = max(leave, take)
            return memory[index]

        return theft(0)
