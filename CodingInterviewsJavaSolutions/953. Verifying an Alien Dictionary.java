class Solution {
    private HashMap<Character, Integer> myMap;
    
    public boolean isSmaller(String s1, String s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        
        int length = Math.min(len1, len2);
        
        for (int i = 0; i < length; i++) {
            if (s1.charAt(i) != s2.charAt(i)) {
                return myMap.get(s1.charAt(i)) < myMap.get(s2.charAt(i));
            }
        }
        
        return len1 < len2;
    }
    
    public boolean isAlienSorted(String[] words, String order) {
        myMap = new HashMap<>();
        
        for (int i = 0; i < order.length(); i++) {
            myMap.put(order.charAt(i), i);
        }
        
        for (int i = 1; i < words.length; i++) {
            if (!words[i - 1].equals(words[i]) && !isSmaller(words[i - 1], words[i])) {
                return false;
            }
        }
        
        return true;
    }
}
