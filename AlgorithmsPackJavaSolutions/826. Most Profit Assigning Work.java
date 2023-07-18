public class Solution {
    public int maxProfitAssignment(int[] difficulty, int[] profit, int[] worker) {
        List<Pair<Integer, Integer>> jobs = new ArrayList<>();
        int sz = difficulty.length;
        for (int i = 0; i < sz; i++) {
            jobs.add(new Pair<>(difficulty[i], profit[i]));
        }
        Collections.sort(jobs, (a, b) -> a.getKey() - b.getKey());
        Arrays.sort(worker);
        
        int job = 0;
        int curProfit = 0;
        int totalProfit = 0;
        
        for (int i = 0; i < worker.length; i++) {
            while (job < sz && worker[i] >= jobs.get(job).getKey()) {
                curProfit = Math.max(curProfit, jobs.get(job).getValue());
                job++;
            }
            totalProfit += curProfit;
        }
        
        return totalProfit;
    }
}
