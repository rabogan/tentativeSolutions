import java.util.PriorityQueue;

class Solution {
    public int[][] kClosest(int[][] points, int k) {
        PriorityQueue<int[]> maxHeap = new PriorityQueue<>((a, b) -> getDistance(b) - getDistance(a));
        
        for (int[] point : points) {
            maxHeap.offer(point);
            
            if (maxHeap.size() > k)
                maxHeap.poll();
        }
        
        int[][] result = new int[k][2];
        while (k > 0) {
            result[--k] = maxHeap.poll();
        }
        
        return result;
    }
    
    private int getDistance(int[] point) {
        return point[0] * point[0] + point[1] * point[1];
    }
}
