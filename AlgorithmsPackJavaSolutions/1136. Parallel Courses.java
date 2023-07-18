class Solution {
    public int minimumSemesters(int n, int[][] relations) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }

        for (int[] rel : relations) {
            addEdge(graph, rel[0] - 1, rel[1] - 1);
        }

        return topSort(graph);
    }

    private void addEdge(List<List<Integer>> graph, int from, int to) {
        graph.get(from).add(to);
    }

    private int topSort(List<List<Integer>> graph) {
        int nodes = graph.size();
        int[] incomingEdges = new int[nodes];
        for (int i = 0; i < nodes; i++) {
            for (int j : graph.get(i)) {
                incomingEdges[j]++;
            }
        }

        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < nodes; i++) {
            if (incomingEdges[i] == 0) {
                q.offer(i);
            }
        }

        int nodesFound = 0;
        int result = 0;
        while (!q.isEmpty()) {
            int sz = q.size();
            while (sz > 0) {
                int cur = q.poll();
                nodesFound++;
                for (int j : graph.get(cur)) {
                    incomingEdges[j]--;
                    if (incomingEdges[j] == 0) {
                        q.offer(j);
                    }
                }
                sz--;
            }
            result++;
        }

        if (nodesFound != nodes) {
            return -1;
        }
        return result;
    }
}
