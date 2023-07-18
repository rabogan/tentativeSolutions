class Solution {
    public int minAreaRect(int[][] points) {
        HashMap<Integer, HashSet<Integer>> xToYs = new HashMap<>();
        int sz = points.length;
        int ans = Integer.MAX_VALUE;

        for (int i = 0; i < sz; i++) {
            int x = points[i][0];
            int y = points[i][1];
            xToYs.computeIfAbsent(x, k -> new HashSet<>()).add(y);
        }

        for (int i = 0; i < sz; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];

            for (int j = i + 1; j < sz; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];

                if (x1 == x2 || y1 == y2)
                    continue;

                if (!xToYs.get(x1).contains(y2) || !xToYs.get(x2).contains(y1))
                    continue;

                int area = Math.abs(x2 - x1) * Math.abs(y2 - y1);
                ans = Math.min(ans, area);
            }
        }

        if (ans == Integer.MAX_VALUE)
            return 0;
        return ans;
    }
}
