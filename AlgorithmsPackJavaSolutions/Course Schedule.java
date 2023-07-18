class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < numCourses; i++) {
            graph.add(new ArrayList<>());
        }

        for (int[] p : prerequisites) {
            addEdge(graph, p[1], p[0]);
        }

        boolean[] visited = new boolean[numCourses];
        return topSort(graph, visited);
    }

    private void addEdge(List<List<Integer>> graph, int from, int to) {
        graph.get(from).add(to);
    }

    private boolean topSort(List<List<Integer>> graph, boolean[] visited) {
        int nodes = graph.size();
        int[] indegree = new int[nodes];
        for (int i = 0; i < nodes; i++) {
            for (int j : graph.get(i)) {
                indegree[j]++;
            }
        }

        Queue<Integer> ready = new LinkedList<>();
        for (int i = 0; i < nodes; i++) {
            if (indegree[i] == 0) {
                ready.offer(i);
            }
        }

        List<Integer> result = new ArrayList<>();
        while (!ready.isEmpty()) {
            int cur = ready.poll();
            result.add(cur);
            if (visited[cur]) {
                return false;
            }
            visited[cur] = true;
            for (int node : graph.get(cur)) {
                if (visited[node]) {
                    return false;
                }
                if (--indegree[node] == 0) {
                    ready.offer(node);
                }
            }
        }

        return result.size() == nodes;
    }
}
