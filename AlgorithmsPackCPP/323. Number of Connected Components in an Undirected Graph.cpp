class Solution {
    typedef vector<vector<int>>GRAPH;

    void addEdge(GRAPH&graph, int from, int to){
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
public:
    void dfs(GRAPH&graph, int node, vector<bool>&visited){
        int nodes = graph.size();
        visited[node] = true;

        for(int cur:graph[node]){
            if(!visited[cur]){
                dfs(graph,cur,visited);
            }
        }
    }

    int countThem(GRAPH&graph){
        int nodes = graph.size();
        vector<bool>visited(nodes);
        int count = 0;
        for(int i = 0; i < nodes; i++){
            if(!visited[i]){
                dfs(graph,i,visited);
                count++;
            }
        }
        return count;
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        GRAPH graph(n);
        for(auto&e:edges){
            addEdge(graph,e[0],e[1]);
        }

        return countThem(graph);
    }
};