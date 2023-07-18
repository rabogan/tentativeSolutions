class Solution:
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        MOD = int(1e9) + 7
        MAX = 30 + 1
        MAX_T = 1000 + 1
        memory = [[-1] * MAX_T for _ in range(MAX)]
        
        def rolling(index, target):
            if target < 0:
                return 0
            if index == n and target == 0:
                return 1
            if index == n or target == 0:
                return 0
            if memory[index][target] != -1:
                return memory[index][target]
            
            ret = 0
            for f in range(1, k+1):
                ret += rolling(index+1, target-f)
                ret %= MOD
            memory[index][target] = ret
            return ret
        
        return rolling(0, target)
