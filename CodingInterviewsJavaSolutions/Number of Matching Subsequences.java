class Solution {
    public int numMatchingSubseq(String s, String[] words) {
        int[] pos = new int[words.length];
        int matchingWords = 0;
        HashMap<Character, List<Integer>> charToIndices = new HashMap<>();
        for (int i = 0; i < words.length; i++) {
            charToIndices.computeIfAbsent(words[i].charAt(0), k -> new ArrayList<>()).add(i);
        }
        
        for (char ch1 : s.toCharArray()) {
            List<Integer> wordIndices = charToIndices.getOrDefault(ch1, new ArrayList<>());
            charToIndices.put(ch1, new ArrayList<>());
            
            for (int idx : wordIndices) {
                String word = words[idx];
                pos[idx]++;
                
                if (pos[idx] == word.length()) {
                    matchingWords++;
                } else {
                    char ch2 = word.charAt(pos[idx]);
                    charToIndices.computeIfAbsent(ch2, k -> new ArrayList<>()).add(idx);
                }
            }
        }
        return matchingWords;
    }
}
