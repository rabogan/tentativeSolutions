class Solution {
    public List<Integer> killProcess(List<Integer> pid, List<Integer> ppid, int kill) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        buildGraph(graph, pid, ppid);
        return killer(graph, kill);
    }

    private void buildGraph(Map<Integer, List<Integer>> graph, List<Integer> pid, List<Integer> ppid) {
        for (int i = 0; i < pid.size(); i++) {
            addEdge(graph, ppid.get(i), pid.get(i));
        }
    }

    private void addEdge(Map<Integer, List<Integer>> graph, int from, int to) {
        graph.computeIfAbsent(from, k -> new ArrayList<>()).add(to);
    }

    private void dfs(Map<Integer, List<Integer>> graph, int kill, Set<Integer> visited) {
        visited.add(kill);
        if (graph.containsKey(kill)) {
            for (int node : graph.get(kill)) {
                if (!visited.contains(node)) {
                    dfs(graph, node, visited);
                }
            }
        }
    }

    private List<Integer> killer(Map<Integer, List<Integer>> graph, int kill) {
        Set<Integer> visited = new HashSet<>();
        dfs(graph, kill, visited);
        return new ArrayList<>(visited);
    }
}
