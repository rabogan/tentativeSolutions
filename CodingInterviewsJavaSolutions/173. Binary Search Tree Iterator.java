class BSTIterator {
    Stack<TreeNode> stk;

    public BSTIterator(TreeNode root) {
        stk = new Stack<>();
        addLeftChain(root);
    }
    
    private void addLeftChain(TreeNode root) {
        while (root != null) {
            stk.push(root);
            root = root.left;
        }
    }
    
    public int next() {
        TreeNode t = stk.pop();
        if (t.right != null) {
            addLeftChain(t.right);
        }
        return t.val;
    }
    
    public boolean hasNext() {
        return !stk.isEmpty();
    }
}
