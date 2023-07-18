class Solution {
    private static final long MOD = 1_000_000_007;
    private static final long OO = 2_000_000_010;
    private static final int MAX_N = 20_001;
    private final long[] memory = new long[MAX_N];

    private static class Edge {
        int to;
        long weight;

        Edge(int to, long weight) {
            this.to = to;
            this.weight = weight;
        }
    }

    private long[] dijkstra(List<List<Edge>> adjList, int n, int source) {
        long[] dist = new long[n];
        boolean[] vis = new boolean[n];
        Arrays.fill(dist, OO);
        Arrays.fill(vis, false);
        dist[source] = 0;

        PriorityQueue<Edge> q = new PriorityQueue<>(Comparator.comparingLong(e -> e.weight));
        q.add(new Edge(source, 0));

        while (!q.isEmpty()) {
            Edge minEdge = q.poll();
            int minIndex = minEdge.to;

            if (vis[minIndex]) {
                continue;
            }

            for (Edge edge : adjList.get(minIndex)) {
                int to = edge.to;
                long weight = edge.weight;

                if (dist[to] > dist[minIndex] + weight) {
                    dist[to] = dist[minIndex] + weight;
                    q.add(new Edge(to, dist[to]));
                }
            }

            vis[minIndex] = true;
        }

        return dist;
    }

    private long countPaths(int source, int target, List<List<Edge>> adjList, long[] dist) {
        if (source == target) {
            return 1;
        }

        if (memory[source] != -1) {
            return memory[source];
        }

        long ret = 0;
        for (Edge edge : adjList.get(source)) {
            if (dist[source] > dist[edge.to]) {
                ret += countPaths(edge.to, target, adjList, dist);
                ret %= MOD;
            }
        }

        memory[source] = ret;
        return ret;
    }

    public int countRestrictedPaths(int n, int[][] roads) {
        List<List<Edge>> adjList = new ArrayList<>(n);

        for (int i = 0; i < n; ++i) {
            adjList.add(new ArrayList<>());
        }

        for (int[] road : roads) {
            int from = road[0] - 1;
            int to = road[1] - 1;
            int cost = road[2];
            adjList.get(from).add(new Edge(to, cost));
            adjList.get(to).add(new Edge(from, cost));
        }

        long[] dist = dijkstra(adjList, n, n - 1);
        Arrays.fill(memory, -1);

        return (int) countPaths(0, n - 1, adjList, dist);
    }
}
