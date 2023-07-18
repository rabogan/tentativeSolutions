class Solution {
    private String toStr(int n) {
        return String.valueOf(n);
    }
    
    private String parenthesize_canonical(TreeNode root) {
        if (root == null) {
            return "()";
        }
        
        String left = parenthesize_canonical(root.left);
        String right = parenthesize_canonical(root.right);
        
        if (left.compareTo(right) > 0) {
            String temp = left;
            left = right;
            right = temp;
        }
        
        return "(" + toStr(root.val) + left + right + ")";
    }
    
    public boolean flipEquiv(TreeNode root1, TreeNode root2) {
        return parenthesize_canonical(root1).equals(parenthesize_canonical(root2));
    }
}
