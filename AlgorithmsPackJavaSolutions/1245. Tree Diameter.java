class Solution {
    private int mxDia = 0;

    private void addEdge(List<List<Integer>> graph, int from, int to) {
        graph.get(from).add(to);
        graph.get(to).add(from);
    }

    private int dfs(List<List<Integer>> graph, int node, int parent) {
        int mxH1 = 0;
        int mxH2 = 0;
        for (int cur : graph.get(node)) {
            if (cur == parent) {
                continue;
            }
            int h = dfs(graph, cur, node);
            if (h > mxH1) {
                mxH2 = mxH1;
                mxH1 = h;
            } else if (h > mxH2) {
                mxH2 = h;
            }
        }
        mxDia = Math.max(mxDia, mxH1 + mxH2);
        return 1 + mxH1;
    }

    public int treeDiameter(int[][] edges) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < edges.length + 1; i++) {
            graph.add(new ArrayList<>());
        }
        for (int[] e : edges) {
            addEdge(graph, e[0], e[1]);
        }
        mxDia = 0;
        dfs(graph, 0, -1);
        return mxDia;
    }
}
