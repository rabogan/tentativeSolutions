class Solution:
    def fastPow(self, x, n):
        if n == 0:
            return 1.0
        result = self.fastPow(x, n // 2)
        result *= result
        if n % 2 != 0:
            result *= x
        return result

    def myPow(self, x: float, n: int) -> float:
        N = n
        if N < 0:
            x = 1 / x
            N = -N
        return self.fastPow(x, N)
