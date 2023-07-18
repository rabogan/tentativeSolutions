class Solution {
    private int[] memory;

    public int integerBreak(int n) {
        int MAX = 58 + 1;
        memory = new int[MAX];
        Arrays.fill(memory, -1);

        if (n == 2 || n == 3) {
            return n - 1;
        }

        return intBreak(n);
    }

    private int intBreak(int num) {
        if (num == 1) {
            return 1;
        }

        if (memory[num] != -1) {
            return memory[num];
        }

        int result = num;
        for (int i = 1; i < num; i++) {
            result = Math.max(result, i * intBreak(num - i));
        }

        memory[num] = result;
        return result;
    }
}
