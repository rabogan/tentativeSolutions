import java.util.*;

class Solution {
    public int minimumOperations(int[] nums, int start, int goal) {
        Queue<Integer> q = new LinkedList<>();
        boolean[] visited = new boolean[1001];
        q.offer(start);
        visited[start] = true;
        
        int level = 0;
        while (!q.isEmpty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int x = q.poll();
                for (int num : nums) {
                    if (process(q, visited, x + num, goal) ||
                        process(q, visited, x - num, goal) ||
                        process(q, visited, x ^ num, goal)) {
                        return level + 1;
                    }
                }
            }
            level++;
        }
        
        return -1;
    }
    
    private boolean process(Queue<Integer> q, boolean[] visited, int num, int goal) {
        if (num == goal) {
            return true;
        }
        
        if (0 <= num && num <= 1000 && !visited[num]) {
            q.offer(num);
            visited[num] = true;
        }
        
        return false;
    }
}
