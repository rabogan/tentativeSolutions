class Solution {
    bool colorConflict{};
public:
    void dfs(vector<vector<int>>&graph, int node, vector<int>&colors, int assignCol = 1){
        if(colors[node]==0)
            colors[node] = assignCol;
        else{
            if(colors[node]!=assignCol)
                colorConflict = true;

            return;
        }
        for(int cur:graph[node])
            dfs(graph,cur,colors,3-assignCol);
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>colors(n,0);

        for(int i = 0; i < n; i++){
            if(colors[i]==0){
                dfs(graph,i,colors);
                if(colorConflict)
                    return false;
            }
        }
        return true;
    }
};