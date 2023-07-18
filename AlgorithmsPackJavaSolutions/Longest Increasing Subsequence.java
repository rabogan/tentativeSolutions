class Solution {
    private List<Integer> numList;
    private int[] memory;
    
    public int lengthOfLIS(int[] nums) {
        int MAX = 2500 + 1;
        memory = new int[MAX];
        Arrays.fill(memory, -1);
        
        numList = new ArrayList<>();
        for (int num : nums) {
            numList.add(num);
        }
        numList.add(0, Integer.MIN_VALUE);
        
        return LIS(0) - 1;
    }
    
    private int LIS(int index) {
        if (index == numList.size()) {
            return 0;
        }
        if (memory[index] != -1) {
            return memory[index];
        }
        
        int ret = 0;
        for (int j = index + 1; j < numList.size(); j++) {
            if (numList.get(index) < numList.get(j)) {
                ret = Math.max(ret, LIS(j));
            }
        }
        ret += 1;
        memory[index] = ret;
        return ret;
    }
}
