class Solution {
    public int maxEvents(int[][] events) {
        Arrays.sort(events, (a, b) -> a[0] - b[0]);
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        int attended = 0;
        int event = 0;
        int sz = events.length;
        
        for (int day = 1; event < sz || !minHeap.isEmpty(); day++) {
            while (!minHeap.isEmpty() && minHeap.peek() < day) {
                minHeap.poll();
            }
            
            if (event < sz && minHeap.isEmpty()) {
                day = Math.max(day, events[event][0]);
            }
            
            while (event < sz && events[event][0] <= day) {
                minHeap.offer(events[event][1]);
                event++;
            }
            
            if (!minHeap.isEmpty()) {
                minHeap.poll();
                attended++;
            }
        }
        
        return attended;
    }
}
