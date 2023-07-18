class Solution {
    typedef vector<vector<int>>GRAPH;
    const int OO = 1e9;
    void addEdge(GRAPH&graph, int from, int to){
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
public:
    bool bfsCycle(GRAPH&graph, int node, vector<int>&visited, vector<int>&parent){
        visited[node] = 0;
        queue<int>q;
        q.push(node);
        
        for(int level = 0, sz = q.size(); !q.empty(); ++level, sz = q.size()){
            while(sz--){
                int cur = q.front();
                q.pop();
                
                for(int neighbour:graph[cur]){
                    if(parent[cur] == neighbour)
                        continue;
                    
                    if(visited[neighbour]==OO){
                        parent[neighbour] = cur;
                        visited[neighbour] = level+1;
                        q.push(neighbour);
                    }else
                        return true;
                }
            }
        }
        return false;
    }
    
    bool hasCycle(GRAPH&graph){
        int nodes = graph.size();
        vector<int>visited(nodes,OO);
        vector<int>parent(nodes,-1);
        
        for(int idx = 0; idx < nodes; idx++){
            if(visited[idx]==OO && bfsCycle(graph, idx, visited, parent))
                return true;
        }
        return false;
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        if(n-1 != edges.size())
            return false;
        
        GRAPH graph(n);
        for(auto&e:edges)
            addEdge(graph,e[0],e[1]);
        
        return !hasCycle(graph);
    }
};
