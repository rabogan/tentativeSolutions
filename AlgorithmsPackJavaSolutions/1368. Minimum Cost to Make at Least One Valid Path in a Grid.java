class Solution {
    int[] dr = {0, 0, 1, -1};
    int[] dc = {1, -1, 0, 0};

    boolean isValid(int r, int c, int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        return r >= 0 && r < rows && c >= 0 && c < cols;
    }

    public int minCost(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        int[][] dist = new int[rows][cols];

        for (int i = 0; i < rows; i++) {
            Arrays.fill(dist[i], Integer.MAX_VALUE);
        }

        dist[0][0] = 0;
        Deque<int[]> deque = new ArrayDeque<>();
        deque.offer(new int[]{0, 0});

        while (!deque.isEmpty()) {
            int[] current = deque.pollFirst();
            int r = current[0];
            int c = current[1];

            for (int d = 0; d < 4; d++) {
                int nr = dr[d] + r;
                int nc = dc[d] + c;
                int edgeWeight = (d != (grid[r][c] - 1)) ? 1 : 0;
                int nDist = dist[r][c] + edgeWeight;

                if (!isValid(nr, nc, grid) || nDist >= dist[nr][nc])
                    continue;

                dist[nr][nc] = nDist;

                if (edgeWeight == 0)
                    deque.offerFirst(new int[]{nr, nc});
                else
                    deque.offerLast(new int[]{nr, nc});
            }
        }

        return dist[rows - 1][cols - 1];
    }
}