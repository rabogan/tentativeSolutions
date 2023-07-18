class Solution {
    static class Edge {
        int to;
        int color;
        
        Edge(int to, int color) {
            this.to = to;
            this.color = color;
        }
    }
    
    static final int OO = (int)1e9;
    static final int RED = 0;
    static final int BLUE = 1;
    
    void addEdge(List<List<Edge>> graph, int from, int to, int color) {
        graph.get(from).add(new Edge(to, color));
    }
    
    public int[] shortestAlternatingPaths(int n, int[][] redEdges, int[][] blueEdges) {
        List<List<Edge>> graph = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            graph.add(new ArrayList<>());
        }
        
        for (int[] r : redEdges) {
            addEdge(graph, r[0], r[1], RED);
        }
        for (int[] b : blueEdges) {
            addEdge(graph, b[0], b[1], BLUE);
        }
        
        return bfs(graph, 0);
    }
    
    public int[] bfs(List<List<Edge>> graph, int node) {
        Queue<Edge> q = new LinkedList<>();
        q.add(new Edge(node, RED));
        q.add(new Edge(node, BLUE));
        
        int nodes = graph.size();
        int[][] visited = new int[nodes][2];
        for (int[] arr : visited) {
            Arrays.fill(arr, OO);
        }
        visited[node][RED] = visited[node][BLUE] = 0;
        
        int[] result = new int[nodes];
        Arrays.fill(result, -1);
        result[node] = 0;
        
        for (int level = 0, sz = q.size(); !q.isEmpty(); level++, sz = q.size()) {
            while (sz-- > 0) {
                Edge edge = q.poll();
                int to = edge.to;
                int color = edge.color;
                
                for (Edge e : graph.get(to)) {
                    if (e.color != color && visited[e.to][e.color] == OO) {
                        q.add(e);
                        visited[e.to][e.color] = level + 1;
                        
                        if (result[e.to] == -1) {
                            result[e.to] = level + 1;
                        }
                    }
                }
            }
        }
        
        return result;
    }
}
