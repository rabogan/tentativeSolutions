class Solution {
    public boolean isSubsequence(String s, String t) {
        int ptr1 = 0;
        int ptr2 = 0;
        int count = 0;
        
        while (ptr1 < s.length() && ptr2 < t.length()) {
            if (s.charAt(ptr1) == t.charAt(ptr2)) {
                count++;
                ptr1++;
                ptr2++;
            } else {
                ptr2++;
            }
        }
        
        return count == s.length();
    }
}
