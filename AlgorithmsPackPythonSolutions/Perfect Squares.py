class Solution:
    def numSquares(self, n: int) -> int:
        MAX = 10000 + 1
        memory = [-1] * MAX

        def perfect(num):
            if num <= 0:
                return 0

            if memory[num] != -1:
                return memory[num]

            result = num
            i = 1
            while i * i <= num:
                result = min(result, 1 + perfect(num - i * i))
                i += 1

            memory[num] = result
            return result

        return perfect(n)
