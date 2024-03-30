class Solution {
    public int findMaxValueOfEquation(int[][] points, int k) {
        	PriorityQueue<int[]> pq = new PriorityQueue<int[]>((a, b)->Integer.compare(b[0], a[0]));

	int res = Integer.MIN_VALUE;
	for(int[] p : points) {
		while(!pq.isEmpty() && p[0] - pq.peek()[1] > k) pq.poll();
		if(!pq.isEmpty()) {
		   int[] e = pq.peek();
		   res = Math.max(res, p[0]+p[1] + e[0]); 
		}
		pq.offer(new int[]{p[1]-p[0], p[0]});
	}
	return res;
    }
}
// https://leetcode.com/problems/max-value-of-equation/discuss/709697/Java-PriorityQueue-Solution-!!!
