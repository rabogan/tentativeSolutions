class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> charToIndex = new HashMap<>();
        int sz = s.length();
        int result = 0;
        int start = 0;
        for (int end = 0; end < sz; end++) {
            if (charToIndex.containsKey(s.charAt(end))) {
                start = Math.max(start, charToIndex.get(s.charAt(end)) + 1);
            }
            charToIndex.put(s.charAt(end), end);
            result = Math.max(result, end - start + 1);
        }
        return result;
    }
}
