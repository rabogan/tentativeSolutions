public class Solution {
    private int[][] memory;
    private String str;
    
    public String longestPalindrome(String s) {
        str = s;
        int n = s.length();
        memory = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                memory[i][j] = -1;
            }
        }
        
        int length = 0;
        int startIndex = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int len = j - i + 1;
                if (isValid(i, j) && len > length) {
                    length = len;
                    startIndex = i;
                }
            }
        }
        return s.substring(startIndex, startIndex + length);
    }
    
    private boolean isValid(int i, int j) {
        if (i >= j) {
            return true;
        }
        
        if (memory[i][j] != -1) {
            return memory[i][j] == 1;
        }
        
        if (str.charAt(i) == str.charAt(j)) {
            boolean ret = isValid(i + 1, j - 1);
            memory[i][j] = ret ? 1 : 0;
            return ret;
        }
        
        memory[i][j] = 0;
        return false;
    }
}
