class Solution {
    private void addEdge(List<List<Integer>> graph, int from, int to) {
        graph.get(from).add(to);
    }

    public int minimumTime(int n, int[][] relations, int[] time) {
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++)
            graph.add(new ArrayList<>());

        for (int[] rel : relations)
            addEdge(graph, rel[0] - 1, rel[1] - 1);

        int[] incomingEdges = new int[n];
        for (List<Integer> node : graph) {
            for (int j : node) {
                incomingEdges[j]++;
            }
        }

        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (incomingEdges[i] == 0) {
                queue.add(i);
            }
        }

        int[] result = new int[n];
        while (!queue.isEmpty()) {
            int cur = queue.poll();
            result[cur] += time[cur];

            for (int j : graph.get(cur)) {
                if (--incomingEdges[j] == 0) {
                    queue.add(j);
                }
                result[j] = Math.max(result[j], result[cur]);
            }
        }

        int res = 0;
        for (int timeComp : result) {
            res = Math.max(res, timeComp);
        }

        return res;
    }
}
