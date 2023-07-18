class Solution {
    typedef vector<vector<int>>GRAPH;

    void addEdge(GRAPH&graph, int from, int to){
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
public:
    void dfs(GRAPH&graph, int node, vector<bool>&visited, vector<int>&ccNodes){
        visited[node] = true;
        ccNodes.push_back(node);

        for(int cur:graph[node]){
            if(!visited[cur])
                dfs(graph,cur,visited,ccNodes);
        }
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        GRAPH graph(s.size());

        for(auto&p:pairs)
            addEdge(graph,p[0],p[1]);

        vector<bool>visited(s.size());

        for(int i = 0; i < s.size(); i++){
            if(visited[i])
                continue;

            vector<int>ccNodes;
            dfs(graph,i,visited,ccNodes);

            string ccLetters;
            for(int node:ccNodes)
                ccLetters+=s[node];

            sort(ccNodes.begin(),ccNodes.end());
            sort(ccLetters.begin(),ccLetters.end());

            for(int j = 0; j < ccNodes.size(); j++){
                s[ccNodes[j]] = ccLetters[j];
            }
        }
        return s;
    }
};
