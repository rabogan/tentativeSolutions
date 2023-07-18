class Solution {
    typedef vector<vector<int>>GRAPH;
    
    void addEdge(GRAPH&graph, int from, int to){
        graph[from].push_back(to);
    }
public:
    vector<int>topSort(GRAPH&graph){
        int nodes = graph.size();
        vector<int>incomingEdges(nodes);
        for(int i = 0; i < nodes; i++){
            for(int j:graph[i])
                incomingEdges[j]++;
        }
        queue<int>q;
        for(int i = 0; i < nodes; i++){
            if(incomingEdges[i]==0)
                q.push(i);
        }
        int nodesFound = 0;
        vector<int>result;
        while(!q.empty()){
            int i = q.front();
            q.pop();
            nodesFound++;
            result.push_back(i);
            
            for(int j:graph[i]){
                if(--incomingEdges[j]==0)
                    q.push(j);
            }
        }
        if(nodesFound!=nodes)
            result.clear();
        return result;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        GRAPH graph(numCourses);
        for(auto&pre:prerequisites){
            addEdge(graph,pre[1],pre[0]);
        }
        
        return topSort(graph);
    }
};
