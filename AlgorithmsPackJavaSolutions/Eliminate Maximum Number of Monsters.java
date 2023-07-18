public class Solution {
    public int eliminateMaximum(int[] dist, int[] speed) {
        int sz = dist.length;
        int[] arrivalTime = new int[sz];
        for (int i = 0; i < sz; i++) {
            arrivalTime[i] = (dist[i] + speed[i] - 1) / speed[i];
        }
        Arrays.sort(arrivalTime);
        
        int monster = 0;
        for (int i = 0; i < arrivalTime.length && i < arrivalTime[monster]; i++) {
            monster++;
        }
        
        return monster;
    }
}
