class Solution {
    int maxDiameter = 0;
public:
    int height(TreeNode*root){
        if(!root)
            return 0;
        
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        
        maxDiameter = max(maxDiameter,leftHeight+rightHeight);
        
        return 1+max(leftHeight,rightHeight);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        
        height(root);
        return maxDiameter;
    }
};

/*
TO solve the Binary Tree diameter problem, first understand 
what it means!  The diameter of a BT is simply the longest 
path in a Binary Tree

1)  If there's no root to our tree, simply return 0
2)  We'll use a global variable (max_diameter) to allow 
easy updating of our eventual result
3)  To solve this, we will simply call the HEIGHT function
You should be familiar with the height function already
4)  Within our specialized height function call, we will 
continually update the maxDiameter
4b) maxDiameter = max(maxDiameter,leftHeight + rightHeight)
5)  Otherwise, our height function operates as standard, 
with recursive calls left and right, returning 1+the 
maximum of the left and right subtrees

Essentially, we update our maxDiamter variable based 
on the left and right subtrees
*/
