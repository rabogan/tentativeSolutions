class Solution {
    private void addEdge(Map<Integer, List<Integer>> graph, int from, int to) {
        graph.computeIfAbsent(from, key -> new ArrayList<>()).add(to);
        graph.computeIfAbsent(to, key -> new ArrayList<>()).add(from);
    }

    private void dfs(Map<Integer, List<Integer>> graph, int node, Set<Integer> visited, List<Integer> result) {
        visited.add(node);
        result.add(node);

        for (int neighbour : graph.get(node)) {
            if (!visited.contains(neighbour)) {
                dfs(graph, neighbour, visited, result);
            }
        }
    }

    public int[] restoreArray(int[][] adjacentPairs) {
        Map<Integer, List<Integer>> graph = new HashMap<>();

        for (int[] pair : adjacentPairs) {
            addEdge(graph, pair[0], pair[1]);
        }

        Set<Integer> visited = new HashSet<>();
        List<Integer> result = new ArrayList<>();

        for (Map.Entry<Integer, List<Integer>> entry : graph.entrySet()) {
            if (entry.getValue().size() == 1) {
                dfs(graph, entry.getKey(), visited, result);
                break;
            }
        }

        int[] restoredArray = new int[result.size()];
        for (int i = 0; i < result.size(); i++) {
            restoredArray[i] = result.get(i);
        }

        return restoredArray;
    }
}
