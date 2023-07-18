class Solution:
    def mySqrt(self, x: int) -> int:
        start = 0.0
        end = float(x)
        EPS = 1e-9
        while end - start > EPS:
            mid = start + (end - start) / 2.0
            if mid * mid - x < 0.0:
                start = mid
            else:
                end = mid
        return int(start + EPS)
