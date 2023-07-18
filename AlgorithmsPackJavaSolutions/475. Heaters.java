class Solution {
    private boolean possible(int[] houses, int[] heaters, int radius) {
        int j = 0;
        int sz = heaters.length;
        for (int i = 0; i < sz; i++) {
            int leftC = heaters[i] - radius;
            int rightC = heaters[i] + radius;
            
            while (j < houses.length && leftC <= houses[j] && houses[j] <= rightC) {
                j++;
            }
        }
        return j == houses.length;
    }
    
    public int findRadius(int[] houses, int[] heaters) {
        Arrays.sort(houses);
        Arrays.sort(heaters);
        
        int start = 0;
        int end = (int)1e9;
        int ans = end;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (possible(houses, heaters, mid)) {
                end = mid - 1;
                ans = mid;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
}
