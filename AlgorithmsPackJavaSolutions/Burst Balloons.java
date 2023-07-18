class Solution {
    private int[][] memory;

    public int maxCoins(int[] nums) {
        int MAX = 300 + 2 + 1;
        memory = new int[MAX][MAX];
        for (int[] row : memory) {
            Arrays.fill(row, -1);
        }

        int[] numsArray = new int[nums.length + 2];
        System.arraycopy(nums, 0, numsArray, 1, nums.length);
        numsArray[0] = 1;
        numsArray[numsArray.length - 1] = 1;

        return coins(1, numsArray.length - 2, numsArray);
    }

    private int coins(int start, int end, int[] nums) {
        if (start > end) {
            return 0;
        }

        if (memory[start][end] != -1) {
            return memory[start][end];
        }

        int result = Integer.MIN_VALUE;
        for (int split = start; split <= end; split++) {
            int action = nums[start - 1] * nums[split] * nums[end + 1];
            int sub1 = coins(start, split - 1, nums);
            int sub2 = coins(split + 1, end, nums);
            int total = action + sub1 + sub2;
            result = Math.max(result, total);
        }

        memory[start][end] = result;
        return result;
    }
}
