class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>>jobs;
        int sz = difficulty.size();
        for(int i = 0; i < sz; i++){
            jobs.push_back({difficulty[i],profit[i]});
        }
        sort(jobs.begin(),jobs.end());
        sort(worker.begin(),worker.end());
        int job = 0;
        int curProfit = 0;
        int totalProfit = 0;
        
        for(int i = 0; i < worker.size(); i++){
            while(job < sz && worker[i] >= jobs[job].first){
                curProfit=max(curProfit,jobs[job].second);
                job++;
            }
            totalProfit+=curProfit;
        }
        return totalProfit;
    }
};
