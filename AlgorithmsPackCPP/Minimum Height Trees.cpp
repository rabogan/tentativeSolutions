class Solution {
    typedef vector<vector<int>>GRAPH;
    
    void addEdge(GRAPH&graph, int from, int to){
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
public:
    vector<int>topSort(GRAPH&graph){
        int nodes = graph.size();
        if(nodes==1)
            return {0};
        vector<int>incomingEdges(nodes);
        for(int i = 0; i < nodes; i++){
            for(int j:graph[i])
                incomingEdges[j]++;
        }
        queue<int>q;
        for(int i = 0; i < nodes; i++){
            if(incomingEdges[i]==1)
                q.push(i);
        }
        while(nodes>2){
            int sz = q.size();
            nodes-=sz;
            while(sz--){
                int i = q.front();
                q.pop();
                
                for(int j:graph[i]){
                    if(--incomingEdges[j]==1)
                        q.push(j);
                }
            }
        }
        vector<int>result;
        while(!q.empty()){
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        GRAPH graph(n);
        for(auto&e:edges)
            addEdge(graph,e[0],e[1]);
        
        return topSort(graph);
    }
};
