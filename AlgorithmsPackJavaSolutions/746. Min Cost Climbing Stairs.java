class Solution {
    private int[] memory;

    public int minCostClimbingStairs(int[] cost) {
        int MAX = 1000 + 1;
        memory = new int[MAX];
        Arrays.fill(memory, -1);

        return Math.min(climb(cost, 0), climb(cost, 1));
    }

    private int climb(int[] cost, int index) {
        if (index >= cost.length) {
            return 0;
        }

        if (memory[index] != -1) {
            return memory[index];
        }

        int nextStep = cost[index] + climb(cost, index + 1);
        int skipStep = cost[index] + climb(cost, index + 2);

        int result = Math.min(nextStep, skipStep);
        memory[index] = result;
        return result;
    }
}
