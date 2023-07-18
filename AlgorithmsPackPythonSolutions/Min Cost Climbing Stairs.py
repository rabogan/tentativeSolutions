class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        MAX = 1000 + 1
        memory = [-1] * MAX

        def climb(index):
            if index >= len(cost):
                return 0

            if memory[index] != -1:
                return memory[index]

            next_step = cost[index] + climb(index + 1)
            skip_step = cost[index] + climb(index + 2)

            result = min(next_step, skip_step)
            memory[index] = result
            return result

        return min(climb(0), climb(1))
