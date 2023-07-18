class Solution {
    public int combinationSum4(int[] nums, int target) {
        int MAX = 5000 + 1;
        int[] memory = new int[MAX];
        Arrays.fill(memory, -1);
        memory[0] = 1;
        return combi(nums, target, memory);
    }

    private int combi(int[] nums, int target, int[] memory) {
        if (target < 0) {
            return 0;
        }
        if (target == 0) {
            return 1;
        }
        if (memory[target] != -1) {
            return memory[target];
        }
        int ret = 0;
        for (int value : nums) {
            ret += combi(nums, target - value, memory);
        }
        memory[target] = ret;
        return ret;
    }
}
