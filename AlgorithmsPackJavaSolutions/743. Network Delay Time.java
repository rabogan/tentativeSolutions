class Solution {
    class Edge implements Comparable<Edge> {
        int to;
        int weight;

        public Edge(int to, int weight) {
            this.to = to;
            this.weight = weight;
        }

        @Override
        public int compareTo(Edge e) {
            return Integer.compare(weight, e.weight);
        }
    }

    public int[] dijkstra(List<List<Edge>> adjList, int nodes, int src) {
        int[] dist = new int[nodes];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[src] = 0;
        boolean[] visited = new boolean[nodes];
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        pq.add(new Edge(src, 0));

        while (!pq.isEmpty()) {
            Edge minEdge = pq.poll();
            int minIndex = minEdge.to;
            if (visited[minIndex]) {
                continue;
            }

            for (Edge edge : adjList.get(minIndex)) {
                int to = edge.to;
                int weight = edge.weight;
                if (dist[to] > dist[minIndex] + weight) {
                    dist[to] = dist[minIndex] + weight;
                    pq.add(new Edge(to, dist[to]));
                }
            }
            visited[minIndex] = true;
        }
        return dist;
    }

    public int networkDelayTime(int[][] times, int n, int k) {
        List<List<Edge>> edgeList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            edgeList.add(new ArrayList<>());
        }
        for (int[] t : times) {
            edgeList.get(t[0] - 1).add(new Edge(t[1] - 1, t[2]));
        }

        int[] res = dijkstra(edgeList, n, k - 1);
        int result = Arrays.stream(res).max().getAsInt();
        return result < Integer.MAX_VALUE ? result : -1;
    }
}
