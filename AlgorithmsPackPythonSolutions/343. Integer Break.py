class Solution:
    def integerBreak(self, n: int) -> int:
        MAX = 58 + 1
        memory = [-1] * MAX

        def intBreak(num):
            if num == 1:
                return 1

            if memory[num] != -1:
                return memory[num]

            result = num
            for i in range(1, num):
                result = max(result, i * intBreak(num - i))

            memory[num] = result
            return result

        if n == 2 or n == 3:
            return n - 1

        return intBreak(n)
