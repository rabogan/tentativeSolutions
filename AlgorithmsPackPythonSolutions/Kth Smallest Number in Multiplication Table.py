class Solution:
    def counting(self, rows, cols, div):
        count = 0
        for r in range(1, rows + 1):
            count += min(div // r, cols)
        return count

    def findKthNumber(self, m: int, n: int, k: int) -> int:
        start = 1
        end = m * n
        ans = end

        while start <= end:
            mid = start + (end - start) // 2
            if self.counting(m, n, mid) < k:
                start = mid + 1
            else:
                end = mid - 1
                ans = mid

        return ans
