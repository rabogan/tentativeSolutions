class Solution {
    class Edge {
        int to;
        boolean built;

        public Edge(int to, boolean built) {
            this.to = to;
            this.built = built;
        }
    }

    private void addUndirectedEdge(List<List<Edge>> graph, int from, int to) {
        graph.get(from).add(new Edge(to, true));
        graph.get(to).add(new Edge(from, false));
    }

    private void dfs(List<List<Edge>> graph, int node, boolean[] visited, int[] reorientCount) {
        visited[node] = true;

        for (Edge e : graph.get(node)) {
            if (!visited[e.to]) {
                reorientCount[0] += e.built ? 1 : 0;
                dfs(graph, e.to, visited, reorientCount);
            }
        }
    }

    public int minReorder(int n, int[][] connections) {
        int[] reorientCount = new int[1];
        List<List<Edge>> graph = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }

        boolean[] visited = new boolean[n];

        for (int[] edge : connections) {
            addUndirectedEdge(graph, edge[0], edge[1]);
        }

        dfs(graph, 0, visited, reorientCount);

        return reorientCount[0];
    }
}
