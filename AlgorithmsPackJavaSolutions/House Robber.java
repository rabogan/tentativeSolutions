class Solution {
    private int[] memory;
    private int[] nums;

    public int rob(int[] nums) {
        int MAX = 100 + 1;
        memory = new int[MAX];
        this.nums = nums;

        Arrays.fill(memory, -1);

        return theft(0);
    }

    private int theft(int index) {
        if (index >= nums.length) {
            return 0;
        }

        if (memory[index] != -1) {
            return memory[index];
        }

        int leave = theft(index + 1);
        int take = nums[index] + theft(index + 2);

        memory[index] = Math.max(leave, take);
        return memory[index];
    }
}
