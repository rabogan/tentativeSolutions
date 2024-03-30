class Solution {
    private:
    string goal = "123450"; 
    vector<vector<int>>dir{{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};   
//This works in a similar way to flattening the 2D array.
//Index 0 has neighbours 1/3, 1 has neighbours 0/2/4, and so on.
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";  
        for(int i=0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                start+=board[i][j]+'0'; 
            }
        }
        
        if(start==goal) 
            return 0;
        
        unordered_set<string>visited;
        queue<string>q;
        q.push(start);
        visited.insert(start);
        
        for(int level = 0, sz = q.size(); !q.empty(); ++level, sz = q.size()){
            while(sz--){
                string cur = q.front();
                q.pop();
                int idx1 = cur.find('0');
                for(int idx2:dir[idx1]){ 
                    swap(cur[idx1],cur[idx2]);  
                    if(cur==goal) 
                        return level+1;
                    
                    if(visited.insert(cur).second) 
                        q.push(cur); 
                    
                    swap(cur[idx1],cur[idx2]); 
                }
            }
        }
        return -1;
    }
};
