class Solution {
    public String canonical(String s) {
        StringBuilder t = new StringBuilder();
        int diff = s.charAt(0) - 'a';
        for (int i = 0; i < s.length(); i++) {
            t.append((char)('a' + (s.charAt(i) - 'a' - diff + 26) % 26));
        }
        return t.toString();
    }
    
    public List<List<String>> groupStrings(String[] strings) {
        HashMap<String, List<String>> myMap = new HashMap<>();
        for (String s : strings) {
            String key = canonical(s);
            myMap.computeIfAbsent(key, k -> new ArrayList<>()).add(s);
        }
        return new ArrayList<>(myMap.values());
    }
}
