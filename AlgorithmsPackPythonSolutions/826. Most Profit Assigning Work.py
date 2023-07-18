class Solution:
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        jobs = list(zip(difficulty, profit))
        jobs.sort()
        worker.sort()
        
        job = 0
        curProfit = 0
        totalProfit = 0
        
        for i in range(len(worker)):
            while job < len(jobs) and worker[i] >= jobs[job][0]:
                curProfit = max(curProfit, jobs[job][1])
                job += 1
            totalProfit += curProfit
        
        return totalProfit
