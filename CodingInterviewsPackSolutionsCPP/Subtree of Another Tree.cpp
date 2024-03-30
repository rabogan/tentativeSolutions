class Solution {
public:
    string toStr(int n){
        ostringstream oss;
        oss<<n;
        return oss.str();
    }
    
    string parenthesize(TreeNode*root){
        if(!root)
            return "()";
        
        string left = parenthesize(root->left);
        string right = parenthesize(root->right);
        
        return "("+toStr(root->val)+left+right+")";
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string big = parenthesize(root);
        string small = parenthesize(subRoot);
        return big.find(small)!=string::npos;
    }
};
/*
This is the LINEAR time approach, with parenthesize in 
O(N) time, and the rest done in O(N+M) time, due to KMP.
Implement pattern matching in O(N+M) time using the KMP algorithm

SOLUTION:
1) First in our main function, we need to create two 
strings, big and small.  We'll use the parenthesize 
function to do that - see below!
2) Then, use that KMP algorithm, like so:
return big.find(small)!=string::npos;
VOILA!
PARENTHESIZE FUNCTION:
1) We're returning a string, where we want to represent 
our value and the left and right nodes, including ANY 
null nodes.  The return is represented within parentheses, 
so that: result = "(" + CURRENT VALUE + left + right + ")"
2) First of all, we return "()" if our current root is nullptr
3) We represent the left side of the subtree using 
string left = parenthesize(root->left)
4) We represent the right side of the subtree using 
string right = parenthesize(root->right)
5) Note that the + is O(1) amortized time in C++, 
so the concatenation is inexpensive
6) However, the CURRENT VALUE needs to be converted into a 
string (using toStr)

UTILITY FUNCTION (CONVERTING INTEGER TO STRING):
1) This function takes in an integer, n, returning it as a string
2) We use the ostringstream, and simply read in the n into it
3) We return the oss.str() output!  Simple!
*/
