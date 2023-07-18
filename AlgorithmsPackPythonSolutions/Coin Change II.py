class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        MAX_T = 5000 + 1
        memory = [0] * MAX_T
        memory[0] = 1
        sz = len(coins)
        for idx in range(sz):
            for target in range(amount + 1):
                if target - coins[idx] >= 0:
                    memory[target] += memory[target - coins[idx]]
        return memory[amount]
