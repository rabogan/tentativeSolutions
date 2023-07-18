class Solution {
    public Node lowestCommonAncestor(Node p, Node q) {
        Node copy_p = p;
        Node copy_q = q;
        
        while (copy_p != copy_q) {
            copy_p = copy_p.parent;
            if (copy_p == null)
                copy_p = q;
            
            copy_q = copy_q.parent;
            if (copy_q == null)
                copy_q = p;
        }
        
        return copy_p;
    }
}
