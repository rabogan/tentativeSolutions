class Solution {
    typedef unordered_map<int,vector<int>>GRAPH;

    void addEdge(GRAPH&graph, int from, int to){
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
public:
    void dfs(GRAPH&graph, int node, unordered_set<int>&visited, vector<int>&ccNodes){
        ccNodes.push_back(node);
        visited.insert(node);

        for(int cur:graph[node]){
            if(!visited.count(cur)){
                dfs(graph,cur,visited,ccNodes);
            }
        }
    }

    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        GRAPH graph;
        for(auto&a:adjacentPairs)
            addEdge(graph,a[0],a[1]);

        unordered_set<int>visited;
        vector<int>ccNodes;

        for(auto&node:graph){
            if(!visited.count(node.first)){
                dfs(graph,node.first,visited,ccNodes);
                break;
            }
        }
        return ccNodes;
    }
};
