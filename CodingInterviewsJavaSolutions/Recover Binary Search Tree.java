class Solution {
    TreeNode mn;
    TreeNode mx;
    TreeNode predecessor;

    public void select(TreeNode cur, TreeNode pred) {
        if (mx == null) {
            mn = cur;
            mx = pred;
        } else {
            mn = cur;
        }
    }

    public void traverse(TreeNode node) {
        if (node == null)
            return;

        traverse(node.left);
        if (predecessor != null && node.val < predecessor.val)
            select(node, predecessor);
        predecessor = node;
        traverse(node.right);
    }

    public void recoverTree(TreeNode root) {
        traverse(root);
        int temp = mn.val;
        mn.val = mx.val;
        mx.val = temp;
    }
}
