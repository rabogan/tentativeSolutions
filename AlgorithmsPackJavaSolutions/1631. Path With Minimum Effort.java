class Solution {
    private int[] dr = {-1, 0, 1, 0};
    private int[] dc = {0, 1, 0, -1};

    private boolean isValid(int r, int c, int[][] heights) {
        if (r < 0 || r >= heights.length)
            return false;
        if (c < 0 || c >= heights[0].length)
            return false;
        return true;
    }

    private boolean dfs(int r, int c, int[][] heights, boolean[][] visited, int diff) {
        if (r == heights.length - 1 && c == heights[0].length - 1)
            return true;

        visited[r][c] = true;

        for (int d = 0; d < 4; d++) {
            int nr = dr[d] + r;
            int nc = dc[d] + c;
            if (!isValid(nr, nc, heights) || visited[nr][nc] || Math.abs(heights[nr][nc] - heights[r][c]) > diff)
                continue;

            if (dfs(nr, nc, heights, visited, diff))
                return true;
        }
        return false;
    }

    private boolean possible(int[][] heights, int diff) {
        int rows = heights.length;
        int cols = heights[0].length;
        boolean[][] visited = new boolean[rows][cols];

        return dfs(0, 0, heights, visited, diff);
    }

    public int minimumEffortPath(int[][] heights) {
        int start = 0;
        int end = (int) 1e9;
        int ans = end;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (possible(heights, mid)) {
                end = mid - 1;
                ans = mid;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
}
