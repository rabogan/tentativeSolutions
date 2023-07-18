class Solution {
    typedef unordered_map<int,vector<int>>GRAPH;
    
    void add_edge(GRAPH&graph, int from, int to){
        graph[from].push_back(to);
    }
    
    void build_graph(GRAPH&graph, vector<int>&pid, vector<int>&ppid){
        for(int i = 0; i < pid.size(); i++){
            add_edge(graph,ppid[i],pid[i]);
        }
    }
public:
    void dfs(GRAPH&graph, int kill, unordered_set<int>&visited){
        visited.insert(kill);
        
        for(int node:graph[kill]){
            if(!visited.count(node))
                dfs(graph,node,visited);
        }
    }
    
    vector<int>killer(GRAPH&graph, int kill){
        unordered_set<int>visited;
        dfs(graph,kill,visited);
        return vector<int>(visited.begin(),visited.end());
    }
    
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        GRAPH graph;
        build_graph(graph,pid,ppid);
        return killer(graph,kill);
    }
};