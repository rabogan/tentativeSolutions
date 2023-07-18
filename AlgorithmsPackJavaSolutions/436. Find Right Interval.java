import java.util.TreeMap;

class Solution {
    public int[] findRightInterval(int[][] intervals) {
        TreeMap<Integer, Integer> startsToIndices = new TreeMap<>();
        int n = intervals.length;
        
        for (int i = 0; i < n; i++) {
            startsToIndices.put(intervals[i][0], i);
        }
        
        int[] result = new int[n];
        for (int i = 0; i < n; i++) {
            int start = intervals[i][1];
            
            if (startsToIndices.containsKey(start)) {
                result[i] = startsToIndices.get(start);
            } else {
                Integer higherKey = startsToIndices.ceilingKey(start);
                if (higherKey != null) {
                    result[i] = startsToIndices.get(higherKey);
                } else {
                    result[i] = -1;
                }
            }
        }
        
        return result;
    }
}
