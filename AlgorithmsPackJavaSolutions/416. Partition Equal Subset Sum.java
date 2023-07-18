class Solution {
    private int[][] memory;
    private int[] numms;

    public boolean canPartition(int[] nums) {
        int MAX = 200 + 1;
        int MAX_T = 100 * 200 + 1;
        memory = new int[MAX][MAX_T];
        numms = nums;

        for (int[] row : memory) {
            Arrays.fill(row, -1);
        }

        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        if (totalSum % 2 == 1) {
            return false;
        }

        return canPart(nums, totalSum / 2);
    }

    private boolean partition(int index, int target) {
        if (target < 0) {
            return false;
        }

        if (target == 0) {
            return true;
        }

        if (index >= numms.length) {
            return false;
        }

        if (memory[index][target] != -1) {
            return memory[index][target] == 1;
        }

        if (partition(index + 1, target)) {
            memory[index][target] = 1;
            return true;
        }

        memory[index][target] = partition(index + 1, target - numms[index]) ? 1 : 0;
        return memory[index][target] == 1;
    }

    private boolean canPart(int[] nums, int target) {
        numms = nums;
        return partition(0, target);
    }
}
