class Solution {
    public int[] canonical(String s) {
        HashMap<Character, Integer> myMap = new HashMap<>();
        int canonicalIndex = 0;
        int[] result = new int[s.length()];
        
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (!myMap.containsKey(ch)) {
                myMap.put(ch, canonicalIndex);
                canonicalIndex++;
            }
            result[i] = myMap.get(ch);
        }
        
        return result;
    }
    
    public boolean isIsomorphic(String s, String t) {
        int[] sCanonical = canonical(s);
        int[] tCanonical = canonical(t);
        
        if (sCanonical.length != tCanonical.length) {
            return false;
        }
        
        for (int i = 0; i < sCanonical.length; i++) {
            if (sCanonical[i] != tCanonical[i]) {
                return false;
            }
        }
        
        return true;
    }
}
