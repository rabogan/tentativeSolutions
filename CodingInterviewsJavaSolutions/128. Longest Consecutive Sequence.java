class Solution {
    public int longestConsecutive(int[] nums) {
        HashSet<Integer> mySet = new HashSet<>();
        for (int num : nums) {
            mySet.add(num);
        }
        
        int answer = 0;
        for (int val : nums) {
            if (mySet.contains(val - 1)) {
                continue;
            }
            
            int length = 0;
            while (mySet.contains(val)) {
                length++;
                val++;
            }
            
            answer = Math.max(answer, length);
        }
        
        return answer;
    }
}
