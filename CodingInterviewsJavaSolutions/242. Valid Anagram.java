class Solution {
    public boolean isAnagram(String s, String t) {
        Map<Character, Integer> freq1 = new HashMap<>();
        Map<Character, Integer> freq2 = new HashMap<>();
        
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            freq1.put(ch, freq1.getOrDefault(ch, 0) + 1);
        }
        
        for (int i = 0; i < t.length(); i++) {
            char ch = t.charAt(i);
            freq2.put(ch, freq2.getOrDefault(ch, 0) + 1);
        }
        
        if (freq1.size() != freq2.size()) {
            return false;
        }
        
        for (Map.Entry<Character, Integer> entry : freq1.entrySet()) {
            char ch = entry.getKey();
            int freq = entry.getValue();
            
            if (freq != freq2.getOrDefault(ch, 0)) {
                return false;
            }
        }
        
        return true;
    }
}
