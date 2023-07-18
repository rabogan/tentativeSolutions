class Solution {
    int maxSum = INT_MIN;
public:
    int inorder(TreeNode* root){
        if(!root)
            return 0;

        int left = inorder(root->left);
        int right = inorder(root->right);

        maxSum = max(root->val,maxSum);
        maxSum = max(maxSum,root->val+left+right);
        maxSum = max(maxSum,root->val+max(left,right));

        return max(root->val,root->val+max(right,left));
    }

    int maxPathSum(TreeNode* root) {
        inorder(root);
        return maxSum;
    }
};
