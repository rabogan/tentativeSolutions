class Solution {
    private static final int MOD = (int) 1e9 + 7;
    private static final int MAX = 30 + 1;
    private static final int MAX_T = 1000 + 1;
    
    public int numRollsToTarget(int n, int k, int target) {
        int[][] memory = new int[MAX][MAX_T];
        for (int[] row : memory) {
            Arrays.fill(row, -1);
        }
        return rolling(0, n, k, target, memory);
    }

    private int rolling(int index, int dice, int rolls, int target, int[][] memory) {
        if (target < 0) {
            return 0;
        }
        if (index == dice && target == 0) {
            return 1;
        }
        if (index == dice || target == 0) {
            return 0;
        }
        if (memory[index][target] != -1) {
            return memory[index][target];
        }

        int ret = 0;
        for (int f = 1; f <= rolls; f++) {
            ret += rolling(index + 1, dice, rolls, target - f, memory);
            ret %= MOD;
        }
        memory[index][target] = ret;
        return ret;
    }
}
