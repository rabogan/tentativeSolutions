class Solution {
    struct Edge{
        int to; 
        bool built;
    };
    
    typedef vector<vector<Edge>>GRAPH;
    
    void add_undirected_edge(GRAPH&graph, int from, int to){
        graph[from].push_back({to,true}); 
        graph[to].push_back({from,false}); 
    }
    
    void dfs(GRAPH& graph, int node, vector<bool>&visited, int &reorient_count){ 
        visited[node] = true;
        
        for(Edge&e:graph[node])
            if(!visited[e.to]){
                reorient_count+=e.built;
                dfs(graph,e.to,visited,reorient_count);
            }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int reorient_count = 0;
        GRAPH graph(n);  
        vector<bool>visited(n); 
        for(auto &edge:connections){ 
            add_undirected_edge(graph,edge[0],edge[1]);
        }
        dfs(graph,0,visited,reorient_count);   
        return reorient_count;
    }
};
