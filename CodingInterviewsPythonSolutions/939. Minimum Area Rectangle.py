class Solution:
    def minAreaRect(self, points: List[List[int]]) -> int:
        x_to_ys = {}
        sz = len(points)
        ans = float('inf')

        for i in range(sz):
            x = points[i][0]
            y = points[i][1]
            if x not in x_to_ys:
                x_to_ys[x] = set()
            x_to_ys[x].add(y)

        for i in range(sz):
            x1 = points[i][0]
            y1 = points[i][1]

            for j in range(i + 1, sz):
                x2 = points[j][0]
                y2 = points[j][1]

                if x1 == x2 or y1 == y2:
                    continue

                if y2 not in x_to_ys[x1] or y1 not in x_to_ys[x2]:
                    continue

                area = abs(x2 - x1) * abs(y2 - y1)
                ans = min(ans, area)

        if ans == float('inf'):
            return 0
        return ans
