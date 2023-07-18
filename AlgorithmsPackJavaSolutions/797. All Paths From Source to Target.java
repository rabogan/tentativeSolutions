class Solution {
    private void backtrack(int[][] graph, int start, int end, List<List<Integer>> ans, List<Integer> cur) {
        if (start == end) {
            ans.add(new ArrayList<>(cur));
            return;
        }

        for (int i = 0; i < graph[start].length; i++) {
            cur.add(graph[start][i]);
            backtrack(graph, graph[start][i], end, ans, cur);
            cur.remove(cur.size() - 1);
        }
    }

    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> cur = new ArrayList<>();
        cur.add(0);
        backtrack(graph, 0, graph.length - 1, ans, cur);
        return ans;
    }
}
