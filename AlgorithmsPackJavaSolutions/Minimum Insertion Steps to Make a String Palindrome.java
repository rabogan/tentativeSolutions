class Solution {
    private int[][] memory;

    public int minInsertions(String s) {
        int MAX = 500 + 1;
        memory = new int[MAX][MAX];
        for (int[] row : memory) {
            Arrays.fill(row, -1);
        }

        return insertion(0, s.length() - 1, s);
    }

    private int insertion(int start, int end, String s) {
        if (start >= end) {
            return 0;
        }

        if (memory[start][end] != -1) {
            return memory[start][end];
        }

        if (s.charAt(start) == s.charAt(end)) {
            return memory[start][end] = insertion(start + 1, end - 1, s);
        }

        int insertLeft = 1 + insertion(start + 1, end, s);
        int insertRight = 1 + insertion(start, end - 1, s);

        memory[start][end] = Math.min(insertRight, insertLeft);
        return memory[start][end];
    }
}
