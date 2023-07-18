public class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        Arrays.sort(arr);
        int sz = arr.length;
        
        int minDiff = Integer.MAX_VALUE;
        for (int index = 1; index < sz; index++) {
            minDiff = Math.min(minDiff, arr[index] - arr[index-1]);
        }
        
        List<List<Integer>> result = new ArrayList<>();
        for (int index = 1; index < sz; index++) {
            if (arr[index] - arr[index-1] == minDiff) {
                List<Integer> pair = new ArrayList<>();
                pair.add(arr[index-1]);
                pair.add(arr[index]);
                result.add(pair);
            }
        }
        
        return result;
    }
}
