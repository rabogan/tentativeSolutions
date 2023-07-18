class Solution {
public:
    bool process(queue<int>&q, vector<bool>&visited, int num, int goal){
        if(num==goal)
            return true;
        
        if(0<=num && num<=1000 && !visited[num]){
            visited[num] = true;
            q.push(num);
        }
        
        return false;
    }
    
    int minimumOperations(vector<int>& nums, int start, int goal) {
        queue<int>q;
        vector<bool>visited(1001);
        q.push(start);
        visited[start] = true;
        
        for(int level = 0, sz = q.size(); !q.empty(); ++level, sz = q.size()){
            while(sz--){
                int cur = q.front();
                q.pop();
                
                for(int i = 0; i < nums.size(); i++){
                    if(process(q,visited,cur+nums[i],goal)
                      ||process(q,visited,cur-nums[i],goal)
                      ||process(q,visited,cur^nums[i],goal))
                        return level+1;
                }
            }
        }
        return -1;
    }
};
