class Solution {
public:
    typedef vector<vector<int>>GRAPH;

    void addEdge(GRAPH&graph, int from, int to){
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    int mxDiam{};

    int traverse(GRAPH&graph, int node, int parent = -1){
        int h1 = 0;
        int h2 = 0;

        for(int cur:graph[node]){
            if(cur==parent)
                continue;
            
            int value = traverse(graph,cur,node);

            if(value > h1){
                h2 = h1;
                h1 = value;
            }else if(value > h2){
                h2 = value;
            }
        }
        mxDiam = max(mxDiam,h1+h2);
        return 1+h1;
    }

    int treeDiameter(vector<vector<int>>& edges) {
        GRAPH graph(edges.size()+1);
        for(auto&e:edges)
            addEdge(graph,e[0],e[1]);

        traverse(graph,0);
        return mxDiam;
    }
};