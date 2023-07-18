/*
This solution uses a 'controlled' stack-based approach
Essentially, we'll look for the left-chain from a given node.  We know that the left-most node will be the smallest
However, when we move up to the parent (after iterating), we need to ensure we add ALL of that node's right nodes.

1)  KEY:  The top node in the stack is ALWAYS the next to be printed
2)  To satisfy this requirement, we begin by having our constructor expand the root.  
It does so by adding the leftMostChain each time (and in perpetuity ;))
2b)  We keep adding nodes to the stack until reaching the bottom-most left node
3)  When we pop a node from the stack, we know that we're returning that nodes value as 'next'
3b)  However, we need to look and see whether it has ANY right nodes (and add to the leftChain)
4)  The 'hasNext' function is VERY easy!
*/
class BSTIterator {
public:
    stack<TreeNode*>stk;
    
    void addLeftChain(TreeNode* root){
        while(root){
            stk.push(root);
            root = root->left;
        }
    }
    
    BSTIterator(TreeNode* root) {
        addLeftChain(root);
    }
    
    int next() {
        TreeNode* t = stk.top();
        stk.pop();
        
        if(t->right)
            addLeftChain(t->right);
        
        return t->val;
    }
    
    bool hasNext() {
        return (!stk.empty());
    }
};
