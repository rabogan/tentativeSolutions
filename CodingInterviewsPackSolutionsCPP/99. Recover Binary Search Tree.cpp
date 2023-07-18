class Solution {
public:
    TreeNode* mn = nullptr;
    TreeNode* mx = nullptr;
    TreeNode* predecessor = nullptr;
    void select(TreeNode* cur, TreeNode* pred){
        if(!mx){
            mn = cur;
            mx = pred;
        }else{
            mn = cur;
        }
    }

    void traverse(TreeNode* node){
        if(!node)
            return;
        
        traverse(node->left);
        if(predecessor && node->val < predecessor->val)
            select(node,predecessor);
        predecessor = node;
        traverse(node->right);
    }

    void recoverTree(TreeNode* root) {
        traverse(root);
        swap(mn->val,mx->val);
    }
};