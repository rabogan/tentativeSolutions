class Solution {
    private int[] memory;

    public int numDecodings(String s) {
        int MAX = 100 + 1;
        memory = new int[MAX];
        Arrays.fill(memory, -1);

        return countWays(s, 0);
    }

    private boolean can2Digit(String str, int index) {
        if (index + 1 >= str.length())
            return false;
        if (str.charAt(index) == '1')
            return true;
        return str.charAt(index) == '2' && str.charAt(index + 1) <= '6';
    }

    private int countWays(String str, int index) {
        if (index == str.length())
            return 1;
        if (str.charAt(index) == '0')
            return 0;

        if (memory[index] != -1)
            return memory[index];

        int result = countWays(str, index + 1);
        if (can2Digit(str, index))
            result += countWays(str, index + 2);

        memory[index] = result;
        return result;
    }
}
