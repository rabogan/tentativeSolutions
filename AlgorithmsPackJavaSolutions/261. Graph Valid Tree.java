class Solution {
    private static final int OO = 1_000_000_000;

    private void addEdge(List<List<Integer>> graph, int from, int to) {
        graph.get(from).add(to);
        graph.get(to).add(from);
    }

    private boolean bfsCycle(List<List<Integer>> graph, int node, int[] visited, int[] parent) {
        visited[node] = 0;
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(node);

        for (int level = 0, sz = queue.size(); !queue.isEmpty(); level++, sz = queue.size()) {
            while (sz-- > 0) {
                int cur = queue.poll();

                for (int neighbour : graph.get(cur)) {
                    if (parent[cur] == neighbour)
                        continue;

                    if (visited[neighbour] == OO) {
                        parent[neighbour] = cur;
                        visited[neighbour] = level + 1;
                        queue.offer(neighbour);
                    } else
                        return true;
                }
            }
        }
        return false;
    }

    private boolean hasCycle(List<List<Integer>> graph) {
        int nodes = graph.size();
        int[] visited = new int[nodes];
        Arrays.fill(visited, OO);
        int[] parent = new int[nodes];
        Arrays.fill(parent, -1);

        for (int idx = 0; idx < nodes; idx++) {
            if (visited[idx] == OO && bfsCycle(graph, idx, visited, parent))
                return true;
        }
        return false;
    }

    public boolean validTree(int n, int[][] edges) {
        if (n - 1 != edges.length)
            return false;

        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++)
            graph.add(new ArrayList<>());

        for (int[] e : edges)
            addEdge(graph, e[0], e[1]);

        return !hasCycle(graph);
    }
}
