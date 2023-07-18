class Solution {
    private boolean possible(int[] bloomDay, int bouquet, int flowers, int day) {
        int adjFlowers = 0;
        int bouCount = 0;
        
        for (int i = 0; i < bloomDay.length; i++) {
            if (bloomDay[i] <= day) {
                adjFlowers++;
                
                if (adjFlowers == flowers) {
                    bouCount++;
                    adjFlowers = 0;
                }
                if (bouCount == bouquet) {
                    return true;
                }
            } else {
                adjFlowers = 0;
            }
        }
        return false;
    }
    
    public int minDays(int[] bloomDay, int m, int k) {
        int sz = bloomDay.length;
        if (m * k > sz) {
            return -1;
        }
        
        int start = 1;
        int end = (int)1e9;
        int ans = -1;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (possible(bloomDay, m, k, mid)) {
                end = mid - 1;
                ans = mid;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
}
