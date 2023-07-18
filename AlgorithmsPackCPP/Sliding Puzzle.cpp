class Solution {
    private:
    string goal = "123450";  //We'll be converting our function into a string!
    vector<vector<int>>dir{{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};   //This works in a similar way to flattening the 2D array.
    //Index 0 has neighbours 1/3, 1 has neighbours 0/2/4, and so on.
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";  
        for(int i=0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                start+=board[i][j]+'0';   //We begin by building our start string!
            }
        }
        
        if(start==goal)   //If we have an instant match, 0 steps are needed!
            return 0;
        
        unordered_set<string>visited;   //These are fairly standard things to consider
        queue<string>q;
        q.push(start);
        visited.insert(start);
        
        for(int level = 0, sz = q.size(); !q.empty(); ++level, sz = q.size()){
            while(sz--){
                string cur = q.front();
                q.pop();
                int idx1 = cur.find('0');  //This is the first 'unusual' thing.  Look for the index of '0' in the string
                for(int idx2:dir[idx1]){   //Iterate through the index, performing swaps, and adding any uncovered strings into the queue!
                    swap(cur[idx1],cur[idx2]);   //Perform the 'swap' of 0 from the current index to neighbouring indices
                    if(cur==goal)   //If we make the goal string "123450", we return level+1
                        return level+1;
                    
                    if(visited.insert(cur).second)   //Otherwise, we insert the 'cur' combination into the visited unSet,
                        q.push(cur);  //AND, if insert(cur).second ;), add the cur combination to the queue!
                    
                    swap(cur[idx1],cur[idx2]);    //Don't forget to swap back
                }
            }
        }
        return -1;   //And double don't forget to return -1 if this proves impossible!
    }
};
