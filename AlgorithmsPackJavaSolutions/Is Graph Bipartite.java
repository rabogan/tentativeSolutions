class Solution {
    private boolean colorConflict;

    private void dfs(int[][] graph, int node, int[] colors, int assignCol) {
        if (colors[node] == 0) {
            colors[node] = assignCol;
        } else {
            if (colors[node] != assignCol) {
                colorConflict = true;
            }
            return;
        }

        for (int cur : graph[node]) {
            dfs(graph, cur, colors, 3 - assignCol);
        }
    }

    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        int[] colors = new int[n];

        for (int i = 0; i < n; i++) {
            if (colors[i] == 0) {
                dfs(graph, i, colors, 1);
                if (colorConflict) {
                    return false;
                }
            }
        }

        return true;
    }
}
