class Solution {
    private int[] memory;

    public int numSquares(int n) {
        int MAX = 10000 + 1;
        memory = new int[MAX];
        Arrays.fill(memory, -1);

        return perfect(n);
    }

    private int perfect(int num) {
        if (num <= 0) {
            return 0;
        }

        if (memory[num] != -1) {
            return memory[num];
        }

        int result = num;
        int i = 1;
        while (i * i <= num) {
            result = Math.min(result, 1 + perfect(num - i * i));
            i++;
        }

        memory[num] = result;
        return result;
    }
}
