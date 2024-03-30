class Solution {
    public List<String> split(String path, char separator) {
        List<String> result = new ArrayList<>();
        StringBuilder cur = new StringBuilder();
        
        for (int idx = 0; idx < path.length(); idx++) {
            char c = path.charAt(idx);
            if (c == separator) {
                result.add(cur.toString());
                cur = new StringBuilder();
            } else {
                cur.append(c);
            }
        }
        
        if (cur.length() > 0) {
            result.add(cur.toString());
        }
        return result;
    }
    
    public String simplifyPath(String path) {
        List<String> tokens = split(path, '/');
        Deque<String> stk = new LinkedList<>();
        
        for (int idx = 0; idx < tokens.size(); idx++) {
            String token = tokens.get(idx);
            if (token.equals("") || token.equals(".")) {
                continue;
            }
            
            if (token.equals("..")) {
                if (!stk.isEmpty()) {
                    stk.pop();
                }
            } else {
                stk.push(token);
            }
        }
        
        if (stk.isEmpty()) {
            return "/";
        }
        
        StringBuilder result = new StringBuilder();
        while (!stk.isEmpty()) {
            result.insert(0, "/" + stk.pop());
        }
        
        return result.toString();
    }
}
