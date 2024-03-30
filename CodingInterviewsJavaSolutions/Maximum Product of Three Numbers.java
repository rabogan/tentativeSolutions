class Solution {
    public int maximumProduct(int[] nums) {
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a, b) -> Integer.compare(b, a));
        
        for (int num : nums) {
            minHeap.offer(num);
            maxHeap.offer(num);
            
            if (minHeap.size() > 3)
                minHeap.poll();
            if (maxHeap.size() > 2)
                maxHeap.poll();
        }
        
        int max1 = Integer.MIN_VALUE, max2 = Integer.MIN_VALUE, max3 = Integer.MIN_VALUE;
        int min1 = Integer.MAX_VALUE, min2 = Integer.MAX_VALUE;
        
        while (!minHeap.isEmpty()) {
            int num = minHeap.poll();
            max3 = max2;
            max2 = max1;
            max1 = num;
        }
        
        while (!maxHeap.isEmpty()) {
            int num = maxHeap.poll();
            min2 = min1;
            min1 = num;
        }
        
        return Math.max(max1 * max2 * max3, min1 * min2 * max1);
    }
}
