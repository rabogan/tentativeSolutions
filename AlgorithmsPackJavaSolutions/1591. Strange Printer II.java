class Solution {
    private List<List<Integer>> graph;
    
    private void addEdge(List<List<Integer>> graph, int from, int to) {
        graph.get(from).add(to);
    }
    
    private List<Integer> topSort(List<List<Integer>> graph) {
        int size = graph.size();
        int[] incomingEdges = new int[size];
        for (List<Integer> neighbors : graph) {
            for (int neighbor : neighbors) {
                incomingEdges[neighbor]++;
            }
        }
        
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < size; i++) {
            if (incomingEdges[i] == 0) {
                queue.add(i);
            }
        }
        
        List<Integer> ordering = new ArrayList<>();
        
        while (!queue.isEmpty()) {
            int i = queue.poll();
            ordering.add(i);
            
            for (int j : graph.get(i)) {
                if (--incomingEdges[j] == 0) {
                    queue.add(j);
                }
            }
        }
        
        if (ordering.size() != size) {
            ordering.clear();
        }
        
        return ordering;
    }
    
    public boolean isPrintable(int[][] targetGrid) {
        int rows = targetGrid.length;
        int cols = targetGrid[0].length;
        int maxColor = 61;
        
        int[] rmax = new int[maxColor];
        int[] rmin = new int[maxColor];
        int[] cmax = new int[maxColor];
        int[] cmin = new int[maxColor];
        
        Arrays.fill(rmax, -1);
        Arrays.fill(rmin, rows);
        Arrays.fill(cmax, -1);
        Arrays.fill(cmin, cols);
        
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                int color = targetGrid[r][c];
                rmax[color] = Math.max(rmax[color], r);
                rmin[color] = Math.min(rmin[color], r);
                cmax[color] = Math.max(cmax[color], c);
                cmin[color] = Math.min(cmin[color], c);
            }
        }
        
        graph = new ArrayList<>();
        for (int i = 0; i < maxColor; i++) {
            graph.add(new ArrayList<>());
        }
        
        for (int color = 0; color < maxColor; color++) {
            for (int r = rmin[color]; r <= rmax[color]; r++) {
                for (int c = cmin[color]; c <= cmax[color]; c++) {
                    if (targetGrid[r][c] != color) {
                        addEdge(graph, color, targetGrid[r][c]);
                    }
                }
            }
        }
        
        return topSort(graph).size() > 0;
    }
}
