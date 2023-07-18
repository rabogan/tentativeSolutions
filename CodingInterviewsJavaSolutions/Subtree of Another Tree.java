class Solution {
    private String toStr(int n) {
        return String.valueOf(n);
    }
    
    private String parenthesize(TreeNode root) {
        if (root == null) {
            return "()";
        }
        
        String left = parenthesize(root.left);
        String right = parenthesize(root.right);
        
        return "(" + toStr(root.val) + left + right + ")";
    }
    
    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        String big = parenthesize(root);
        String small = parenthesize(subRoot);
        return big.contains(small);
    }
}
