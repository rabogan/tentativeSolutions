class Solution {
    public boolean canReach(int[] arr, int start) {
        int n = arr.length;
        if (arr[start] == 0) {
            return true;
        }
        
        Queue<Integer> q = new LinkedList<>();
        q.offer(start);
        boolean[] visited = new boolean[n];
        visited[start] = true;
        
        while (!q.isEmpty()) {
            int cur = q.poll();
            
            if (process(q, visited, arr, cur + arr[cur]) || process(q, visited, arr, cur - arr[cur])) {
                return true;
            }
        }
        
        return false;
    }
    
    private boolean process(Queue<Integer> q, boolean[] visited, int[] arr, int index) {
        if (index < 0 || index >= arr.length || visited[index]) {
            return false;
        }
        
        if (arr[index] == 0) {
            return true;
        }
        
        q.offer(index);
        visited[index] = true;
        return false;
    }
}
