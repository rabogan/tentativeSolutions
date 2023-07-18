class Solution {
    private int collected = 0;
    
    private void addKeysFromBoxes(int[] status, int[][] keys, int[] boxes) {
        for (int box : boxes) {
            for (int key : keys[box]) {
                status[key] = 1;
            }
        }
    }
    
    private void openBoxes(Queue<Integer> q, boolean[] visited, int[] status, int[] candies, int[] boxes) {
        for (int box : boxes) {
            if (!visited[box] && status[box] == 1) {
                q.offer(box);
                visited[box] = true;
                collected += candies[box];
            }
        }
    }
    
    public int maxCandies(int[] status, int[] candies, int[][] keys, int[][] containedBoxes, int[] initialBoxes) {
        Queue<Integer> q = new LinkedList<>();
        boolean[] visited = new boolean[status.length];
        
        addKeysFromBoxes(status, keys, initialBoxes);
        openBoxes(q, visited, status, candies, initialBoxes);
        
        while (!q.isEmpty()) {
            int box = q.poll();
            addKeysFromBoxes(status, keys, containedBoxes[box]);
            openBoxes(q, visited, status, candies, containedBoxes[box]);
        }
        
        return collected;
    }
}
