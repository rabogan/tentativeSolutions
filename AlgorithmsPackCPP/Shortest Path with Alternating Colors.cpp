class Solution {
    struct Edge{
        int to;
        int color;
    };
    const int OO = 1e9;
    const int RED = 0;
    const int BLUE = 1;
    typedef vector<vector<Edge>>GRAPH;

    void addEdge(GRAPH&graph, int from, int to, int color){
        graph[from].push_back({to,color});
    }
public:
    vector<int>bfs(GRAPH&graph, int node){
        queue<Edge>q;
        q.push({node,RED});
        q.push({node,BLUE});

        int nodes = graph.size();
        vector<vector<int>>visited(nodes,vector<int>(2,OO));
        visited[node][RED] = visited[node][BLUE] = 0;

        vector<int>result(nodes,-1);
        result[node] = 0;

        for(int level = 0, sz = q.size(); !q.empty(); ++level, sz = q.size()){
            while(sz--){
                int to = q.front().to;
                int color = q.front().color;
                q.pop();

                for(Edge&e:graph[to]){
                    if(e.color != color && visited[e.to][e.color]==OO){
                        q.push(e);
                        visited[e.to][e.color] = level+1;

                        if(result[e.to]==-1)
                            result[e.to] = level+1;
                    }
                }
            }
        }
        return result;
    }

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        GRAPH graph(n);
        for(auto&r:redEdges)
            addEdge(graph,r[0],r[1],RED);
        for(auto&b:blueEdges)
            addEdge(graph,b[0],b[1],BLUE);
        
        return bfs(graph,0);
    }
};
