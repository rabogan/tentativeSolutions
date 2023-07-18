class Solution {
    public int largestPathValue(String colors, int[][] edges) {
        int nodes = colors.length();
        List<List<Integer>> graph = new ArrayList<>();
        int[] incomingEdges = new int[nodes];
        
        for (int i = 0; i < nodes; i++) {
            graph.add(new ArrayList<>());
        }
        
        for (int[] edge : edges) {
            int from = edge[0];
            int to = edge[1];
            graph.get(from).add(to);
            incomingEdges[to]++;
        }
        
        Queue<Integer> queue = new LinkedList<>();
        int[][] colorValues = new int[nodes][26];
        int nodesFound = 0;
        int result = 0;
        
        for (int i = 0; i < nodes; i++) {
            if (incomingEdges[i] == 0) {
                queue.add(i);
            }
        }
        
        while (!queue.isEmpty()) {
            int cur = queue.poll();
            int color = colors.charAt(cur) - 'a';
            colorValues[cur][color]++;
            nodesFound++;
            result = Math.max(result, colorValues[cur][color]);
            
            for (int neighbor : graph.get(cur)) {
                incomingEdges[neighbor]--;
                if (incomingEdges[neighbor] == 0) {
                    queue.add(neighbor);
                }
                
                for (int col = 0; col < 26; col++) {
                    colorValues[neighbor][col] = Math.max(colorValues[neighbor][col], colorValues[cur][col]);
                }
            }
        }
        
        if (nodesFound != nodes) {
            return -1;
        }
        
        return result;
    }
}
