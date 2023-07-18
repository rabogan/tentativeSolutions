class Solution {
    private void addEdge(List<List<Integer>> graph, int from, int to) {
        graph.get(from).add(to);
        graph.get(to).add(from);
    }

    private void dfs(List<List<Integer>> graph, int node, boolean[] visited, List<Integer> ccNodes) {
        visited[node] = true;
        ccNodes.add(node);

        for (int neighbour : graph.get(node)) {
            if (!visited[neighbour]) {
                dfs(graph, neighbour, visited, ccNodes);
            }
        }
    }

    public String smallestStringWithSwaps(String s, List<List<Integer>> pairs) {
        int nodes = s.length();
        List<List<Integer>> graph = new ArrayList<>(nodes);

        for (int i = 0; i < nodes; i++) {
            graph.add(new ArrayList<>());
        }

        for (List<Integer> pair : pairs) {
            addEdge(graph, pair.get(0), pair.get(1));
        }

        boolean[] visited = new boolean[nodes];

        for (int i = 0; i < nodes; i++) {
            if (!visited[i]) {
                List<Integer> ccNodes = new ArrayList<>();
                dfs(graph, i, visited, ccNodes);

                List<Character> ccLetters = new ArrayList<>();
                for (int node : ccNodes) {
                    ccLetters.add(s.charAt(node));
                }

                ccLetters.sort(null);
                ccNodes.sort(null);

                for (int j = 0; j < ccNodes.size(); j++) {
                    int node = ccNodes.get(j);
                    char letter = ccLetters.get(j);
                    s = s.substring(0, node) + letter + s.substring(node + 1);
                }
            }
        }

        return s;
    }
}
