class Solution {
    private int[][] memory;
    private String str1;
    private String str2;

    public int minDistance(String word1, String word2) {
        int MAX = 500 + 1;
        memory = new int[MAX][MAX];
        str1 = word1;
        str2 = word2;

        for (int[] row : memory) {
            Arrays.fill(row, -1);
        }

        return levenshtein(str1.length() - 1, str2.length() - 1);
    }

    private int levenshtein(int i, int j) {
        if (i == -1 || j == -1) {
            return Math.max(i, j) + 1;
        }

        if (memory[i][j] != -1) {
            return memory[i][j];
        }

        if (str1.charAt(i) == str2.charAt(j)) {
            return levenshtein(i - 1, j - 1);
        }

        int change = 1 + levenshtein(i - 1, j - 1);
        int delete_ = 1 + levenshtein(i - 1, j);
        int insert = 1 + levenshtein(i, j - 1);

        memory[i][j] = Math.min(change, Math.min(delete_, insert));
        return memory[i][j];
    }
}
