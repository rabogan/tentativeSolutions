/*
The backtracking solution is not so difficult to follow.
Firstly, we know that we want to return all possible paths from 0 to n-1,
necessitating both a vector<vector<int>>ANSWER and vector<int>CUR
When we reach n-1, we will push CUR into the ANSWER!
So, how do we work all this out?

Firstly, create ANSWER and CUR, and then push 0 (the first node of any solved path) into cur
After that, we use the initial graph, ANSWER, CUR, and the START and END variables,
calling them recursively using backtracking to try and find a valid path (and add that path to our answer)
The START is 0, the END is n-1!

The backtracking function uses the initial graph, a START (which is initially 0), and END (ALWAYS n-1), and the ANSWER and CUR
If we're at a point where START==END, when we have found a valid path, and can push CUR into ANS, returning

Otherwise, we're going to have a look at the lists currently held at the INDEX we have.
The INDEX is 'START'
So, we iterate through our graph, such that:
for(int i = 0; i < graph[start].size(); i++)
We will ADD the graph[start][i] to CUR, then call the backtrack function recursively,
then POP_BACK the latest added node
*/

class Solution {
public:
    void backtrack(vector<vector<int>>&graph, int start, int end, vector<vector<int>>&ans, vector<int>&cur){
        if(start==end){
            ans.push_back(cur);
            return;
        }

        for(int i = 0; i < graph[start].size(); i++){
            cur.push_back(graph[start][i]);
            backtrack(graph,graph[start][i],end,ans,cur);
            cur.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>cur;
        cur.push_back(0);
        backtrack(graph,0,graph.size()-1,ans,cur);
        return ans;
    }
};
