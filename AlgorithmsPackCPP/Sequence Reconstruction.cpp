class Solution {
    typedef unordered_map<int,vector<int>>GRAPH;

    void addEdge(GRAPH&graph, int from, int to){
        graph[from].push_back(to);
    }
public:
    vector<int>topSort(GRAPH&graph){
        unordered_map<int,int>incomingEdges;
        for(auto&node:graph){
            for(int j:node.second){
                incomingEdges[j]++;
            }
        }
        queue<int>q;
        for(auto&node:graph){
            if(!incomingEdges.count(node.first))
                q.push(node.first);
        }
        vector<int>result;
        while(!q.empty()){
            if(q.size()>1)
                return vector<int>();

            int cur = q.front();
            q.pop();
            result.push_back(cur);

            for(int j:graph[cur]){
                if(--incomingEdges[j]==0){
                    q.push(j);
                }
            }
        }
        if(result.size()!=graph.size())
            result.clear();
        return result;
    }

    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        GRAPH graph(nums.size());
        for(auto&seq:sequences){
            for(int i = 0; i < seq.size()-1; i++){
                addEdge(graph,seq[i],seq[i+1]);
            }
        }
        for(auto&seq:sequences){
            if(seq.size()==1 && graph.count(seq[0])==0){
                graph[seq[0]] = vector<int>();
            }
        }
        return topSort(graph)==nums;
    }
};
