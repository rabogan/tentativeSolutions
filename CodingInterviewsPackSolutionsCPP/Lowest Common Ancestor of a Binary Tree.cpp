class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root||root==p||root==q)
            return root;
        
        TreeNode*left = lowestCommonAncestor(root->left,p,q);
        TreeNode*right = lowestCommonAncestor(root->right,p,q);
        
        if(left&&right)
            return root;
        if(left)
            return left;
        return right;
    }
};

/*
1) We know that if P is on the LEFT, and Q on the RIGHT, 
the ROOT is the LCA!!!
So, there are 4 cases for p and q's existence in the tree
a) P and Q are both in the tree
b) P is in the tree, Q is NOT
c) P is NOT in the tree, Q is in the tree
d) Neither are in the tree
2) For the recursive solution, we will return the LCA node 
if p and q are both in the tree
That is given by:
if(left && right)
return root;
3) What are left and right?  Well, we recursively call them 
from the root
Using left = LCA(root->left,p,q)
right = LCA(root->right,p,q)
4) If only one exists, return the node found
if(left)
return left;
return right;
5) If p and q are not left and right, and neither p nor q 
are in the tree, return nullptr!
given at the start by
if(!root || p==root||q==root)
return root;
*/
