class Solution {
    private int[][] memory;
    private String word1;
    private String word2;

    public int longestCommonSubsequence(String text1, String text2) {
        int MAX = 1000 + 1;
        memory = new int[MAX][MAX];
        word1 = text1;
        word2 = text2;

        for (int[] row : memory) {
            Arrays.fill(row, -1);
        }

        return LCS(0, 0);
    }

    private int LCS(int i, int j) {
        if (i >= word1.length() || j >= word2.length()) {
            return 0;
        }
        if (memory[i][j] != -1) {
            return memory[i][j];
        }
        if (word1.charAt(i) == word2.charAt(j)) {
            return 1 + LCS(i + 1, j + 1);
        }

        int insertLeft = LCS(i + 1, j);
        int insertRight = LCS(i, j + 1);

        memory[i][j] = Math.max(insertLeft, insertRight);
        return memory[i][j];
    }
}
