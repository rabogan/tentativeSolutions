/*
This is the BFS approach.  The key observations are simple:
1)   If we have N levels, we need to return N values
2***) Level-by-level, we want the value from the FINAL node from each
3) Easily achievable with BFS and the 'size trick'
3b)  i.e. if we have M nodes at the current level, after we process the
queue M times, the new added nodes represent the next level's nodes
4)  And, key, is that when sz-1 == i at each level, we add that to our result vector
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>result;
        if(!root)
            return result;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            int sz = q.size();
            
            for(int i = 0; i < sz; i++){
                TreeNode* cur = q.front();
                q.pop();
                
                if(i==sz-1)
                    result.push_back(cur->val);
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
        }
        return result;
    }
};
