class Solution {
    public int change(int amount, int[] coins) {
        int MAX_T = 5000 + 1;
        int[] memory = new int[MAX_T];
        memory[0] = 1;
        int sz = coins.length;
        for (int idx = 0; idx < sz; idx++) {
            for (int target = 0; target <= amount; target++) {
                if (target - coins[idx] >= 0) {
                    memory[target] += memory[target - coins[idx]];
                }
            }
        }
        return memory[amount];
    }
}
