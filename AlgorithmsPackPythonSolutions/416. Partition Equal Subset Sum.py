class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        MAX = 200 + 1
        MAX_T = 100 * 200 + 1
        memory = [[-1] * MAX_T for _ in range(MAX)]
        numms = nums

        def partition(index, target):
            if target < 0:
                return False

            if target == 0:
                return True

            if index >= len(numms):
                return False

            if memory[index][target] != -1:
                return memory[index][target]

            if partition(index + 1, target):
                return True

            memory[index][target] = partition(index + 1, target - numms[index])
            return memory[index][target]

        def canPart(nums, target):
            nonlocal numms
            numms = nums
            return partition(0, target)

        total_sum = sum(nums)
        if total_sum % 2 == 1:
            return False

        return canPart(nums, total_sum // 2)
