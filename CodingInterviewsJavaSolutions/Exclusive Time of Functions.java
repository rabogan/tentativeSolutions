class Entry {
    public int id;
    public int startTime;
    public int subcallTime;
    
    public Entry(int id, int time) {
        this.id = id;
        this.startTime = time;
        this.subcallTime = 0;
    }
}

class Solution {
    public int[] parse(String str) {
        int sz = str.length();
        int[] result = new int[sz];

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < sz; i++) {
            if (str.charAt(i) == ':') {
                sb.append(' ');
            } else {
                sb.append(str.charAt(i));
            }
        }

        String[] parts = sb.toString().split(" ");
        int id = Integer.parseInt(parts[0]);
        boolean type = parts[1].equals("start");
        int time = Integer.parseInt(parts[2]);

        return new int[]{id, type ? 1 : 0, time};
    }

    public int[] exclusiveTime(int n, List<String> logs) {
        int[] result = new int[n];
        Deque<Entry> logStack = new ArrayDeque<>();
        logStack.push(new Entry(0, 0));

        for (String log : logs) {
            int[] v = parse(log);
            int id = v[0];
            boolean type = v[1] == 1;
            int time = v[2];

            if (type) {
                logStack.push(new Entry(id, time));
            } else {
                Entry e = logStack.pop();
                int sTime = e.startTime;
                int total = time - sTime + 1;
                int exclusive = total - e.subcallTime;

                Entry eParent = logStack.pop();
                eParent.subcallTime += total;
                logStack.push(eParent);

                result[id] += exclusive;
            }
        }

        return result;
    }
}
