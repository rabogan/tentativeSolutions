/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int maxSum = Integer.MIN_VALUE;

    public int inorder(TreeNode root) {
        if (root == null)
            return 0;

        int left = inorder(root.left);
        int right = inorder(root.right);

        maxSum = Math.max(root.val, maxSum);
        maxSum = Math.max(maxSum, root.val + left + right);
        maxSum = Math.max(maxSum, root.val + Math.max(left, right));

        return Math.max(root.val, root.val + Math.max(right, left));
    }

    public int maxPathSum(TreeNode root) {
        inorder(root);
        return maxSum;
    }
}
