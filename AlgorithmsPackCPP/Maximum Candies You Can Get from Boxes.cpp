class Solution {
    int collected = 0;
    
    void addKeysFromBoxes(vector<int>&status,vector<vector<int>>&keys,vector<int>&boxes){
        for(int box:boxes){
            for(int key:keys[box]){
                status[key] = 1;
            }
        }
    }
    
    void openBoxes(queue<int>&q,vector<bool>&visited,vector<int>&status, vector<int>&candies, vector<int>&boxes){
        for(int box:boxes){
            if(!visited[box] && status[box]){
                q.push(box);
                visited[box] = true;
                collected+=candies[box];
            }
        }
    }
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue<int>q;
        vector<bool>visited(status.size());
        
        addKeysFromBoxes(status,keys,initialBoxes);
        openBoxes(q,visited,status,candies,initialBoxes);
        
        while(!q.empty()){
            int box = q.front();
            q.pop();
            addKeysFromBoxes(status,keys,containedBoxes[box]);
            openBoxes(q,visited,status,candies,containedBoxes[box]);
        }
        return collected;
    }
};
