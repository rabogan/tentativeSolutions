class Solution {
    int dr[4]{-1,0,1,0};
    int dc[4]{0,1,0,-1};
    
    struct Cell{
        int r;
        int c;
    };
    
    bool isValid(int r, int c, vector<vector<int>>&rooms){
        if(r<0||r>=rooms.size())
            return false;
        if(c<0||c>=rooms[0].size())
            return false;
        return true;
    }
    
    const int INF = 2147483647;
public:
    void fillSpaces(vector<vector<int>>&rooms, vector<vector<bool>>&visited, vector<Cell>&starts){
        queue<Cell>q;
        for(auto&cel:starts){
            q.push(cel);
            visited[cel.r][cel.c] = true;
        }
        
        for(int level = 0, sz = q.size(); !q.empty(); ++level, sz = q.size()){
            while(sz--){
                int r = q.front().r;
                int c = q.front().c;
                q.pop();
                
                for(int d = 0; d < 4; d++){
                    int nr = dr[d]+r;
                    int nc = dc[d]+c;
                    if(!isValid(nr,nc,rooms)||visited[nr][nc]||rooms[nr][nc]==-1)
                        continue;
                    
                    if(rooms[nr][nc]==INF){
                        rooms[nr][nc] = level+1;
                        q.push({nr,nc});
                        visited[nr][nc] =  true;
                    }
                }
            }
        }
    }
    
    void bfs(vector<vector<int>>&rooms){
        int rows = rooms.size();
        int cols = rooms[0].size();
        
        vector<vector<bool>>visited(rows,vector<bool>(cols));
        vector<Cell>starts;
        
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(rooms[r][c]==0){
                    starts.push_back({r,c});
                }
            }
        }
        fillSpaces(rooms,visited,starts);
    }
    
    void wallsAndGates(vector<vector<int>>& rooms) {
        bfs(rooms);
    }
};
