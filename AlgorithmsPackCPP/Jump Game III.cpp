class Solution {
public:
    bool process(queue<int>&q,vector<bool>&visited, vector<int>&arr, int index){
        if(index < 0 || index>=arr.size()||visited[index])
            return false;

        if(arr[index]==0)
            return true;

        q.push(index);
        visited[index] = true;
        return false;
    }

    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        if(arr[start]==0)
            return true;

        queue<int>q;
        q.push(start);
        vector<bool>visited(n);
        visited[start] = true;

        for(int level = 0, sz = q.size(); !q.empty(); ++level, sz = q.size()){
            while(sz--){
                int cur = q.front();
                q.pop();

                if(process(q,visited,arr,cur+arr[cur])
                ||process(q,visited,arr,cur-arr[cur]))
                return true;
            }
        }
        return false;
    }
};
