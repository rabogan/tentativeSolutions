class Solution {
    public int maxPerformance(int n, int[] speed, int[] efficiency, int k) {
        final int MOD = (int) 1e9 + 7;
        int[][] engineers = new int[n][2];
        for (int i = 0; i < n; i++) {
            engineers[i][0] = efficiency[i];
            engineers[i][1] = speed[i];
        }
        
        Arrays.sort(engineers, (a, b) -> b[0] - a[0]);
        
        long speedSum = 0;
        long ans = 0;
        
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        
        for (int i = 0; i < engineers.length; i++) {
            int e = engineers[i][0];
            int s = engineers[i][1];
            
            speedSum += s;
            minHeap.offer(s);
            
            if (minHeap.size() > k) {
                speedSum -= minHeap.poll();
            }
            
            ans = Math.max(ans, speedSum * e);
        }
        
        ans %= MOD;
        return (int) ans;
    }
}
