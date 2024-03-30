class Solution {
    public int nthUglyNumber(int n) {
        PriorityQueue<Long> minHeap = new PriorityQueue<>();
        minHeap.add(1L);
        
        int nth = 0;
        long mnValue = 0;
        
        while (!minHeap.isEmpty() && nth < n) {
            nth += 1;
            mnValue = minHeap.poll();
            
            while (!minHeap.isEmpty() && minHeap.peek() == mnValue)
                minHeap.poll();
            
            minHeap.add(2 * mnValue);
            minHeap.add(3 * mnValue);
            minHeap.add(5 * mnValue);
        }
        
        return (int) mnValue;
    }
}
