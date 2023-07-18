class Solution {
    public int openLock(String[] deadends, String target) {
        String start = "0000";
        if (start.equals(target))
            return 0;

        Queue<String> q = new LinkedList<>();
        Set<String> visited = new HashSet<>(Arrays.asList(deadends));
        if (visited.contains(start))
            return -1;

        q.offer(start);
        visited.add(start);

        int level = 0;
        while (!q.isEmpty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                String cur = q.poll();
                char[] curChars = cur.toCharArray();
                for (int d = 0; d < 4; d++) {
                    curChars[d] = prev(curChars[d]);
                    String curPrev = new String(curChars);
                    if (curPrev.equals(target))
                        return level + 1;
                    if (visited.add(curPrev))
                        q.offer(curPrev);

                    curChars[d] = next(next(curChars[d]));
                    String curNext = new String(curChars);
                    if (curNext.equals(target))
                        return level + 1;
                    if (visited.add(curNext))
                        q.offer(curNext);

                    curChars[d] = prev(curChars[d]);
                }
            }
            level++;
        }
        return -1;
    }

    private char prev(char ch) {
        if (ch == '0')
            return '9';
        return (char) (ch - 1);
    }

    private char next(char ch) {
        if (ch == '9')
            return '0';
        return (char) (ch + 1);
    }
}
