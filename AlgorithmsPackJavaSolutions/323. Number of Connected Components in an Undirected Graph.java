class Solution {
    public int countComponents(int n, int[][] edges) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }

        for (int[] edge : edges) {
            addEdge(graph, edge[0], edge[1]);
        }

        return countThem(graph);
    }

    private void addEdge(List<List<Integer>> graph, int fromNode, int toNode) {
        graph.get(fromNode).add(toNode);
        graph.get(toNode).add(fromNode);
    }

    private void dfs(List<List<Integer>> graph, int node, boolean[] visited) {
        visited[node] = true;

        for (int cur : graph.get(node)) {
            if (!visited[cur]) {
                dfs(graph, cur, visited);
            }
        }
    }

    private int countThem(List<List<Integer>> graph) {
        int count = 0;
        int nodes = graph.size();
        boolean[] visited = new boolean[nodes];

        for (int i = 0; i < nodes; i++) {
            if (!visited[i]) {
                dfs(graph, i, visited);
                count++;
            }
        }

        return count;
    }
}
