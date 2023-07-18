const int MAX = 200+1;
int memory[MAX][MAX];
vector<vector<int>>dungeon;
const int OO = 1e9;
class Solution {
public:
    int minHealth(int r, int c){
        int rows = dungeon.size();
        int cols = dungeon[0].size();
        
        if(r>=rows||c>=cols)
            return OO;
        
        if(r==rows-1 && c==cols-1)
        {
            if(dungeon[r][c] < 0)
                return 1-dungeon[r][c];
            return 1;
        }
        
        auto &ret = memory[r][c];
        if(ret!=-1)
            return ret;
        
        int health = min(minHealth(r+1,c),minHealth(r,c+1));
        
        if(health<=dungeon[r][c])
            return 1;
        
        return ret = health - dungeon[r][c];
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon_) {
        dungeon = dungeon_;
        memset(memory,-1,sizeof(memory));
        return minHealth(0,0);
    }
};