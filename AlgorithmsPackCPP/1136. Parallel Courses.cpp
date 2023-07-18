class Solution {
    typedef vector<vector<int>>GRAPH;


    void addEdge(GRAPH&graph, int from, int to){
        graph[from].push_back(to);
    }

public:
    int topSort(GRAPH&graph){
        int nodes = graph.size();
        vector<int>incomingEdges(nodes);
        for(int i = 0; i < nodes; i++){
            for(int j:graph[i]){
                incomingEdges[j]++;
            }
        }
        queue<int>q;
        for(int i = 0; i < nodes; i++){
            if(incomingEdges[i]==0){
                q.push(i);
            }
        }
        int nodesFound = 0;
        int result = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int cur = q.front();
                q.pop();
                nodesFound++;
                for(int j:graph[cur]){
                    if(--incomingEdges[j]==0)
                        q.push(j);
                }
            }
            result++;
        }
        if(nodesFound!=nodes)
            return -1;
        return result;
    }

    int minimumSemesters(int n, vector<vector<int>>& relations) {
        GRAPH graph(n);
        for(auto&rel:relations)
            addEdge(graph,rel[0]-1,rel[1]-1);

        return topSort(graph);
    }
};