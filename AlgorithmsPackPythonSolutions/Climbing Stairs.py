class Solution:
    def climbStairs(self, n: int) -> int:
        memory = [0] * (n + 1)
        memory[0] = 1
        memory[1] = 1
        for i in range(2, n + 1):
            memory[i] = memory[i - 1] + memory[i - 2]
        return memory[n]
