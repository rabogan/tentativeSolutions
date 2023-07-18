class Solution {
    int dr[4]{-1,0,1,0};
    int dc[4]{0,1,0,-1};
    
    struct node{
        int r;
        int c;
    };
    
    bool isValid(int r, int c, vector<vector<int>>&matrix){
        if(r < 0 || r>=matrix.size())
            return false;
        if(c<0||c>=matrix[0].size())
            return false;
        return true;
    }
public:
    pair<vector<node>,int>biggerNeighboursAndEdges(int r, int c, vector<vector<int>>&matrix){
        vector<node>edges;
        int incomingEdges = 0;
        
        for(int d = 0; d < 4; d++){
            int nr = dr[d]+r;
            int nc = dc[d]+c;
            if(!isValid(nr,nc,matrix))
                continue;
            
            if(matrix[r][c] < matrix[nr][nc])   //If the neighbouring node is bigger, we will push it into the 'biggerNeighbours' vector of nodes (used in the bfs below!)
                edges.push_back({nr,nc});  //3 5
            else if(matrix[r][c] > matrix[nr][nc])  //If the neighbouring node is smaller, it means there's an INCOMING EDGE to the original node!
                incomingEdges++;
        }
        return {edges,incomingEdges};   // This is return a vector of bigger neighbours, and the number of incoming edges to our node
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>>incomingEdges(rows,vector<int>(cols));
        queue<node>q;
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                incomingEdges[r][c] = biggerNeighboursAndEdges(r,c,matrix).second;
                //So, all the convoluted calculations in the function above give us the number of incoming edges here!
                if(incomingEdges[r][c]==0)
                    q.push({r,c});  //We're adding all our potential 'starts' to the path into the queue!
                //Our bfs function will cleave off the starts...
            }
        }
        int levels = 0;
        while(!q.empty()){
            int level_sz = q.size();
            while(level_sz--){
                int r = q.front().r;
                int c = q.front().c;
                q.pop();
                vector<node>biggerNeighbours = biggerNeighboursAndEdges(r,c,matrix).first;
                
                for(auto&node:biggerNeighbours){
                    if(--incomingEdges[node.r][node.c]==0)
                        q.push(node);
                }
            }
            levels++;
        }
        return levels;
    }
};