class Solution {
public:
    string toStr(int n){
        ostringstream oss;
        oss<<n;
        return oss.str();
    }
    
    string parenthesize_canonical(TreeNode* root){
        if(!root)
            return "()";
        
        string left = parenthesize_canonical(root->left);
        string right = parenthesize_canonical(root->right);
        
        if(left>right)
            swap(left,right);
        
        return "("+toStr(root->val)+left+right+")";
    }
    
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return parenthesize_canonical(root1)==parenthesize_canonical(root2);
    }
};