class Solution {
    static final long MOD = (long) 1e9 + 7;
    static final long OO = ((long) 1e9 + 10) * 200;

    static class Edge implements Comparable<Edge> {
        int to;
        long weight;

        public Edge(int to, long weight) {
            this.to = to;
            this.weight = weight;
        }

        @Override
        public int compareTo(Edge e) {
            return Long.compare(weight, e.weight);
        }
    }

    public int dijkstra(List<List<Edge>> adjList, int nodes, int source, int target) {
        List<Long> dist = new ArrayList<>(nodes);
        List<Long> pathCount = new ArrayList<>(nodes);
        for (int i = 0; i < nodes; i++) {
            dist.add(OO);
            pathCount.add(0L);
        }

        dist.set(source, 0L);
        pathCount.set(source, 1L);

        PriorityQueue<Edge> pq = new PriorityQueue<>();
        pq.add(new Edge(source, 0));

        while (!pq.isEmpty()) {
            Edge minEdge = pq.poll();
            int minIndex = minEdge.to;

            if (minEdge.weight > dist.get(minIndex))
                continue;

            for (Edge edge : adjList.get(minIndex)) {
                int to = edge.to;
                long weight = edge.weight;

                if (dist.get(to) > dist.get(minIndex) + weight) {
                    dist.set(to, dist.get(minIndex) + weight);
                    pathCount.set(to, pathCount.get(minIndex));
                    pq.add(new Edge(to, dist.get(to)));
                } else if (dist.get(to) == dist.get(minIndex) + weight) {
                    pathCount.set(to, (pathCount.get(to) + pathCount.get(minIndex)) % MOD);
                }
            }
        }

        return (int) (pathCount.get(target) % MOD);
    }

    public int countPaths(int n, int[][] roads) {
        List<List<Edge>> adjList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adjList.add(new ArrayList<>());
        }

        for (int[] road : roads) {
            int from = road[0];
            int to = road[1];
            int cost = road[2];

            adjList.get(from).add(new Edge(to, cost));
            adjList.get(to).add(new Edge(from, cost));
        }

        return dijkstra(adjList, n, 0, n - 1);
    }
}
